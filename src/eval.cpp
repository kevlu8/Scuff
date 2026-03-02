#include "eval.hpp"
#include "eval_funcs.hpp"

EvalScore MATERIAL_VALUES[] = {
	ES(233, 411),
	ES(852, 1109),
	ES(842, 1079),
	ES(1157, 1835),
	ES(2261, 3104),
};

EvalScore PAWN_PSQT[] = {
	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 
	ES(-81, -13), 	ES(-12, 7), 	ES(-18, -45), 	ES(-33, -20), 	ES(14, 4), 	ES(73, -41), 	ES(138, -40), 	ES(-20, -74), 
	ES(-89, -28), 	ES(-9, -10), 	ES(-15, -68), 	ES(1, -40), 	ES(48, -46), 	ES(11, -58), 	ES(103, -37), 	ES(4, -77), 
	ES(-91, -7), 	ES(-20, 0), 	ES(-10, -59), 	ES(40, -80), 	ES(46, -77), 	ES(26, -68), 	ES(45, -33), 	ES(-24, -61), 
	ES(-67, 79), 	ES(5, 47), 	ES(11, -10), 	ES(27, -50), 	ES(90, -66), 	ES(74, -48), 	ES(79, 8), 	ES(14, 3), 
	ES(-20, 329), 	ES(16, 369), 	ES(129, 239), 	ES(140, 159), 	ES(139, 132), 	ES(215, 104), 	ES(157, 258), 	ES(22, 250), 
	ES(226, 537), 	ES(312, 507), 	ES(218, 503), 	ES(320, 331), 	ES(254, 325), 	ES(200, 371), 	ES(-31, 527), 	ES(-99, 567), 
	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 
};

EvalScore KNIGHT_PSQT[] = {
	ES(-204, 9), 	ES(-12, -4), 	ES(-48, 81), 	ES(-2, 89), 	ES(16, 94), 	ES(69, 60), 	ES(-4, 3), 	ES(-96, -34), 
	ES(-47, 43), 	ES(-15, 97), 	ES(53, 125), 	ES(98, 143), 	ES(101, 135), 	ES(104, 112), 	ES(51, 63), 	ES(45, 77), 
	ES(-17, 75), 	ES(59, 140), 	ES(114, 153), 	ES(117, 211), 	ES(170, 206), 	ES(125, 145), 	ES(134, 126), 	ES(48, 76), 
	ES(41, 143), 	ES(83, 163), 	ES(124, 235), 	ES(142, 229), 	ES(163, 246), 	ES(153, 209), 	ES(154, 177), 	ES(78, 107), 
	ES(70, 136), 	ES(101, 204), 	ES(162, 232), 	ES(245, 247), 	ES(166, 255), 	ES(245, 235), 	ES(130, 211), 	ES(177, 113), 
	ES(64, 95), 	ES(156, 152), 	ES(198, 203), 	ES(222, 213), 	ES(338, 162), 	ES(368, 128), 	ES(226, 128), 	ES(156, 62), 
	ES(20, 45), 	ES(74, 122), 	ES(143, 152), 	ES(174, 156), 	ES(129, 125), 	ES(340, 72), 	ES(71, 116), 	ES(156, -12), 
	ES(-420, -139), 	ES(-332, 49), 	ES(-124, 110), 	ES(-13, 95), 	ES(97, 113), 	ES(-93, 21), 	ES(-248, 74), 	ES(-239, -230), 
};

