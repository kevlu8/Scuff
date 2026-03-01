#include "eval.hpp"

EvalScore MATERIAL_VALUES[] = {
	ES(211, 446),
	ES(853, 1101),
	ES(844, 1072),
	ES(1162, 1823),
	ES(2288, 3095),
};

EvalScore PAWN_PSQT[] = {
	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 
	ES(-84, 14), 	ES(-11, 23), 	ES(-15, -34), 	ES(-37, 0), 	ES(20, 16), 	ES(78, -34), 	ES(142, -33), 	ES(-20, -56), 
	ES(-96, -2), 	ES(-12, 2), 	ES(-18, -58), 	ES(-1, -12), 	ES(50, -36), 	ES(11, -52), 	ES(103, -25), 	ES(5, -59), 
	ES(-89, 18), 	ES(-18, 18), 	ES(-5, -52), 	ES(40, -61), 	ES(53, -67), 	ES(25, -66), 	ES(42, -21), 	ES(-23, -49), 
	ES(-70, 113), 	ES(7, 69), 	ES(10, 10), 	ES(26, -28), 	ES(87, -58), 	ES(68, -48), 	ES(80, 23), 	ES(11, 25), 
	ES(-29, 361), 	ES(9, 397), 	ES(115, 273), 	ES(121, 198), 	ES(126, 169), 	ES(211, 125), 	ES(154, 282), 	ES(13, 276), 
	ES(224, 580), 	ES(302, 545), 	ES(212, 550), 	ES(312, 377), 	ES(242, 366), 	ES(197, 409), 	ES(-41, 571), 	ES(-109, 610), 
	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 
};

EvalScore KNIGHT_PSQT[] = {
	ES(-201, 9), 	ES(-9, -4), 	ES(-51, 73), 	ES(3, 94), 	ES(18, 101), 	ES(60, 55), 	ES(3, 15), 	ES(-98, -40), 
	ES(-53, 38), 	ES(-14, 98), 	ES(48, 130), 	ES(100, 142), 	ES(98, 137), 	ES(107, 119), 	ES(54, 64), 	ES(46, 78), 
	ES(-11, 80), 	ES(60, 138), 	ES(111, 153), 	ES(125, 213), 	ES(159, 199), 	ES(129, 147), 	ES(128, 130), 	ES(44, 82), 
	ES(35, 144), 	ES(87, 162), 	ES(127, 230), 	ES(135, 227), 	ES(162, 247), 	ES(156, 215), 	ES(154, 173), 	ES(73, 106), 
	ES(71, 136), 	ES(99, 202), 	ES(166, 237), 	ES(239, 239), 	ES(165, 253), 	ES(244, 236), 	ES(127, 211), 	ES(180, 113), 
	ES(61, 91), 	ES(153, 149), 	ES(199, 203), 	ES(223, 213), 	ES(339, 158), 	ES(364, 126), 	ES(227, 122), 	ES(159, 64), 
	ES(29, 33), 	ES(75, 112), 	ES(148, 146), 	ES(177, 153), 	ES(127, 121), 	ES(342, 71), 	ES(72, 98), 	ES(162, -21), 
	ES(-425, -145), 	ES(-329, 50), 	ES(-119, 112), 	ES(-13, 88), 	ES(100, 103), 	ES(-92, 15), 	ES(-245, 74), 	ES(-238, -229), 
};

EvalScore BISHOP_PSQT[] = {
	ES(49, 96), 	ES(127, 143), 	ES(62, 94), 	ES(41, 143), 	ES(56, 138), 	ES(41, 138), 	ES(133, 90), 	ES(96, 40), 
	ES(116, 146), 	ES(102, 126), 	ES(145, 112), 	ES(66, 162), 	ES(100, 165), 	ES(143, 127), 	ES(159, 143), 	ES(122, 82), 
	ES(83, 158), 	ES(101, 177), 	ES(100, 185), 	ES(121, 181), 	ES(115, 201), 	ES(116, 183), 	ES(106, 141), 	ES(141, 131), 
	ES(65, 152), 	ES(59, 201), 	ES(85, 209), 	ES(153, 190), 	ES(154, 196), 	ES(91, 191), 	ES(81, 182), 	ES(92, 125), 
	ES(61, 171), 	ES(106, 201), 	ES(139, 187), 	ES(181, 229), 	ES(161, 191), 	ES(167, 197), 	ES(105, 187), 	ES(72, 180), 
	ES(86, 186), 	ES(150, 168), 	ES(138, 179), 	ES(186, 149), 	ES(156, 171), 	ES(277, 168), 	ES(221, 156), 	ES(181, 178), 
	ES(57, 98), 	ES(116, 132), 	ES(83, 156), 	ES(35, 166), 	ES(106, 149), 	ES(128, 139), 	ES(98, 164), 	ES(107, 89), 
	ES(9, 152), 	ES(-86, 185), 	ES(-54, 184), 	ES(-216, 220), 	ES(-158, 205), 	ES(-95, 166), 	ES(-5, 157), 	ES(-97, 132), 
};

