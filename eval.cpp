#include "eval.hpp"

EvalScore MATERIAL_VALUES[] = {
	ES(228, 443),
	ES(891, 1089),
	ES(988, 1119),
	ES(1211, 1906),
	ES(2480, 3149),
};

EvalScore PAWN_PSQT[] = {
	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 
	ES(-106, 17), 	ES(-17, 19), 	ES(-34, -27), 	ES(-66, -4), 	ES(8, 14), 	ES(53, -26), 	ES(136, -26), 	ES(-26, -54), 
	ES(-107, 3), 	ES(-17, 12), 	ES(-20, -55), 	ES(-16, -12), 	ES(37, -36), 	ES(-1, -40), 	ES(106, -32), 	ES(-3, -64), 
	ES(-105, 20), 	ES(-5, 10), 	ES(-7, -53), 	ES(49, -60), 	ES(47, -68), 	ES(27, -58), 	ES(55, -22), 	ES(-24, -42), 
	ES(-62, 111), 	ES(21, 74), 	ES(30, -2), 	ES(39, -31), 	ES(117, -61), 	ES(94, -51), 	ES(105, 19), 	ES(20, 24), 
	ES(-5, 359), 	ES(45, 386), 	ES(155, 263), 	ES(174, 186), 	ES(185, 153), 	ES(268, 108), 	ES(195, 274), 	ES(41, 266), 
	ES(276, 563), 	ES(355, 537), 	ES(278, 539), 	ES(382, 368), 	ES(321, 351), 	ES(263, 382), 	ES(22, 550), 	ES(-66, 597), 
	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 
};

EvalScore KNIGHT_PSQT[] = {
	ES(-227, 17), 	ES(-45, -32), 	ES(-90, 74), 	ES(-41, 86), 	ES(-19, 92), 	ES(20, 53), 	ES(-30, 2), 	ES(-125, -24), 
	ES(-77, 44), 	ES(-37, 100), 	ES(26, 130), 	ES(58, 141), 	ES(66, 140), 	ES(73, 121), 	ES(36, 69), 	ES(25, 81), 
	ES(-28, 77), 	ES(48, 141), 	ES(92, 173), 	ES(109, 226), 	ES(147, 217), 	ES(110, 163), 	ES(128, 124), 	ES(29, 80), 
	ES(35, 129), 	ES(88, 162), 	ES(137, 242), 	ES(149, 250), 	ES(183, 261), 	ES(154, 220), 	ES(159, 172), 	ES(72, 98), 
	ES(81, 122), 	ES(130, 199), 	ES(220, 241), 	ES(295, 246), 	ES(230, 257), 	ES(314, 231), 	ES(163, 195), 	ES(203, 97), 
	ES(92, 83), 	ES(217, 141), 	ES(278, 202), 	ES(319, 200), 	ES(450, 144), 	ES(459, 133), 	ES(301, 102), 	ES(190, 51), 
	ES(43, 31), 	ES(104, 104), 	ES(198, 136), 	ES(250, 121), 	ES(197, 98), 	ES(422, 51), 	ES(104, 95), 	ES(182, -24), 
	ES(-440, -155), 	ES(-303, 51), 	ES(-86, 103), 	ES(28, 80), 	ES(142, 87), 	ES(-59, 8), 	ES(-208, 72), 	ES(-240, -232), 
};

EvalScore BISHOP_PSQT[] = {
	ES(22, 67), 	ES(99, 127), 	ES(42, 59), 	ES(5, 133), 	ES(26, 129), 	ES(19, 126), 	ES(114, 79), 	ES(64, 25), 
	ES(102, 127), 	ES(106, 131), 	ES(149, 117), 	ES(74, 176), 	ES(94, 180), 	ES(144, 142), 	ES(165, 150), 	ES(113, 57), 
	ES(95, 151), 	ES(115, 183), 	ES(116, 210), 	ES(124, 213), 	ES(133, 222), 	ES(115, 205), 	ES(128, 150), 	ES(140, 118), 
	ES(58, 149), 	ES(102, 211), 	ES(121, 236), 	ES(193, 222), 	ES(183, 224), 	ES(125, 216), 	ES(102, 198), 	ES(90, 118), 
	ES(84, 166), 	ES(138, 225), 	ES(211, 204), 	ES(241, 247), 	ES(234, 219), 	ES(215, 210), 	ES(129, 212), 	ES(85, 164), 
	ES(108, 182), 	ES(187, 153), 	ES(190, 195), 	ES(280, 160), 	ES(230, 181), 	ES(338, 181), 	ES(259, 159), 	ES(211, 153), 
	ES(76, 79), 	ES(164, 152), 	ES(134, 160), 	ES(76, 171), 	ES(178, 135), 	ES(178, 131), 	ES(147, 160), 	ES(112, 71), 
	ES(18, 124), 	ES(-49, 162), 	ES(-12, 154), 	ES(-154, 206), 	ES(-116, 181), 	ES(-54, 146), 	ES(50, 118), 	ES(-83, 115), 
};

