#include "ttable.hpp"

void TTable::store(uint64_t key, Move move, Value score, uint8_t depth, TTFlags flags) {
	size_t index = key % size;
	table[index] = {key, move, score, depth, (uint8_t)flags};
}

std::optional<TTable::TTEntry> TTable::probe(uint64_t key) {
	size_t index = key % size;
	if (table[index].key == key) {
		return table[index];
	}
	return std::nullopt;
}

TTable ttable(16);
