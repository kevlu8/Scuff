#pragma once

#include "includes.hpp"
#include "bitboard.hpp"

#define MAX_HISTORY 16384

struct History {
	int history[2][64][64]; // [side][from][to]

	void update_history(Board &board, Move move, int bonus);
};
