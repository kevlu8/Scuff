#include "search.hpp"

bool stop_search = true;
uint64_t nodes[MAX_THREADS] = {};
std::chrono::time_point<std::chrono::steady_clock> start_time, end_time;
int max_depth, max_nodes;
bool output = true;
int num_threads = 1;

Value negamax(ThreadInfo &ti, int depth, Value alpha, Value beta, bool root=false) {
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

	if (depth <= 0) {
		return eval(board);
	}

	Value best = -VALUE_INFINITE;

	pzstd::vector<Move> moves;
	board.legal_moves(moves);

	for (auto &move : moves) {
		board.make_move(move);
		Value score = -negamax(ti, depth - 1, -beta, -alpha);
		board.unmake_move();

		if (stop_search) return 0;

		if (score > best) {
			best = score;
			if (root) ti.best_move = move;
		}
	}

	return best;
}

void iterativedeepening(ThreadInfo &ti) {
	for (int d = 1; d <= max_depth; d++) {
		Value score = negamax(ti, d, -VALUE_INFINITE, VALUE_INFINITE, true);
		if (stop_search) break;
		if (ti.id == 0 && output) {
			uint64_t tot_nodes = 0;
			for (int i = 0; i < num_threads; i++) tot_nodes += nodes[i];

			auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_time).count();
			if (elapsed == 0) elapsed = 1; // avoid division by zero

			std::cout << "info depth " << d << " score cp " << score << " nodes " << tot_nodes;
			std::cout << " nps " << int(tot_nodes / ((double)elapsed / 1000)) << " pv " << ti.best_move.to_string() << std::endl;
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
		tis[i].id = i;
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