EvalScore ROOK_PSQT[] = {
	ES(61, 315), 	ES(59, 344), 	ES(96, 373), 	ES(108, 362), 	ES(127, 342), 	ES(93, 323), 	ES(144, 308), 	ES(59, 283), 
	ES(-16, 324), 	ES(34, 341), 	ES(82, 338), 	ES(75, 354), 	ES(87, 321), 	ES(93, 302), 	ES(158, 272), 	ES(43, 287), 
	ES(2, 348), 	ES(32, 346), 	ES(62, 339), 	ES(57, 353), 	ES(78, 343), 	ES(73, 318), 	ES(196, 249), 	ES(121, 252), 
	ES(17, 358), 	ES(34, 382), 	ES(68, 388), 	ES(109, 377), 	ES(108, 364), 	ES(55, 357), 	ES(144, 315), 	ES(112, 296), 
	ES(93, 387), 	ES(135, 380), 	ES(143, 407), 	ES(175, 398), 	ES(194, 344), 	ES(200, 333), 	ES(227, 313), 	ES(241, 296), 
	ES(145, 377), 	ES(221, 387), 	ES(226, 395), 	ES(246, 394), 	ES(344, 344), 	ES(341, 320), 	ES(477, 288), 	ES(397, 274), 
	ES(223, 379), 	ES(215, 416), 	ES(285, 434), 	ES(360, 403), 	ES(298, 398), 	ES(411, 356), 	ES(362, 338), 	ES(471, 294), 
	ES(288, 378), 	ES(254, 403), 	ES(279, 431), 	ES(299, 416), 	ES(367, 394), 	ES(414, 353), 	ES(356, 364), 	ES(432, 340), 
};

EvalScore QUEEN_PSQT[] = {
	ES(360, 885), 	ES(329, 924), 	ES(357, 937), 	ES(405, 899), 	ES(371, 911), 	ES(325, 910), 	ES(405, 804), 	ES(378, 801), 
	ES(366, 913), 	ES(381, 925), 	ES(422, 916), 	ES(424, 954), 	ES(415, 966), 	ES(448, 872), 	ES(462, 767), 	ES(508, 665), 
	ES(371, 932), 	ES(400, 990), 	ES(380, 1072), 	ES(377, 1067), 	ES(388, 1077), 	ES(421, 1055), 	ES(461, 971), 	ES(438, 928), 
	ES(389, 973), 	ES(375, 1078), 	ES(375, 1114), 	ES(401, 1178), 	ES(397, 1174), 	ES(401, 1146), 	ES(441, 1076), 	ES(449, 1026), 
	ES(374, 988), 	ES(394, 1068), 	ES(402, 1115), 	ES(405, 1206), 	ES(409, 1248), 	ES(457, 1195), 	ES(457, 1145), 	ES(483, 1072), 
	ES(439, 955), 	ES(437, 1021), 	ES(422, 1160), 	ES(476, 1167), 	ES(500, 1219), 	ES(648, 1143), 	ES(648, 1010), 	ES(632, 963), 
	ES(434, 912), 	ES(360, 1067), 	ES(382, 1187), 	ES(356, 1249), 	ES(378, 1310), 	ES(507, 1163), 	ES(437, 1106), 	ES(587, 1015), 
	ES(302, 1048), 	ES(332, 1081), 	ES(457, 1132), 	ES(567, 1083), 	ES(559, 1081), 	ES(617, 1031), 	ES(647, 902), 	ES(450, 1015), 
};

