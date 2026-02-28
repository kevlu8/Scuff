#pragma once

#include "bitboard.hpp"
#include "eval.hpp"
#include "includes.hpp"

extern bool stop_search;
extern uint64_t nodes[MAX_THREADS];
extern int num_threads;

struct ThreadInfo {
	Board board;
	Move best_move;
	int id;
};

void search(ThreadInfo *tis, uint64_t time, int depth, uint64_t nodes, bool quiet);

void clear_search_vars(ThreadInfo &ti);