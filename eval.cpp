#include "eval.hpp"

EvalScore MATERIAL_VALUES[] = {
	ES(154, 264),
	ES(596, 608),
	ES(686, 655),
	ES(672, 1135),
	ES(879, 1939),
	ES(10000, 10000),
};

EvalScore PAWN_PSQT[] = {
	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 
	ES(0, 0), 	ES(1, 0), 	ES(0, 0), 	ES(-10, -10), 	ES(-10, -10), 	ES(21, 0), 	ES(95, 0), 	ES(0, 0), 
	ES(-22, 20), 	ES(24, 29), 	ES(-4, 10), 	ES(20, 20), 	ES(20, 20), 	ES(51, 18), 	ES(82, 10), 	ES(3, 10), 
	ES(-35, 4), 	ES(-1, 7), 	ES(-17, 16), 	ES(-21, 40), 	ES(4, 39), 	ES(-10, 13), 	ES(64, 5), 	ES(17, -15), 
	ES(-24, 20), 	ES(7, 19), 	ES(-11, 29), 	ES(39, 40), 	ES(23, 39), 	ES(10, 29), 	ES(25, 19), 	ES(17, 18), 
	ES(40, 40), 	ES(40, 40), 	ES(50, 50), 	ES(34, 50), 	ES(86, 50), 	ES(50, 50), 	ES(40, 40), 	ES(40, 40), 
	ES(80, 80), 	ES(80, 80), 	ES(80, 80), 	ES(80, 80), 	ES(80, 80), 	ES(80, 80), 	ES(80, 80), 	ES(80, 80), 
	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 
};

EvalScore KNIGHT_PSQT[] = {
	ES(-50, -30), 	ES(-35, -20), 	ES(-20, -20), 	ES(-20, -20), 	ES(-20, -20), 	ES(-20, -20), 	ES(-30, -20), 	ES(-50, -30), 
	ES(-30, -20), 	ES(-20, 0), 	ES(10, 15), 	ES(-15, 15), 	ES(13, 15), 	ES(15, 15), 	ES(15, 15), 	ES(-30, -20), 
	ES(-20, 5), 	ES(15, 15), 	ES(21, 15), 	ES(20, 20), 	ES(20, 20), 	ES(14, 15), 	ES(15, 15), 	ES(-20, 5), 
	ES(-20, 0), 	ES(15, 20), 	ES(20, 20), 	ES(20, 20), 	ES(20, 20), 	ES(15, 15), 	ES(0, 10), 	ES(-20, 5), 
	ES(-20, 0), 	ES(15, 20), 	ES(20, 20), 	ES(20, 20), 	ES(20, 20), 	ES(15, 15), 	ES(0, 10), 	ES(-20, 5), 
	ES(-20, 5), 	ES(10, 15), 	ES(15, 15), 	ES(15, 15), 	ES(15, 15), 	ES(10, 15), 	ES(5, 5), 	ES(-20, 5), 
	ES(-30, -20), 	ES(0, 5), 	ES(5, 5), 	ES(0, 0), 	ES(0, 0), 	ES(5, 5), 	ES(-20, 0), 	ES(-30, -20), 
	ES(-50, -30), 	ES(-30, -20), 	ES(-20, -20), 	ES(-20, -20), 	ES(-20, -20), 	ES(-20, -20), 	ES(-30, -20), 	ES(-50, -30), 
};