EvalScore ROOK_PSQT[] = {
	ES(81, 305), 	ES(85, 324), 	ES(109, 344), 	ES(132, 336), 	ES(146, 312), 	ES(121, 311), 	ES(158, 286), 	ES(83, 273), 
	ES(6, 309), 	ES(49, 332), 	ES(102, 324), 	ES(87, 337), 	ES(108, 305), 	ES(108, 291), 	ES(162, 260), 	ES(67, 282), 
	ES(14, 341), 	ES(34, 335), 	ES(63, 327), 	ES(67, 350), 	ES(88, 329), 	ES(83, 313), 	ES(190, 261), 	ES(115, 251), 
	ES(29, 358), 	ES(33, 370), 	ES(59, 374), 	ES(99, 376), 	ES(103, 365), 	ES(43, 361), 	ES(139, 325), 	ES(107, 303), 
	ES(75, 390), 	ES(120, 375), 	ES(124, 413), 	ES(134, 401), 	ES(161, 355), 	ES(168, 337), 	ES(215, 327), 	ES(216, 305), 
	ES(99, 382), 	ES(178, 392), 	ES(174, 404), 	ES(182, 401), 	ES(282, 354), 	ES(294, 340), 	ES(435, 308), 	ES(359, 277), 
	ES(149, 394), 	ES(150, 430), 	ES(207, 444), 	ES(282, 413), 	ES(231, 420), 	ES(322, 367), 	ES(317, 350), 	ES(425, 305), 
	ES(232, 369), 	ES(192, 399), 	ES(203, 434), 	ES(225, 421), 	ES(277, 399), 	ES(350, 357), 	ES(307, 367), 	ES(379, 339), 
};

EvalScore QUEEN_PSQT[] = {
	ES(424, 885), 	ES(388, 921), 	ES(406, 907), 	ES(454, 926), 	ES(433, 895), 	ES(391, 905), 	ES(475, 812), 	ES(462, 799), 
	ES(411, 911), 	ES(407, 908), 	ES(439, 903), 	ES(442, 928), 	ES(445, 934), 	ES(466, 860), 	ES(489, 766), 	ES(545, 700), 
	ES(398, 938), 	ES(400, 985), 	ES(387, 1022), 	ES(381, 1017), 	ES(395, 1036), 	ES(418, 1014), 	ES(453, 979), 	ES(453, 955), 
	ES(409, 963), 	ES(344, 1067), 	ES(339, 1078), 	ES(384, 1117), 	ES(374, 1109), 	ES(358, 1127), 	ES(413, 1081), 	ES(453, 1064), 
	ES(375, 981), 	ES(368, 1039), 	ES(349, 1097), 	ES(333, 1166), 	ES(333, 1222), 	ES(408, 1198), 	ES(437, 1166), 	ES(472, 1107), 
	ES(431, 975), 	ES(385, 1011), 	ES(349, 1150), 	ES(377, 1190), 	ES(408, 1245), 	ES(569, 1163), 	ES(607, 1044), 	ES(622, 1031), 
	ES(419, 941), 	ES(294, 1074), 	ES(299, 1206), 	ES(274, 1266), 	ES(283, 1344), 	ES(430, 1204), 	ES(396, 1116), 	ES(602, 1051), 
	ES(328, 1034), 	ES(265, 1116), 	ES(366, 1174), 	ES(469, 1127), 	ES(482, 1122), 	ES(521, 1096), 	ES(626, 921), 	ES(467, 1025), 
};