EvalScore BISHOP_PSQT[] = {
	ES(50, 93), 	ES(125, 150), 	ES(57, 88), 	ES(40, 146), 	ES(56, 131), 	ES(46, 141), 	ES(129, 93), 	ES(96, 41), 
	ES(113, 150), 	ES(99, 123), 	ES(142, 111), 	ES(70, 163), 	ES(99, 164), 	ES(143, 128), 	ES(164, 141), 	ES(122, 83), 
	ES(85, 164), 	ES(114, 174), 	ES(109, 197), 	ES(119, 186), 	ES(112, 204), 	ES(119, 183), 	ES(108, 144), 	ES(138, 127), 
	ES(58, 149), 	ES(57, 201), 	ES(86, 215), 	ES(154, 196), 	ES(155, 192), 	ES(93, 187), 	ES(85, 182), 	ES(84, 122), 
	ES(59, 176), 	ES(108, 200), 	ES(144, 192), 	ES(174, 221), 	ES(164, 195), 	ES(168, 199), 	ES(100, 189), 	ES(71, 180), 
	ES(88, 185), 	ES(146, 163), 	ES(141, 181), 	ES(182, 151), 	ES(152, 170), 	ES(275, 171), 	ES(222, 160), 	ES(178, 180), 
	ES(46, 109), 	ES(118, 147), 	ES(73, 155), 	ES(36, 169), 	ES(103, 146), 	ES(123, 145), 	ES(96, 172), 	ES(107, 96), 
	ES(12, 153), 	ES(-91, 191), 	ES(-56, 185), 	ES(-219, 223), 	ES(-154, 208), 	ES(-97, 173), 	ES(-4, 156), 	ES(-100, 140), 
};

EvalScore ROOK_PSQT[] = {
	ES(82, 306), 	ES(82, 315), 	ES(109, 340), 	ES(133, 337), 	ES(148, 314), 	ES(117, 319), 	ES(162, 291), 	ES(86, 273), 
	ES(6, 311), 	ES(41, 326), 	ES(103, 328), 	ES(79, 336), 	ES(107, 314), 	ES(114, 294), 	ES(170, 266), 	ES(66, 284), 
	ES(15, 339), 	ES(42, 342), 	ES(65, 331), 	ES(61, 349), 	ES(86, 329), 	ES(82, 311), 	ES(188, 253), 	ES(113, 250), 
	ES(30, 359), 	ES(33, 371), 	ES(60, 377), 	ES(102, 380), 	ES(108, 366), 	ES(51, 367), 	ES(138, 321), 	ES(112, 308), 
	ES(71, 387), 	ES(127, 382), 	ES(123, 411), 	ES(140, 408), 	ES(158, 352), 	ES(172, 335), 	ES(224, 325), 	ES(222, 305), 
	ES(104, 394), 	ES(181, 392), 	ES(168, 396), 	ES(188, 409), 	ES(281, 355), 	ES(295, 339), 	ES(440, 310), 	ES(361, 278), 
	ES(145, 388), 	ES(143, 438), 	ES(204, 451), 	ES(279, 419), 	ES(233, 427), 	ES(325, 382), 	ES(314, 364), 	ES(416, 302), 
	ES(231, 378), 	ES(187, 405), 	ES(196, 435), 	ES(216, 424), 	ES(272, 398), 	ES(348, 366), 	ES(308, 377), 	ES(376, 343), 
};

EvalScore QUEEN_PSQT[] = {
	ES(423, 886), 	ES(384, 918), 	ES(410, 906), 	ES(451, 923), 	ES(432, 888), 	ES(389, 906), 	ES(474, 808), 	ES(465, 798), 
	ES(418, 918), 	ES(413, 911), 	ES(441, 902), 	ES(444, 926), 	ES(447, 929), 	ES(465, 858), 	ES(493, 767), 	ES(539, 693), 
	ES(391, 930), 	ES(402, 988), 	ES(385, 1018), 	ES(384, 1020), 	ES(395, 1034), 	ES(419, 1011), 	ES(458, 975), 	ES(448, 954), 
	ES(398, 955), 	ES(349, 1067), 	ES(341, 1076), 	ES(387, 1114), 	ES(382, 1120), 	ES(359, 1125), 	ES(413, 1075), 	ES(460, 1069), 
	ES(380, 978), 	ES(369, 1037), 	ES(351, 1095), 	ES(333, 1165), 	ES(338, 1226), 	ES(408, 1196), 	ES(435, 1166), 	ES(477, 1109), 
	ES(419, 967), 	ES(386, 1007), 	ES(348, 1150), 	ES(374, 1188), 	ES(403, 1238), 	ES(570, 1172), 	ES(600, 1038), 	ES(619, 1033), 
	ES(416, 950), 	ES(291, 1089), 	ES(289, 1203), 	ES(271, 1266), 	ES(279, 1346), 	ES(423, 1206), 	ES(392, 1129), 	ES(597, 1055), 
	ES(321, 1035), 	ES(261, 1127), 	ES(355, 1185), 	ES(456, 1135), 	ES(473, 1136), 	ES(501, 1118), 	ES(623, 930), 	ES(467, 1030), 
};

