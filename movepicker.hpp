#pragma once

#include "bitboard.hpp"
#include "history.hpp"

enum MP_STAGE {
	MP_EMIT_TT,
	MP_MOVEGEN,
	MP_EMIT_NOISY,
	MP_EMIT_QUIET,
	MP_DONE
};

struct MovePicker {
	Board &board;
	MP_STAGE stage;
	Move tt_move;
	pzstd::vector<std::pair<Move, int>> noisies, quiets;
	size_t index;
	History &history;

	MovePicker(Board &board, Move tt_move, History &hist);
	Move next_move();
};