#pragma once

#include "bitboard.hpp"
#include "history.hpp"

enum MP_STAGE {
	MP_EMIT_TT,
	MP_MOVEGEN,
	MP_EMIT_GOODNOISY,
	MP_EMIT_QUIET,
	MP_EMIT_BADNOISY,
	MP_DONE
};

struct MovePicker {
	Board &board;
	MP_STAGE stage;
	Move tt_move;
	pzstd::vector<std::pair<Move, int>> good_noisies, quiets, bad_noisies;
	size_t index;
	History &history;

	MovePicker(Board &board, Move tt_move, History &hist);
	Move next_move();
};