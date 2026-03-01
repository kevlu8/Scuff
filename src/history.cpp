#include "history.hpp"

void History::update_history(Board &board, Move move, int bonus) {
	int cbonus = std::clamp(bonus, -MAX_HISTORY, MAX_HISTORY);
	history[board.side][move.src()][move.dst()] += cbonus - history[board.side][move.src()][move.dst()] * abs(cbonus) / MAX_HISTORY;
}

void History::update_capthist(Board &board, Move move, int bonus) {
	int cbonus = std::clamp(bonus, -MAX_HISTORY, MAX_HISTORY);
	capthist[board.side][board.mailbox[move.src()] & 7][move.dst()] += cbonus - capthist[board.side][board.mailbox[move.src()] & 7][move.dst()] * abs(cbonus) / MAX_HISTORY;
}

int History::get_history(Board &board, Move move) {
	return history[board.side][move.src()][move.dst()];
}

int History::get_capthist(Board &board, Move move) {
	return capthist[board.side][board.mailbox[move.src()] & 7][move.dst()];
}

void History::update_corrhist(Board &board, int bonus) {
	auto update_entry = [=](int &entry) {
		int update = std::clamp(bonus, -MAX_CORRHIST / 4, MAX_CORRHIST / 4);
		entry += update - entry * abs(update) / MAX_CORRHIST;
	};

	update_entry(corrhist_ps[board.side][board.pawn_hash() % CORRHIST_SZ]);
}

int History::get_correction(Board &board) {
	int corr = 0;
	corr += 128 * corrhist_ps[board.side][board.pawn_hash() % CORRHIST_SZ];

	return corr / 2048;
}