EvalScore KING_PSQT[] = {
	ES(308, -340), 	ES(285, -225), 	ES(199, -155), 	ES(-151, -98), 	ES(66, -177), 	ES(-64, -107), 	ES(204, -195), 	ES(328, -356), 
	ES(221, -175), 	ES(51, -69), 	ES(7, -31), 	ES(-110, 5), 	ES(-115, 19), 	ES(-49, -11), 	ES(108, -78), 	ES(153, -148), 
	ES(-79, -105), 	ES(-49, -15), 	ES(-254, 64), 	ES(-301, 97), 	ES(-274, 103), 	ES(-266, 68), 	ES(-108, -1), 	ES(-149, -50), 
	ES(-217, -71), 	ES(-278, 45), 	ES(-391, 128), 	ES(-496, 187), 	ES(-493, 170), 	ES(-357, 131), 	ES(-364, 88), 	ES(-421, 25), 
	ES(-222, -37), 	ES(-297, 94), 	ES(-349, 169), 	ES(-505, 203), 	ES(-477, 206), 	ES(-340, 177), 	ES(-321, 157), 	ES(-380, 47), 
	ES(-342, 5), 	ES(34, 81), 	ES(-209, 142), 	ES(-289, 183), 	ES(-159, 183), 	ES(121, 151), 	ES(41, 149), 	ES(-58, 31), 
	ES(-287, -44), 	ES(-131, 62), 	ES(-294, 111), 	ES(92, 43), 	ES(-100, 115), 	ES(-85, 159), 	ES(59, 117), 	ES(-7, -4), 
	ES(245, -419), 	ES(101, -198), 	ES(203, -160), 	ES(-290, 5), 	ES(-111, -63), 	ES(72, -48), 	ES(230, -86), 	ES(575, -475), 
};

EvalScore BISHOP_PAIR = ES(82, 209);

EvalScore KNIGHT_MOB[] = {
	ES(-54, -1),
	ES(-16, -3),
	ES(-8, 25),
	ES(0, 35),
	ES(20, 10),
	ES(31, 10),
	ES(19, 13),
	ES(39, 17),
	ES(49, 30),
};

EvalScore BISHOP_MOB[] = {
	ES(-329, -37),
	ES(-305, -20),
	ES(-299, -37),
	ES(-248, -58),
	ES(-211, -55),
	ES(-164, -67),
	ES(-134, -42),
	ES(-116, -23),
	ES(-92, -3),
	ES(-74, 14),
	ES(-52, 20),
	ES(-29, 18),
	ES(-12, 30),
	ES(6, 34),
	ES(29, 49),
	ES(44, 58),
	ES(61, 87),
	ES(71, 109),
	ES(96, 110),
	ES(110, 133),
	ES(136, 140),
	ES(157, 180),
	ES(168, 176),
	ES(184, 203),
	ES(205, 201),
	ES(220, 237),
	ES(239, 243),
	ES(258, 269),
	ES(258, 327),
	ES(285, 332),
	ES(293, 345),
	ES(301, 360),
};

