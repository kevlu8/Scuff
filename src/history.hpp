#pragma once

#include "includes.hpp"
#include "bitboard.hpp"

#define MAX_HISTORY 16384
#define CORRHIST_SZ 16384

struct History {
	int history[2][64][64]; // [side][from][to]
	int capthist[2][6][64]; // [side][moving piece][to]

	int corrhist_ps[2][CORRHIST_SZ]; // [side][index]

	void update_history(Board &board, Move move, int bonus);
	void update_capthist(Board &board, Move move, int bonus);

	int get_history(Board &board, Move move);
	int get_capthist(Board &board, Move move);

	void update_corrhist(Board &board, int bonus);
	int get_correction(Board &board);
};