EvalScore BISHOP_PSQT[] = {
	ES(-20, -20), 	ES(-10, -10), 	ES(-73, -10), 	ES(-10, -10), 	ES(-10, -10), 	ES(-20, -10), 	ES(-10, -10), 	ES(-20, -20), 
	ES(-10, -10), 	ES(-9, 0), 	ES(0, 0), 	ES(-15, 0), 	ES(-14, 0), 	ES(0, 0), 	ES(42, 0), 	ES(-10, -10), 
	ES(-10, -10), 	ES(0, 0), 	ES(10, 10), 	ES(22, 10), 	ES(19, 10), 	ES(10, 10), 	ES(0, 0), 	ES(-10, -10), 
	ES(-10, -10), 	ES(0, 0), 	ES(10, 10), 	ES(10, 10), 	ES(10, 10), 	ES(10, 10), 	ES(0, 0), 	ES(-10, -10), 
	ES(-10, -10), 	ES(0, 0), 	ES(10, 10), 	ES(10, 10), 	ES(10, 10), 	ES(10, 10), 	ES(0, 0), 	ES(-10, -10), 
	ES(-10, -10), 	ES(10, 10), 	ES(10, 10), 	ES(10, 10), 	ES(10, 10), 	ES(10, 10), 	ES(10, 10), 	ES(-10, -10), 
	ES(-10, -10), 	ES(20, 20), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(20, 20), 	ES(-10, -10), 
	ES(-20, -20), 	ES(-10, -10), 	ES(-10, -10), 	ES(-10, -10), 	ES(-10, -10), 	ES(-10, -10), 	ES(-10, -10), 	ES(-20, -20), 
};

EvalScore ROOK_PSQT[] = {
	ES(-34, 0), 	ES(-2, 0), 	ES(13, 5), 	ES(59, 10), 	ES(43, 10), 	ES(26, 5), 	ES(0, 0), 	ES(-38, 0), 
	ES(-5, -5), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(-5, -5), 
	ES(-5, -5), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(-5, -5), 
	ES(-5, -5), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(-5, -5), 
	ES(-5, -5), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(-5, -5), 
	ES(-5, -5), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(-5, -5), 
	ES(5, 5), 	ES(10, 10), 	ES(10, 10), 	ES(10, 10), 	ES(10, 10), 	ES(10, 10), 	ES(10, 10), 	ES(5, 5), 
	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 
};

EvalScore QUEEN_PSQT[] = {
	ES(-20, -20), 	ES(-10, -10), 	ES(-10, -10), 	ES(5, -5), 	ES(-5, -5), 	ES(-10, -10), 	ES(-10, -10), 	ES(-20, -20), 
	ES(-10, -10), 	ES(0, 0), 	ES(12, 0), 	ES(2, 0), 	ES(7, 0), 	ES(0, 0), 	ES(0, 0), 	ES(-10, -10), 
	ES(-10, -10), 	ES(0, 0), 	ES(5, 5), 	ES(5, 5), 	ES(5, 5), 	ES(5, 5), 	ES(0, 0), 	ES(-10, -10), 
	ES(-5, -5), 	ES(0, 0), 	ES(5, 5), 	ES(5, 5), 	ES(5, 5), 	ES(5, 5), 	ES(0, 0), 	ES(-5, -5), 
	ES(0, 0), 	ES(0, 0), 	ES(5, 5), 	ES(5, 5), 	ES(5, 5), 	ES(5, 5), 	ES(0, 0), 	ES(-10, -10), 
	ES(-10, -10), 	ES(5, 5), 	ES(5, 5), 	ES(5, 5), 	ES(5, 5), 	ES(5, 5), 	ES(0, 0), 	ES(-10, -10), 
	ES(-10, -10), 	ES(0, 0), 	ES(5, 5), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(-10, -10), 
	ES(-20, -20), 	ES(-10, -10), 	ES(-10, -10), 	ES(-5, -5), 	ES(-5, -5), 	ES(-10, -10), 	ES(-10, -10), 	ES(-20, -20), 
};

