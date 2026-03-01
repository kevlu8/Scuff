#include "history.hpp"

void History::update_history(Board &board, Move move, int bonus) {
	int cbonus = std::clamp(bonus, -MAX_HISTORY, MAX_HISTORY);
	history[board.side][move.src()][move.dst()] += cbonus - history[board.side][move.src()][move.dst()] * abs(cbonus) / MAX_HISTORY;
}
