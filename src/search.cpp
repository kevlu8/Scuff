#include "search.hpp"

bool stop_search = true;
uint64_t nodes[MAX_THREADS] = {};
std::chrono::time_point<std::chrono::steady_clock> start_time, end_time;
int max_depth, max_nodes;
bool output = true;
int num_threads = 1;

Value quiesce(ThreadInfo &ti, int ply, Value alpha, Value beta) {
	nodes[ti.id]++;

	if (nodes[ti.id] >= max_nodes) {
		stop_search = true;
		return 0;
	}

	if ((nodes[ti.id] & 4095) == 0) {
		if (std::chrono::steady_clock::now() >= end_time) {
			stop_search = true;
			return 0;
		}
	}

	Board &board = ti.board;

	Value stand_pat = eval(board);
	if (stand_pat >= beta) return stand_pat;
	if (stand_pat > alpha) alpha = stand_pat;

	pzstd::vector<Move> moves;
	board.captures(moves);
	
	pzstd::vector<std::pair<Move, int>> scored_moves;
	for (const auto &move : moves) {
		int score = 0;
		if (!board.see(move, 0)) continue;

		if (board.is_capture(move)) {
			score = 1000000 + MVV[board.mailbox[move.dst()] & 7] - PieceValue[board.mailbox[move.src()] & 7];
		}
		scored_moves.push_back({move, score});
	}
	std::stable_sort(scored_moves.begin(), scored_moves.end(), [](const auto &a, const auto &b) {
		return a.second > b.second;
	});

	for (const auto &[move, val] : scored_moves) {
		board.make_move(move);
		Value score = -quiesce(ti, ply + 1, -beta, -alpha);
		board.unmake_move();

		if (stop_search) return 0;

		if (score > stand_pat) {
			stand_pat = score;
		}

		if (score > alpha) {
			alpha = score;
		}

		if (score >= beta) {
			return score;
		}
	}

	return stand_pat;
}

template <bool pv>
Value negamax(ThreadInfo &ti, int depth, int ply, Value alpha, Value beta) {
	nodes[ti.id]++;

	if (nodes[ti.id] >= max_nodes) {
		stop_search = true;
		return 0;
	}

	if ((nodes[ti.id] & 4095) == 0) {
		if (std::chrono::steady_clock::now() >= end_time) {
			stop_search = true;
			return 0;
		}
	}

	Board &board = ti.board;
	bool excluded = ti.ss[ply].excluded != NullMove;

	bool in_check = false, opp_in_check = false;
	if (board.control(__tzcnt_u64(board.piece_boards[OCC(board.side)] & board.piece_boards[KING]), !board.side)) {
		in_check = true;
	}

	if (board.control(__tzcnt_u64(board.piece_boards[OPPOCC(board.side)] & board.piece_boards[KING]), board.side)) {
		return VALUE_INFINITE;
	}

	if (ply > 0 && (board.threefold(ply) || board.halfmove >= 100 || board.insufficient_material())) {
		return 0;
	}

	if (depth <= 0) {
		return quiesce(ti, ply, alpha, beta);
	}

	auto tt_entry = ttable.probe(board.zobrist);
	if (!pv && tt_entry && tt_entry->depth >= depth) {
		if (tt_entry->flags == TTFlags::EXACT) {
			return tt_entry->score;
		} else if (tt_entry->flags == TTFlags::LOWERBOUND) {
			if (tt_entry->score >= beta) return tt_entry->score;
		} else if (tt_entry->flags == TTFlags::UPPERBOUND) {
			if (tt_entry->score <= alpha) return tt_entry->score;
		}
	}

	Value cur_eval = -VALUE_INFINITE;
	if (!in_check) {
		cur_eval = eval(board);
	}

	if (!pv && !in_check && depth <= 10 && !excluded) {
		/**
		 * Reverse futility pruning
		 */
		int margin = beta + 150 * depth;
		if (cur_eval >= margin)
			return cur_eval;
	}

	if (!pv && !in_check && depth >= 2 && !excluded) {
		/**
		 * Null move pruning
		 */
		int r = 4;
		board.make_move(NullMove);
		Value score = -negamax<false>(ti, depth - r, ply + 1, -beta, -beta + 1);
		board.unmake_move();

		if (score >= beta) {
			return score;
		}
	}

	Value best = -VALUE_INFINITE;
	Move best_move = NullMove;

	MovePicker mp(board, tt_entry ? tt_entry->move : NullMove, ti.thread_hist);

	TTFlags flag = TTFlags::UPPERBOUND; // assume upperbound until we can prove otherwise
	
	int movecount = 1;

	pzstd::vector<Move> quiets;

	Move move = NullMove;

	while ((move = mp.next_move()) != NullMove) {
		if (move == ti.ss[ply].excluded) continue;

		if (best > -VALUE_MATE_MAX_PLY && ply != 0) {
			if (movecount >= 5 + 2 * depth * depth)
				break;
		}

		int extension = 0;

		if (!excluded && depth >= 7 && tt_entry && tt_entry->move == move && tt_entry->depth >= depth - 3 && tt_entry->flags != UPPERBOUND) {
			// Singular extensions
			ti.ss[ply].excluded = move;
			Value singular_beta = tt_entry->score - 3 * depth;
			Value s_score = negamax<false>(ti, (depth - 1) / 2, ply + 1, singular_beta - 1, singular_beta);
			ti.ss[ply].excluded = NullMove;
			if (s_score < singular_beta) {
				extension++;
			}
		}

		int newdepth = depth - 1 + extension;

		board.make_move(move);

		Value score = -VALUE_INFINITE;

		if (depth >= 3 && movecount >= 4) {
			int r = 0.77 + log(movecount) * log(depth) / 2.36;

			int search_depth = newdepth - r;
			score = -negamax<false>(ti, search_depth, ply + 1, -alpha - 1, -alpha);
			if (score > alpha && search_depth < newdepth) {
				score = -negamax<false>(ti, newdepth, ply + 1, -alpha - 1, -alpha);
			}
		} else if (!pv || movecount > 1) {
			score = -negamax<false>(ti, newdepth, ply + 1, -alpha - 1, -alpha);
		}
		if (pv && (movecount == 1 || score > alpha)) {
			score = -negamax<true>(ti, newdepth, ply + 1, -beta, -alpha);
		}

		board.unmake_move();

		if (stop_search) return 0;

		if (score > best) {
			best = score;
			if (ply == 0) ti.best_move = move;
		}

		if (score > alpha) {
			alpha = score;
			best_move = move;
			flag = TTFlags::EXACT;
		}

		if (score >= beta) {
			flag = TTFlags::LOWERBOUND;
			int bonus = depth * depth;
			ti.thread_hist.update_history(board, move, bonus);
			for (auto &quiet : quiets) {
				ti.thread_hist.update_history(board, quiet, -bonus);
			}
			break;
		}

		quiets.push_back(move);
		
		movecount++;
	}

	if (best == -VALUE_INFINITE) {
		if (in_check) return -VALUE_MATE + ply;
		else return 0;
	}

	Move tt_move = best_move != NullMove ? best_move : (tt_entry ? tt_entry->move : NullMove);
	ttable.store(board.zobrist, tt_move, best, depth, flag);

	return best;
}

