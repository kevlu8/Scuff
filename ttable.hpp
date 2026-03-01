#pragma once

#include "includes.hpp"
#include "move.hpp"

enum TTFlags : uint8_t {
	EXACT,
	LOWERBOUND,
	UPPERBOUND
};

struct TTable {
	struct TTEntry {
		uint64_t key;
		Move move;
		Value score;
		uint8_t depth;
		uint8_t flags; // 0 = exact, 1 = lower bound, 2 = upper bound	
	};

	TTEntry *table;
	size_t size;

	TTable(size_t mb_size) {
		size = (mb_size * 1024 * 1024) / sizeof(TTEntry);
		table = new TTEntry[size];
	}

	~TTable() {
		delete[] table;
	}

	void store(uint64_t key, Move move, Value score, uint8_t depth, TTFlags flags);

	std::optional<TTEntry> probe(uint64_t key);

	void resize(size_t mb_size) {
		size = (mb_size * 1024 * 1024) / sizeof(TTEntry);
		delete[] table;
		table = new TTEntry[size];
	}
};

extern TTable ttable;