EvalScore KING_PSQT[] = {
	ES(307, -346), 	ES(282, -235), 	ES(200, -161), 	ES(-148, -102), 	ES(65, -175), 	ES(-58, -105), 	ES(209, -200), 	ES(331, -358), 
	ES(224, -178), 	ES(53, -84), 	ES(15, -33), 	ES(-106, 3), 	ES(-117, 9), 	ES(-53, -15), 	ES(115, -81), 	ES(157, -147), 
	ES(-78, -107), 	ES(-46, -18), 	ES(-248, 56), 	ES(-296, 96), 	ES(-274, 98), 	ES(-259, 69), 	ES(-102, 4), 	ES(-144, -48), 
	ES(-219, -69), 	ES(-280, 47), 	ES(-386, 132), 	ES(-494, 178), 	ES(-484, 182), 	ES(-359, 131), 	ES(-361, 97), 	ES(-420, 28), 
	ES(-236, -28), 	ES(-306, 102), 	ES(-356, 167), 	ES(-511, 205), 	ES(-474, 208), 	ES(-338, 192), 	ES(-334, 161), 	ES(-398, 57), 
	ES(-342, 10), 	ES(13, 84), 	ES(-225, 146), 	ES(-305, 183), 	ES(-162, 183), 	ES(107, 154), 	ES(27, 152), 	ES(-66, 45), 
	ES(-279, -44), 	ES(-140, 66), 	ES(-301, 108), 	ES(75, 43), 	ES(-107, 113), 	ES(-93, 157), 	ES(35, 122), 	ES(-17, 1), 
	ES(132, -386), 	ES(47, -183), 	ES(169, -155), 	ES(-301, 8), 	ES(-126, -58), 	ES(44, -45), 	ES(194, -76), 	ES(389, -436), 
};

EvalScore BISHOP_PAIR = ES(78, 204);

EvalScore KNIGHT_MOB[] = {
	ES(-58, 3),
	ES(-15, -1),
	ES(-10, 36),
	ES(-4, 27),
	ES(30, 15),
	ES(31, 13),
	ES(27, 14),
	ES(34, 16),
	ES(48, 25),
};

EvalScore BISHOP_MOB[] = {
	ES(-340, -26),
	ES(-319, -12),
	ES(-311, -24),
	ES(-255, -46),
	ES(-214, -47),
	ES(-163, -55),
	ES(-137, -33),
	ES(-113, -21),
	ES(-96, -2),
	ES(-70, 17),
	ES(-57, 18),
	ES(-31, 16),
	ES(-15, 31),
	ES(10, 27),
	ES(23, 40),
	ES(44, 54),
	ES(58, 79),
	ES(77, 104),
	ES(99, 113),
	ES(117, 131),
	ES(141, 134),
	ES(154, 169),
	ES(164, 165),
	ES(185, 193),
	ES(209, 190),
	ES(219, 223),
	ES(239, 236),
	ES(263, 257),
	ES(267, 318),
	ES(286, 314),
	ES(298, 324),
	ES(301, 330),
};

EvalScore ROOK_MOB[] = {
	ES(-462, -117),
	ES(-518, -92),
	ES(-206, -131),
	ES(-155, -119),
	ES(-65, -151),
	ES(46, -165),
	ES(46, -142),
	ES(3, -100),
	ES(-24, -59),
	ES(-61, -46),
	ES(-57, -21),
	ES(-45, -13),
	ES(-48, 0),
	ES(-39, 12),
	ES(-37, 27),
	ES(-25, 30),
	ES(-14, 45),
	ES(1, 55),
	ES(6, 59),
	ES(18, 83),
	ES(27, 107),
	ES(47, 123),
	ES(55, 128),
	ES(71, 145),
	ES(104, 155),
	ES(110, 162),
	ES(141, 146),
	ES(160, 134),
	ES(174, 129),
	ES(203, 111),
	ES(223, 90),
	ES(272, 107),
};

EvalScore KING_MOB[] = {
	ES(0, 0),
	ES(1, 1),
	ES(2, 2),
	ES(3, 3),
	ES(-126, 71),
	ES(-95, 22),
	ES(24, 11),
	ES(64, -28),
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

	EvalScore final_eval = material + psqt + bishop_pair + mobility;

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

	return grads;
}