void iterativedeepening(ThreadInfo &ti) {
	Value score = -VALUE_INFINITE;
	for (int d = 1; d <= max_depth; d++) {
		Value alpha = -VALUE_INFINITE, beta = VALUE_INFINITE;
		if (d >= 4) {
			alpha = score - 50;
			beta = score + 50;
		}

		score = negamax<true>(ti, d, 0, alpha, beta);

		if (score <= alpha || score >= beta) {
			if (stop_search) break;
			alpha = -VALUE_INFINITE, beta = VALUE_INFINITE;
			score = negamax<true>(ti, d, 0, alpha, beta);
		}

		if (stop_search) break;
		if (ti.id == 0 && output) {
			uint64_t tot_nodes = 0;
			for (int i = 0; i < num_threads; i++) tot_nodes += nodes[i];

			auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_time).count();
			if (elapsed == 0) elapsed = 1; // avoid division by zero

			std::cout << "info depth " << d << " score cp " << score << " nodes " << tot_nodes;
			std::cout << " nps " << int(tot_nodes / ((double)elapsed / 1000)) << " pv " << ti.best_move.to_string() << std::endl;
		}

		if (ti.id == 0) {
			auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_time).count();
			auto tot_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
			if (elapsed >= tot_time * 0.6) {
				stop_search = true;
				break;
			}
		}
	}
	stop_search = true; // if it somehow didn't get set before
}

void search(ThreadInfo *tis, uint64_t time, int depth, uint64_t nodes, bool quiet) {
	stop_search = false;
	start_time = std::chrono::steady_clock::now();
	end_time = start_time + std::chrono::milliseconds(time);
	max_depth = depth;
	max_nodes = nodes;
	output = !quiet;

	std::vector<std::thread> threads;

	for (int i = 0; i < num_threads; i++) ::nodes[i] = 0;

	for (int i = 0; i < num_threads; i++) {
		threads.emplace_back(iterativedeepening, std::ref(tis[i]));
	}

	for (auto &thread : threads) {
		thread.join();
	}

	std::cout << "bestmove " << tis[0].best_move.to_string() << std::endl;
}

void clear_search_vars(ThreadInfo &ti) {
	ti.best_move = NullMove;
	ti.thread_hist = History();
}