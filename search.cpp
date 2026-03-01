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

	bool in_check = false, opp_in_check = false;
	if (board.control(__tzcnt_u64(board.piece_boards[OCC(board.side)] & board.piece_boards[KING]), !board.side)) {
		in_check = true;
	}

	if (board.control(__tzcnt_u64(board.piece_boards[OPPOCC(board.side)] & board.piece_boards[KING]), board.side)) {
		return VALUE_INFINITE;
	}

	if (board.threefold(ply) || board.halfmove >= 100 || board.insufficient_material()) {
		return 0;
	}

	if (depth <= 0) {
		return quiesce(ti, ply, alpha, beta);
	}

	auto tt_entry = ttable.probe(board.zobrist);

	Value best = -VALUE_INFINITE;
	Move best_move = NullMove;

	pzstd::vector<Move> moves;
	board.legal_moves(moves);
	
	pzstd::vector<std::pair<Move, int>> scored_moves;
	for (const auto &move : moves) {
		int score = 0;
		if (tt_entry && tt_entry->move == move) {
			score = 10000000; // ensure best move from ttable is searched first
		} else if (board.is_capture(move)) {
			score = 100000 + MVV[board.mailbox[move.dst()] & 7] - PieceValue[board.mailbox[move.src()] & 7];
		} else {
			score = ti.thread_hist.history[board.side][move.src()][move.dst()];
		}
		scored_moves.push_back({move, score});
	}
	std::stable_sort(scored_moves.begin(), scored_moves.end(), [](const auto &a, const auto &b) {
		return a.second > b.second;
	});

	TTFlags flag = TTFlags::UPPERBOUND; // assume upperbound until we can prove otherwise

	for (auto &[move, val] : scored_moves) {
		board.make_move(move);
		Value score = -negamax(ti, depth - 1, ply + 1, -beta, -alpha);
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
			ti.thread_hist.update_history(board, move, depth * depth);
			break;
		}
	}

	if (best == -VALUE_INFINITE) {
		if (in_check) return -VALUE_MATE + ply;
		else return 0;
	}

	ttable.store(board.zobrist, best_move, best, depth, flag);

	return best;
}

void iterativedeepening(ThreadInfo &ti) {
	for (int d = 1; d <= max_depth; d++) {
		Value score = negamax(ti, d, 0, -VALUE_INFINITE, VALUE_INFINITE);
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
}