EvalScore KING_PSQT[] = {
	ES(20, 20), 	ES(30, 30), 	ES(12, 10), 	ES(0, 0), 	ES(4, 0), 	ES(10, 10), 	ES(96, -6), 	ES(22, 20), 
	ES(20, 20), 	ES(20, 20), 	ES(20, 20), 	ES(20, 20), 	ES(20, 20), 	ES(20, 20), 	ES(20, 20), 	ES(20, 20), 
	ES(-10, -10), 	ES(20, 20), 	ES(20, 20), 	ES(0, 0), 	ES(0, 0), 	ES(20, 20), 	ES(20, 20), 	ES(-10, -10), 
	ES(-20, -20), 	ES(-30, -30), 	ES(-30, -30), 	ES(-40, -40), 	ES(-40, -40), 	ES(-30, -30), 	ES(-30, -30), 	ES(-20, -20), 
	ES(-30, -30), 	ES(-40, -40), 	ES(-40, -40), 	ES(-50, -50), 	ES(-50, -50), 	ES(-40, -40), 	ES(-40, -40), 	ES(-30, -30), 
	ES(-30, -30), 	ES(-40, -40), 	ES(-40, -40), 	ES(-50, -50), 	ES(-50, -50), 	ES(-40, -40), 	ES(-40, -40), 	ES(-30, -30), 
	ES(-30, -30), 	ES(-40, -40), 	ES(-40, -40), 	ES(-50, -50), 	ES(-50, -50), 	ES(-40, -40), 	ES(-40, -40), 	ES(-30, -30), 
	ES(-30, -30), 	ES(-40, -40), 	ES(-40, -40), 	ES(-50, -50), 	ES(-50, -50), 	ES(-40, -40), 	ES(-40, -40), 	ES(-30, -30), 
};

Value eval(const Board &board) {
	EvalScore material = 0;

	material += MATERIAL_VALUES[PAWN] * (_mm_popcnt_u64(board.piece_boards[OCC(WHITE)] & board.piece_boards[PAWN]) - _mm_popcnt_u64(board.piece_boards[OCC(BLACK)] & board.piece_boards[PAWN]));
	material += MATERIAL_VALUES[KNIGHT] * (_mm_popcnt_u64(board.piece_boards[OCC(WHITE)] & board.piece_boards[KNIGHT]) - _mm_popcnt_u64(board.piece_boards[OCC(BLACK)] & board.piece_boards[KNIGHT]));
	material += MATERIAL_VALUES[BISHOP] * (_mm_popcnt_u64(board.piece_boards[OCC(WHITE)] & board.piece_boards[BISHOP]) - _mm_popcnt_u64(board.piece_boards[OCC(BLACK)] & board.piece_boards[BISHOP]));
	material += MATERIAL_VALUES[ROOK] * (_mm_popcnt_u64(board.piece_boards[OCC(WHITE)] & board.piece_boards[ROOK]) - _mm_popcnt_u64(board.piece_boards[OCC(BLACK)] & board.piece_boards[ROOK]));
	material += MATERIAL_VALUES[QUEEN] * (_mm_popcnt_u64(board.piece_boards[OCC(WHITE)] & board.piece_boards[QUEEN]) - _mm_popcnt_u64(board.piece_boards[OCC(BLACK)] & board.piece_boards[QUEEN]));

	EvalScore psqt = 0;
	for (int i = 0; i < 64; i++) {
		Piece p = board.mailbox[i];
		PieceType pt = PieceType(p & 7);
		int side = p >> 3;
		int idx = side == WHITE ? i : 56 ^ i; // mirror for black pieces
		if (p == NO_PIECE) continue;
		if (pt == PAWN)
			psqt += PAWN_PSQT[idx] * (side == WHITE ? 1 : -1);
		else if (pt == KNIGHT)
			psqt += KNIGHT_PSQT[idx] * (side == WHITE ? 1 : -1);
		else if (pt == BISHOP)
			psqt += BISHOP_PSQT[idx] * (side == WHITE ? 1 : -1);
		else if (pt == ROOK)
			psqt += ROOK_PSQT[idx] * (side == WHITE ? 1 : -1);
		else if (pt == QUEEN)
			psqt += QUEEN_PSQT[idx] * (side == WHITE ? 1 : -1);
		else if (pt == KING)
			psqt += KING_PSQT[idx] * (side == WHITE ? 1 : -1);
	}

	EvalScore final_eval = material + psqt;
	if (board.side == BLACK) final_eval *= -1;

	int phase = _mm_popcnt_u64(board.piece_boards[KNIGHT])
			+ _mm_popcnt_u64(board.piece_boards[BISHOP])
			+ 2 * _mm_popcnt_u64(board.piece_boards[ROOK])
			+ 4 * _mm_popcnt_u64(board.piece_boards[QUEEN]);
	phase = std::min(phase, 24);

	return final_eval(phase);
}