EvalScore ROOK_MOB[] = {
	ES(-805, -52),
	ES(-799, -42),
	ES(-191, -134),
	ES(-134, -123),
	ES(-46, -155),
	ES(55, -165),
	ES(45, -147),
	ES(0, -104),
	ES(-28, -59),
	ES(-53, -36),
	ES(-57, -22),
	ES(-40, -10),
	ES(-41, 1),
	ES(-44, 14),
	ES(-38, 23),
	ES(-20, 33),
	ES(-14, 51),
	ES(-3, 51),
	ES(7, 55),
	ES(19, 79),
	ES(29, 101),
	ES(49, 119),
	ES(60, 131),
	ES(76, 149),
	ES(102, 151),
	ES(110, 160),
	ES(139, 140),
	ES(165, 133),
	ES(181, 132),
	ES(209, 113),
	ES(232, 89),
	ES(267, 95),
};

EvalScore KING_MOB[] = {
	ES(0, 0),
	ES(1, 1),
	ES(2, 2),
	ES(3, 3),
	ES(-127, 73),
	ES(-92, 23),
	ES(25, 6),
	ES(62, -24),
};

EvalScore PASSED_PAWN = ES(-37, 86);

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

	EvalScore mobility = 0;
	int w_knight_mob = _mm_popcnt_u64(board.controlled_squares[OCC(WHITE)] & board.controlled_squares[KNIGHT]);
	int b_knight_mob = _mm_popcnt_u64(board.controlled_squares[OCC(BLACK)] & board.controlled_squares[KNIGHT]);
	mobility += KNIGHT_MOB[std::min(w_knight_mob, 8)] - KNIGHT_MOB[std::min(b_knight_mob, 8)];
	int w_bishop_mob = _mm_popcnt_u64(board.controlled_squares[OCC(WHITE)] & board.controlled_squares[BISHOP]);
	int b_bishop_mob = _mm_popcnt_u64(board.controlled_squares[OCC(BLACK)] & board.controlled_squares[BISHOP]);
	mobility += BISHOP_MOB[std::min(w_bishop_mob, 31)] - BISHOP_MOB[std::min(b_bishop_mob, 31)];
	int w_rook_mob = _mm_popcnt_u64(board.controlled_squares[OCC(WHITE)] & board.controlled_squares[ROOK]);
	int b_rook_mob = _mm_popcnt_u64(board.controlled_squares[OCC(BLACK)] & board.controlled_squares[ROOK]);
	mobility += ROOK_MOB[std::min(w_rook_mob, 31)] - ROOK_MOB[std::min(b_rook_mob, 31)];
	int w_king_mob = _mm_popcnt_u64(board.controlled_squares[OCC(WHITE)] & board.controlled_squares[KING]);
	int b_king_mob = _mm_popcnt_u64(board.controlled_squares[OCC(BLACK)] & board.controlled_squares[KING]);
	mobility += KING_MOB[std::min(w_king_mob, 7)] - KING_MOB[std::min(b_king_mob, 7)];

	EvalScore passed_pawn = 0;
	Bitboard pawns = board.piece_boards[OCC(WHITE)] & board.piece_boards[PAWN];
	while (pawns) {
		int sq = _tzcnt_u64(pawns);
		passed_pawn += Eval::passed_pawn_mask[WHITE][sq] & board.piece_boards[OCC(BLACK)] & board.piece_boards[PAWN] ? 0 : PASSED_PAWN;
		pawns &= pawns - 1;
	}
	pawns = board.piece_boards[OCC(BLACK)] & board.piece_boards[PAWN];
	while (pawns) {
		int sq = _tzcnt_u64(pawns);
		passed_pawn -= Eval::passed_pawn_mask[BLACK][sq] & board.piece_boards[OCC(WHITE)] & board.piece_boards[PAWN] ? 0 : PASSED_PAWN;
		pawns &= pawns - 1;
	}

	EvalScore final_eval = material + psqt + bishop_pair + mobility + passed_pawn;

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
		bishop_pair_grad.first += alpha, bishop_pair_grad.second += beta;
	if (_mm_popcnt_u64(board.piece_boards[OCC(BLACK)] & board.piece_boards[BISHOP]) >= 2)
		bishop_pair_grad.first -= alpha, bishop_pair_grad.second -= beta;
	grads.push_back(bishop_pair_grad);

	std::vector<std::pair<double, double>> knight_mob_grads(9), bishop_mob_grads(32), rook_mob_grads(32), king_mob_grads(8);
	
	int w_knight_mob = _mm_popcnt_u64(board.controlled_squares[OCC(WHITE)] & board.controlled_squares[KNIGHT]);
	int b_knight_mob = _mm_popcnt_u64(board.controlled_squares[OCC(BLACK)] & board.controlled_squares[KNIGHT]);
	knight_mob_grads[std::min(w_knight_mob, 8)].first += alpha, knight_mob_grads[std::min(w_knight_mob, 8)].second += beta;
	knight_mob_grads[std::min(b_knight_mob, 8)].first -= alpha, knight_mob_grads[std::min(b_knight_mob, 8)].second -= beta;
	int w_bishop_mob = _mm_popcnt_u64(board.controlled_squares[OCC(WHITE)] & board.controlled_squares[BISHOP]);
	int b_bishop_mob = _mm_popcnt_u64(board.controlled_squares[OCC(BLACK)] & board.controlled_squares[BISHOP]);
	bishop_mob_grads[std::min(w_bishop_mob, 31)].first += alpha, bishop_mob_grads[std::min(w_bishop_mob, 31)].second += beta;
	bishop_mob_grads[std::min(b_bishop_mob, 31)].first -= alpha, bishop_mob_grads[std::min(b_bishop_mob, 31)].second -= beta;
	int w_rook_mob = _mm_popcnt_u64(board.controlled_squares[OCC(WHITE)] & board.controlled_squares[ROOK]);
	int b_rook_mob = _mm_popcnt_u64(board.controlled_squares[OCC(BLACK)] & board.controlled_squares[ROOK]);
	rook_mob_grads[std::min(w_rook_mob, 31)].first += alpha, rook_mob_grads[std::min(w_rook_mob, 31)].second += beta;
	rook_mob_grads[std::min(b_rook_mob, 31)].first -= alpha, rook_mob_grads[std::min(b_rook_mob, 31)].second -= beta;
	int w_king_mob = _mm_popcnt_u64(board.controlled_squares[OCC(WHITE)] & board.controlled_squares[KING]);
	int b_king_mob = _mm_popcnt_u64(board.controlled_squares[OCC(BLACK)] & board.controlled_squares[KING]);
	king_mob_grads[std::min(w_king_mob, 7)].first += alpha, king_mob_grads[std::min(w_king_mob, 7)].second += beta;
	king_mob_grads[std::min(b_king_mob, 7)].first -= alpha, king_mob_grads[std::min(b_king_mob, 7)].second -= beta;

	grads.insert(grads.end(), knight_mob_grads.begin(), knight_mob_grads.end());
	grads.insert(grads.end(), bishop_mob_grads.begin(), bishop_mob_grads.end());
	grads.insert(grads.end(), rook_mob_grads.begin(), rook_mob_grads.end());
	grads.insert(grads.end(), king_mob_grads.begin(), king_mob_grads.end());

	std::pair<double, double> passed_pawn_grad = {0, 0};
	Bitboard pawns = board.piece_boards[OCC(WHITE)] & board.piece_boards[PAWN];
	while (pawns) {
		int sq = _tzcnt_u64(pawns);
		if (!(Eval::passed_pawn_mask[WHITE][sq] & board.piece_boards[OCC(BLACK)] & board.piece_boards[PAWN]))
			passed_pawn_grad.first += alpha, passed_pawn_grad.second += beta;
		pawns &= pawns - 1;
	}
	pawns = board.piece_boards[OCC(BLACK)] & board.piece_boards[PAWN];
	while (pawns) {
		int sq = _tzcnt_u64(pawns);
		if (!(Eval::passed_pawn_mask[BLACK][sq] & board.piece_boards[OCC(WHITE)] & board.piece_boards[PAWN]))
			passed_pawn_grad.first -= alpha, passed_pawn_grad.second -= beta;
		pawns &= pawns - 1;
	}
	grads.push_back(passed_pawn_grad);

	return grads;
}