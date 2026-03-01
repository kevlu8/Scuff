#include "eval.hpp"

EvalScore MATERIAL_VALUES[] = {
	ES(219, 440),
	ES(888, 1103),
	ES(896, 1137),
	ES(1191, 1920),
	ES(2376, 3249),
};

EvalScore PAWN_PSQT[] = {
	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 
	ES(-107, 17), 	ES(-14, 18), 	ES(-35, -28), 	ES(-65, -4), 	ES(4, 12), 	ES(56, -31), 	ES(136, -31), 	ES(-29, -58), 
	ES(-106, 1), 	ES(-21, 10), 	ES(-20, -53), 	ES(-16, -15), 	ES(40, -31), 	ES(-1, -47), 	ES(104, -29), 	ES(2, -60), 
	ES(-102, 23), 	ES(-5, 21), 	ES(-9, -47), 	ES(53, -58), 	ES(53, -61), 	ES(23, -60), 	ES(54, -18), 	ES(-29, -45), 
	ES(-64, 111), 	ES(23, 68), 	ES(34, 0), 	ES(40, -29), 	ES(118, -58), 	ES(83, -51), 	ES(100, 17), 	ES(16, 21), 
	ES(-10, 356), 	ES(33, 384), 	ES(150, 261), 	ES(175, 191), 	ES(182, 160), 	ES(262, 107), 	ES(194, 271), 	ES(40, 267), 
	ES(271, 567), 	ES(348, 540), 	ES(269, 541), 	ES(375, 372), 	ES(314, 357), 	ES(257, 392), 	ES(21, 555), 	ES(-74, 603), 
	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 
};

EvalScore KNIGHT_PSQT[] = {
	ES(-235, 21), 	ES(-41, -30), 	ES(-84, 82), 	ES(-38, 93), 	ES(-21, 90), 	ES(25, 55), 	ES(-26, 2), 	ES(-126, -19), 
	ES(-76, 44), 	ES(-37, 103), 	ES(22, 132), 	ES(66, 145), 	ES(70, 143), 	ES(77, 130), 	ES(24, 66), 	ES(19, 74), 
	ES(-34, 72), 	ES(53, 147), 	ES(99, 176), 	ES(106, 225), 	ES(151, 225), 	ES(112, 160), 	ES(122, 125), 	ES(22, 80), 
	ES(30, 127), 	ES(89, 165), 	ES(141, 245), 	ES(150, 253), 	ES(180, 255), 	ES(157, 223), 	ES(147, 173), 	ES(71, 99), 
	ES(80, 129), 	ES(132, 202), 	ES(214, 242), 	ES(292, 244), 	ES(225, 244), 	ES(306, 227), 	ES(171, 200), 	ES(205, 103), 
	ES(92, 89), 	ES(218, 145), 	ES(276, 202), 	ES(315, 203), 	ES(445, 147), 	ES(444, 131), 	ES(301, 103), 	ES(184, 49), 
	ES(44, 32), 	ES(103, 105), 	ES(196, 134), 	ES(240, 129), 	ES(200, 112), 	ES(417, 49), 	ES(102, 96), 	ES(182, -19), 
	ES(-420, -155), 	ES(-309, 61), 	ES(-82, 104), 	ES(29, 77), 	ES(144, 88), 	ES(-52, 6), 	ES(-234, 82), 	ES(-225, -236), 
};

EvalScore BISHOP_PSQT[] = {
	ES(7, 62), 	ES(92, 132), 	ES(27, 59), 	ES(3, 140), 	ES(23, 129), 	ES(8, 129), 	ES(100, 75), 	ES(52, 20), 
	ES(95, 129), 	ES(94, 130), 	ES(143, 129), 	ES(59, 178), 	ES(85, 189), 	ES(132, 144), 	ES(151, 157), 	ES(107, 61), 
	ES(81, 148), 	ES(108, 184), 	ES(110, 209), 	ES(117, 218), 	ES(120, 229), 	ES(106, 216), 	ES(116, 158), 	ES(128, 116), 
	ES(47, 148), 	ES(92, 213), 	ES(115, 240), 	ES(182, 225), 	ES(180, 229), 	ES(115, 221), 	ES(93, 196), 	ES(65, 110), 
	ES(69, 158), 	ES(119, 222), 	ES(202, 204), 	ES(237, 255), 	ES(228, 219), 	ES(214, 213), 	ES(123, 215), 	ES(73, 158), 
	ES(106, 179), 	ES(193, 162), 	ES(188, 198), 	ES(270, 162), 	ES(227, 181), 	ES(337, 178), 	ES(258, 153), 	ES(198, 152), 
	ES(71, 77), 	ES(152, 143), 	ES(128, 159), 	ES(73, 167), 	ES(179, 135), 	ES(179, 137), 	ES(142, 154), 	ES(107, 66), 
	ES(17, 120), 	ES(-43, 159), 	ES(-7, 152), 	ES(-160, 192), 	ES(-115, 177), 	ES(-57, 140), 	ES(46, 120), 	ES(-85, 112), 
};