std::vector<std::pair<double, double>> calc_grad(const Board &board) {
	std::vector<std::pair<double, double>> grads;
	
	int phase = _mm_popcnt_u64(board.piece_boards[KNIGHT])
			+ _mm_popcnt_u64(board.piece_boards[BISHOP])
			+ 2 * _mm_popcnt_u64(board.piece_boards[ROOK])
			+ 4 * _mm_popcnt_u64(board.piece_boards[QUEEN]);
	phase = std::min(phase, 24);

	double alpha = phase / 24.0, beta = 1 - alpha;
	for (int i = 0; i < 6; i++) {
		int diff = _mm_popcnt_u64(board.piece_boards[OCC(WHITE)] & board.piece_boards[i]) - _mm_popcnt_u64(board.piece_boards[OCC(BLACK)] & board.piece_boards[i]);
		grads.push_back({diff * alpha, diff * beta});
	}

	std::vector<std::pair<double, double>> pawn_grads(64), knight_grads(64), bishop_grads(64), rook_grads(64), queen_grads(64), king_grads(64);

	for (int i = 0; i < 64; i++) {
		Piece p = board.mailbox[i];
		PieceType pt = PieceType(p & 7);
		int side = p >> 3;
		int idx = side == WHITE ? i : 56 ^ i; // mirror for black pieces
		if (p == NO_PIECE) continue;

		double cur_alpha = alpha * (side == WHITE ? 1 : -1);
		double cur_beta = beta * (side == WHITE ? 1 : -1);

		if (pt != PAWN) pawn_grads[idx].first += 0, pawn_grads[idx].second += 0;
		else pawn_grads[idx].first += cur_alpha, pawn_grads[idx].second += cur_beta;

		if (pt != KNIGHT) knight_grads[idx].first += 0, knight_grads[idx].second += 0;
		else knight_grads[idx].first += cur_alpha, knight_grads[idx].second += cur_beta;

		if (pt != BISHOP) bishop_grads[idx].first += 0, bishop_grads[idx].second += 0;
		else bishop_grads[idx].first += cur_alpha, bishop_grads[idx].second += cur_beta;

		if (pt != ROOK) rook_grads[idx].first += 0, rook_grads[idx].second += 0;
		else rook_grads[idx].first += cur_alpha, rook_grads[idx].second += cur_beta;

		if (pt != QUEEN) queen_grads[idx].first += 0, queen_grads[idx].second += 0;
		else queen_grads[idx].first += cur_alpha, queen_grads[idx].second += cur_beta;

		if (pt != KING) king_grads[idx].first += 0, king_grads[idx].second += 0;
		else king_grads[idx].first += cur_alpha, king_grads[idx].second += cur_beta;
	}

	grads.insert(grads.end(), pawn_grads.begin(), pawn_grads.end());
	grads.insert(grads.end(), knight_grads.begin(), knight_grads.end());
	grads.insert(grads.end(), bishop_grads.begin(), bishop_grads.end());
	grads.insert(grads.end(), rook_grads.begin(), rook_grads.end());
	grads.insert(grads.end(), queen_grads.begin(), queen_grads.end());
	grads.insert(grads.end(), king_grads.begin(), king_grads.end());

	if (board.side == BLACK) {
		for (auto &g : grads) {
			g.first *= -1;
			g.second *= -1;
		}
	}

	return grads;
}