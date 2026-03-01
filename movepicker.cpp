#include "movepicker.hpp"

MovePicker::MovePicker(Board &board, Move tt_move, History &hist) : board(board), stage(MP_EMIT_TT), tt_move(tt_move), index(0), history(hist) {}

Move MovePicker::next_move() {
	if (stage == MP_EMIT_TT) {
		stage = MP_MOVEGEN;
		if (board.is_pseudolegal(tt_move))
			return tt_move;
	}

	if (stage == MP_MOVEGEN) {
		pzstd::vector<Move> mv;
		board.legal_moves(mv);
		for (const auto &move : mv) {
			int score = 0;
			if (board.is_capture(move)) {
				score = MVV[board.mailbox[move.dst()] & 7] - PieceValue[board.mailbox[move.src()] & 7];
				noisies.push_back({move, score});
			} else {
				score = history.history[board.side][move.src()][move.dst()];
				quiets.push_back({move, score});
			}
		}
		stage = MP_EMIT_NOISY;
	}

	if (stage == MP_EMIT_NOISY) {
		// partial insertion sort
		if (index >= noisies.size()) {
			stage = MP_EMIT_QUIET;
			index = 0;
		} else {
			size_t best = index;
			for (size_t i = index + 1; i < noisies.size(); i++) {
				if (noisies[i].second > noisies[best].second) {
					best = i;
				}
			}
			std::swap(noisies[index], noisies[best]);
			index++;
			return noisies[index - 1].first;
		}
	}

	if (stage == MP_EMIT_QUIET) {
		// partial insertion sort
		if (index >= quiets.size()) {
			stage = MP_DONE;
		} else {
			size_t best = index;
			for (size_t i = index + 1; i < quiets.size(); i++) {
				if (quiets[i].second > quiets[best].second) {
					best = i;
				}
			}
			std::swap(quiets[index], quiets[best]);
			index++;
			return quiets[index - 1].first;
		}
	}

	return NullMove;
}
