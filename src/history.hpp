#pragma once

#include "includes.hpp"
#include "bitboard.hpp"

#define MAX_HISTORY 16384
#define CORRHIST_SZ 16384

struct History {
	int history[2][64][64]; // [side][from][to]

	int corrhist_ps[2][CORRHIST_SZ]; // [side][index]

	void update_history(Board &board, Move move, int bonus);
	
	void update_corrhist(Board &board, int bonus);
	int get_correction(Board &board);
};