EvalScore KING_PSQT[] = {
	ES(216, -303), 	ES(298, -232), 	ES(200, -169), 	ES(-152, -99), 	ES(78, -189), 	ES(-63, -111), 	ES(230, -203), 	ES(235, -302), 
	ES(224, -185), 	ES(85, -81), 	ES(36, -34), 	ES(-84, -1), 	ES(-90, 14), 	ES(-29, -24), 	ES(139, -87), 	ES(178, -146), 
	ES(-86, -106), 	ES(-27, -17), 	ES(-227, 60), 	ES(-275, 101), 	ES(-250, 96), 	ES(-243, 66), 	ES(-79, -2), 	ES(-142, -45), 
	ES(-234, -68), 	ES(-270, 47), 	ES(-379, 130), 	ES(-474, 179), 	ES(-463, 181), 	ES(-337, 127), 	ES(-351, 87), 	ES(-432, 32), 
	ES(-248, -22), 	ES(-293, 95), 	ES(-347, 161), 	ES(-507, 205), 	ES(-462, 196), 	ES(-328, 178), 	ES(-325, 150), 	ES(-403, 61), 
	ES(-353, 10), 	ES(-2, 79), 	ES(-242, 140), 	ES(-295, 185), 	ES(-166, 181), 	ES(92, 155), 	ES(28, 146), 	ES(-88, 50), 
	ES(-264, -54), 	ES(-147, 58), 	ES(-283, 98), 	ES(39, 44), 	ES(-102, 111), 	ES(-80, 147), 	ES(56, 113), 	ES(0, -2), 
	ES(-53, -336), 	ES(-67, -172), 	ES(28, -137), 	ES(-275, 2), 	ES(-139, -58), 	ES(6, -39), 	ES(114, -52), 	ES(148, -365), 
};

int white_eval(const Board &board) {
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
	// EvalScore final_eval = material;

	int phase = _mm_popcnt_u64(board.piece_boards[KNIGHT])
			+ _mm_popcnt_u64(board.piece_boards[BISHOP])
			+ 2 * _mm_popcnt_u64(board.piece_boards[ROOK])
			+ 4 * _mm_popcnt_u64(board.piece_boards[QUEEN]);
	phase = std::min(phase, 24);

	return final_eval(phase);
}

int eval(const Board &board) {
	int base_eval = white_eval(board);
	return board.side == WHITE ? base_eval : -base_eval;
}

std::vector<std::pair<double, double>> calc_grad(const Board &board) {
	std::vector<std::pair<double, double>> grads;
	
	int phase = _mm_popcnt_u64(board.piece_boards[KNIGHT])
			+ _mm_popcnt_u64(board.piece_boards[BISHOP])
			+ 2 * _mm_popcnt_u64(board.piece_boards[ROOK])
			+ 4 * _mm_popcnt_u64(board.piece_boards[QUEEN]);
	phase = std::min(phase, 24);

	double alpha = phase / 24.0, beta = 1 - alpha;
	for (int i = 0; i < 5; i++) {
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

		if (pt == PAWN) pawn_grads[idx].first += cur_alpha, pawn_grads[idx].second += cur_beta;
		if (pt == KNIGHT) knight_grads[idx].first += cur_alpha, knight_grads[idx].second += cur_beta;
		if (pt == BISHOP) bishop_grads[idx].first += cur_alpha, bishop_grads[idx].second += cur_beta;
		if (pt == ROOK) rook_grads[idx].first += cur_alpha, rook_grads[idx].second += cur_beta;
		if (pt == QUEEN) queen_grads[idx].first += cur_alpha, queen_grads[idx].second += cur_beta;
		if (pt == KING) king_grads[idx].first += cur_alpha, king_grads[idx].second += cur_beta;
	}

	grads.insert(grads.end(), pawn_grads.begin(), pawn_grads.end());
	grads.insert(grads.end(), knight_grads.begin(), knight_grads.end());
	grads.insert(grads.end(), bishop_grads.begin(), bishop_grads.end());
	grads.insert(grads.end(), rook_grads.begin(), rook_grads.end());
	grads.insert(grads.end(), queen_grads.begin(), queen_grads.end());
	grads.insert(grads.end(), king_grads.begin(), king_grads.end());

	return grads;
}