EvalScore ROOK_PSQT[] = {
	ES(53, 311), 	ES(62, 348), 	ES(95, 370), 	ES(111, 364), 	ES(131, 336), 	ES(92, 324), 	ES(148, 310), 	ES(59, 275), 
	ES(-9, 331), 	ES(35, 341), 	ES(83, 339), 	ES(73, 351), 	ES(85, 319), 	ES(97, 310), 	ES(165, 273), 	ES(54, 293), 
	ES(0, 347), 	ES(30, 344), 	ES(60, 344), 	ES(54, 359), 	ES(80, 349), 	ES(73, 316), 	ES(198, 246), 	ES(120, 255), 
	ES(22, 364), 	ES(32, 380), 	ES(67, 388), 	ES(112, 379), 	ES(112, 367), 	ES(61, 362), 	ES(144, 316), 	ES(110, 288), 
	ES(87, 389), 	ES(141, 383), 	ES(144, 412), 	ES(174, 401), 	ES(196, 350), 	ES(201, 324), 	ES(233, 310), 	ES(233, 287), 
	ES(143, 376), 	ES(219, 389), 	ES(227, 400), 	ES(236, 390), 	ES(335, 345), 	ES(339, 322), 	ES(474, 292), 	ES(391, 272), 
	ES(219, 383), 	ES(221, 425), 	ES(284, 433), 	ES(348, 403), 	ES(303, 407), 	ES(403, 351), 	ES(366, 346), 	ES(469, 293), 
	ES(289, 384), 	ES(246, 406), 	ES(275, 440), 	ES(291, 418), 	ES(359, 392), 	ES(421, 354), 	ES(353, 363), 	ES(426, 338), 
};

EvalScore QUEEN_PSQT[] = {
	ES(355, 905), 	ES(320, 927), 	ES(348, 937), 	ES(403, 908), 	ES(371, 924), 	ES(329, 929), 	ES(408, 809), 	ES(382, 817), 
	ES(372, 927), 	ES(379, 929), 	ES(427, 929), 	ES(420, 956), 	ES(413, 965), 	ES(444, 876), 	ES(470, 778), 	ES(504, 672), 
	ES(372, 939), 	ES(403, 1003), 	ES(380, 1081), 	ES(384, 1066), 	ES(393, 1080), 	ES(413, 1055), 	ES(458, 972), 	ES(438, 932), 
	ES(379, 977), 	ES(379, 1087), 	ES(377, 1115), 	ES(402, 1182), 	ES(399, 1174), 	ES(397, 1142), 	ES(434, 1075), 	ES(449, 1031), 
	ES(378, 984), 	ES(395, 1069), 	ES(407, 1129), 	ES(398, 1196), 	ES(411, 1253), 	ES(456, 1199), 	ES(457, 1147), 	ES(475, 1064), 
	ES(435, 948), 	ES(425, 1010), 	ES(419, 1161), 	ES(480, 1175), 	ES(489, 1219), 	ES(638, 1151), 	ES(643, 1013), 	ES(638, 965), 
	ES(437, 911), 	ES(357, 1064), 	ES(374, 1185), 	ES(356, 1255), 	ES(374, 1312), 	ES(507, 1166), 	ES(434, 1104), 	ES(588, 1008), 
	ES(309, 1035), 	ES(324, 1084), 	ES(437, 1139), 	ES(558, 1097), 	ES(555, 1092), 	ES(587, 1050), 	ES(643, 903), 	ES(451, 1007), 
};

EvalScore KING_PSQT[] = {
	ES(214, -307), 	ES(295, -241), 	ES(199, -168), 	ES(-151, -100), 	ES(81, -193), 	ES(-61, -106), 	ES(230, -205), 	ES(234, -304), 
	ES(233, -181), 	ES(86, -80), 	ES(35, -41), 	ES(-88, 3), 	ES(-97, 8), 	ES(-29, -20), 	ES(144, -87), 	ES(176, -152), 
	ES(-86, -106), 	ES(-26, -20), 	ES(-227, 59), 	ES(-273, 102), 	ES(-254, 96), 	ES(-245, 69), 	ES(-80, -5), 	ES(-140, -45), 
	ES(-238, -69), 	ES(-275, 40), 	ES(-383, 126), 	ES(-477, 179), 	ES(-468, 184), 	ES(-341, 131), 	ES(-350, 96), 	ES(-440, 28), 
	ES(-264, -25), 	ES(-303, 99), 	ES(-355, 164), 	ES(-514, 209), 	ES(-475, 200), 	ES(-340, 184), 	ES(-332, 159), 	ES(-417, 64), 
	ES(-371, 14), 	ES(-11, 76), 	ES(-252, 146), 	ES(-320, 178), 	ES(-175, 184), 	ES(90, 150), 	ES(23, 150), 	ES(-101, 46), 
	ES(-291, -47), 	ES(-158, 55), 	ES(-305, 106), 	ES(59, 41), 	ES(-114, 111), 	ES(-94, 152), 	ES(43, 122), 	ES(-22, 0), 
	ES(10, -349), 	ES(-26, -184), 	ES(82, -150), 	ES(-310, 4), 	ES(-149, -62), 	ES(11, -41), 	ES(148, -63), 	ES(241, -386), 
};

EvalScore BISHOP_PAIR = ES(126, 126);

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

	EvalScore bishop_pair = 0;
	if (_mm_popcnt_u64(board.piece_boards[OCC(WHITE)] & board.piece_boards[BISHOP]) >= 2)
		bishop_pair += BISHOP_PAIR;
	if (_mm_popcnt_u64(board.piece_boards[OCC(BLACK)] & board.piece_boards[BISHOP]) >= 2)
		bishop_pair -= BISHOP_PAIR;

	EvalScore final_eval = material + psqt + bishop_pair;
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

	std::pair<double, double> bishop_pair_grad = {0, 0};
	if (_mm_popcnt_u64(board.piece_boards[OCC(WHITE)] & board.piece_boards[BISHOP]) >= 2)
		bishop_pair_grad.first += BISHOP_PAIR.mg, bishop_pair_grad.second += BISHOP_PAIR.eg;
	if (_mm_popcnt_u64(board.piece_boards[OCC(BLACK)] & board.piece_boards[BISHOP]) >= 2)
		bishop_pair_grad.first -= BISHOP_PAIR.mg, bishop_pair_grad.second -= BISHOP_PAIR.eg;
	grads.push_back(bishop_pair_grad);

	return grads;
}