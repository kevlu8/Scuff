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
				int capthist = history.get_capthist(board, move);
				bool good = board.see(move, -capthist / 50);
				score = MVV[board.mailbox[move.dst()] & 7] + capthist;
				if (good) good_noisies.push_back({move, score});
				else bad_noisies.push_back({move, score});
			} else {
				score = history.get_history(board, move);
				quiets.push_back({move, score});
			}
		}
		stage = MP_EMIT_GOODNOISY;
	}

	if (stage == MP_EMIT_GOODNOISY) {
		// partial insertion sort
		if (index >= good_noisies.size()) {
			stage = MP_EMIT_QUIET;
			index = 0;
		} else {
			size_t best = index;
			for (size_t i = index + 1; i < good_noisies.size(); i++) {
				if (good_noisies[i].second > good_noisies[best].second) {
					best = i;
				}
			}
			std::swap(good_noisies[index], good_noisies[best]);
			index++;
			return good_noisies[index - 1].first;
		}
	}

	if (stage == MP_EMIT_QUIET) {
		// partial insertion sort
		if (index >= quiets.size()) {
			stage = MP_EMIT_BADNOISY;
			index = 0;
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

	if (stage == MP_EMIT_BADNOISY) {
		// we don't need to sort this one
		if (index >= bad_noisies.size()) {
			stage = MP_DONE;
		} else {
			return bad_noisies[index++].first;
		}
	}

	return NullMove;
}
