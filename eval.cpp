#include "eval.hpp"

EvalScore MATERIAL_VALUES[] = {
	ES(213, 446),
	ES(855, 1103),
	ES(842, 1072),
	ES(1166, 1826),
	ES(2279, 3087),
};

EvalScore PAWN_PSQT[] = {
	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 
	ES(-86, 8), 	ES(-13, 23), 	ES(-14, -31), 	ES(-35, -3), 	ES(17, 11), 	ES(74, -31), 	ES(140, -30), 	ES(-19, -57), 
	ES(-91, 0), 	ES(-10, 5), 	ES(-15, -53), 	ES(1, -19), 	ES(41, -35), 	ES(11, -53), 	ES(102, -28), 	ES(3, -62), 
	ES(-92, 23), 	ES(-17, 18), 	ES(-6, -53), 	ES(42, -66), 	ES(48, -70), 	ES(27, -66), 	ES(49, -19), 	ES(-20, -46), 
	ES(-68, 110), 	ES(10, 78), 	ES(9, 6), 	ES(27, -26), 	ES(92, -55), 	ES(78, -44), 	ES(77, 23), 	ES(11, 23), 
	ES(-30, 363), 	ES(4, 392), 	ES(115, 274), 	ES(133, 203), 	ES(129, 180), 	ES(208, 120), 	ES(155, 282), 	ES(8, 271), 
	ES(219, 577), 	ES(298, 541), 	ES(216, 555), 	ES(314, 377), 	ES(245, 369), 	ES(195, 412), 	ES(-40, 571), 	ES(-107, 613), 
	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 
};

EvalScore KNIGHT_PSQT[] = {
	ES(-201, 9), 	ES(-11, -5), 	ES(-45, 79), 	ES(6, 91), 	ES(12, 94), 	ES(57, 49), 	ES(-2, 12), 	ES(-100, -40), 
	ES(-49, 40), 	ES(-13, 96), 	ES(46, 125), 	ES(96, 139), 	ES(103, 136), 	ES(111, 124), 	ES(57, 68), 	ES(44, 76), 
	ES(-8, 79), 	ES(54, 140), 	ES(112, 149), 	ES(122, 210), 	ES(166, 207), 	ES(124, 155), 	ES(130, 129), 	ES(41, 79), 
	ES(37, 142), 	ES(84, 168), 	ES(126, 236), 	ES(142, 230), 	ES(166, 250), 	ES(153, 211), 	ES(149, 175), 	ES(79, 107), 
	ES(74, 137), 	ES(98, 203), 	ES(170, 233), 	ES(237, 242), 	ES(170, 254), 	ES(246, 231), 	ES(129, 220), 	ES(182, 118), 
	ES(69, 95), 	ES(154, 153), 	ES(194, 199), 	ES(218, 208), 	ES(343, 164), 	ES(365, 130), 	ES(228, 125), 	ES(154, 64), 
	ES(27, 30), 	ES(78, 114), 	ES(145, 139), 	ES(175, 149), 	ES(127, 122), 	ES(343, 73), 	ES(73, 100), 	ES(159, -24), 
	ES(-421, -139), 	ES(-327, 53), 	ES(-117, 112), 	ES(-12, 91), 	ES(101, 106), 	ES(-91, 13), 	ES(-246, 73), 	ES(-236, -227), 
};

EvalScore BISHOP_PSQT[] = {
	ES(44, 89), 	ES(133, 149), 	ES(63, 91), 	ES(32, 139), 	ES(61, 132), 	ES(44, 138), 	ES(133, 87), 	ES(93, 42), 
	ES(114, 151), 	ES(101, 125), 	ES(142, 108), 	ES(68, 165), 	ES(95, 160), 	ES(143, 127), 	ES(163, 136), 	ES(121, 79), 
	ES(79, 158), 	ES(104, 176), 	ES(102, 184), 	ES(124, 190), 	ES(115, 204), 	ES(114, 179), 	ES(107, 145), 	ES(134, 126), 
	ES(54, 146), 	ES(57, 200), 	ES(88, 216), 	ES(152, 198), 	ES(152, 191), 	ES(85, 187), 	ES(84, 182), 	ES(88, 119), 
	ES(64, 178), 	ES(107, 198), 	ES(141, 189), 	ES(182, 227), 	ES(165, 199), 	ES(169, 200), 	ES(99, 188), 	ES(71, 177), 
	ES(85, 184), 	ES(150, 164), 	ES(144, 181), 	ES(180, 148), 	ES(151, 166), 	ES(278, 161), 	ES(224, 161), 	ES(179, 178), 
	ES(54, 94), 	ES(119, 137), 	ES(81, 160), 	ES(43, 171), 	ES(104, 148), 	ES(126, 142), 	ES(99, 168), 	ES(110, 92), 
	ES(7, 151), 	ES(-81, 190), 	ES(-52, 180), 	ES(-215, 221), 	ES(-156, 207), 	ES(-92, 171), 	ES(-6, 157), 	ES(-94, 134), 
};

EvalScore ROOK_PSQT[] = {
	ES(84, 305), 	ES(84, 321), 	ES(116, 347), 	ES(131, 342), 	ES(150, 311), 	ES(123, 314), 	ES(161, 291), 	ES(83, 276), 
	ES(9, 310), 	ES(39, 319), 	ES(96, 325), 	ES(80, 328), 	ES(107, 310), 	ES(114, 293), 	ES(171, 269), 	ES(60, 273), 
	ES(16, 345), 	ES(30, 334), 	ES(64, 328), 	ES(61, 350), 	ES(89, 336), 	ES(77, 308), 	ES(190, 259), 	ES(109, 253), 
	ES(27, 357), 	ES(32, 374), 	ES(64, 378), 	ES(94, 372), 	ES(98, 360), 	ES(50, 365), 	ES(132, 314), 	ES(106, 304), 
	ES(73, 389), 	ES(120, 377), 	ES(117, 406), 	ES(135, 403), 	ES(160, 355), 	ES(170, 340), 	ES(217, 326), 	ES(220, 309), 
	ES(99, 384), 	ES(183, 395), 	ES(176, 405), 	ES(179, 399), 	ES(276, 347), 	ES(288, 330), 	ES(434, 304), 	ES(367, 282), 
	ES(153, 392), 	ES(148, 431), 	ES(211, 449), 	ES(284, 416), 	ES(227, 415), 	ES(327, 372), 	ES(314, 346), 	ES(423, 299), 
	ES(232, 369), 	ES(194, 401), 	ES(202, 435), 	ES(224, 420), 	ES(270, 392), 	ES(356, 362), 	ES(306, 364), 	ES(381, 343), 
};

EvalScore QUEEN_PSQT[] = {
	ES(423, 884), 	ES(385, 918), 	ES(406, 902), 	ES(454, 926), 	ES(436, 896), 	ES(389, 902), 	ES(473, 811), 	ES(461, 801), 
	ES(412, 914), 	ES(408, 908), 	ES(436, 906), 	ES(448, 931), 	ES(444, 932), 	ES(455, 856), 	ES(483, 763), 	ES(545, 699), 
	ES(392, 934), 	ES(401, 986), 	ES(386, 1023), 	ES(391, 1027), 	ES(394, 1034), 	ES(415, 1012), 	ES(450, 974), 	ES(460, 963), 
	ES(411, 965), 	ES(339, 1063), 	ES(341, 1083), 	ES(381, 1113), 	ES(372, 1108), 	ES(358, 1130), 	ES(417, 1085), 	ES(462, 1070), 
	ES(377, 981), 	ES(370, 1041), 	ES(349, 1098), 	ES(329, 1162), 	ES(332, 1220), 	ES(399, 1190), 	ES(430, 1165), 	ES(477, 1109), 
	ES(420, 965), 	ES(390, 1016), 	ES(347, 1146), 	ES(375, 1189), 	ES(402, 1237), 	ES(572, 1166), 	ES(609, 1049), 	ES(623, 1034), 
	ES(415, 938), 	ES(295, 1074), 	ES(298, 1206), 	ES(272, 1263), 	ES(280, 1341), 	ES(425, 1201), 	ES(398, 1118), 	ES(596, 1045), 
	ES(326, 1030), 	ES(267, 1115), 	ES(371, 1178), 	ES(469, 1125), 	ES(483, 1122), 	ES(523, 1094), 	ES(627, 923), 	ES(473, 1030), 
};

EvalScore KING_PSQT[] = {
	ES(307, -345), 	ES(286, -230), 	ES(200, -157), 	ES(-147, -102), 	ES(64, -180), 	ES(-65, -109), 	ES(208, -202), 	ES(337, -357), 
	ES(220, -179), 	ES(55, -76), 	ES(16, -36), 	ES(-102, 7), 	ES(-110, 17), 	ES(-52, -23), 	ES(111, -77), 	ES(158, -142), 
	ES(-76, -102), 	ES(-47, -22), 	ES(-247, 62), 	ES(-293, 94), 	ES(-277, 96), 	ES(-265, 63), 	ES(-105, 2), 	ES(-146, -48), 
	ES(-220, -72), 	ES(-279, 45), 	ES(-387, 128), 	ES(-494, 182), 	ES(-486, 178), 	ES(-354, 136), 	ES(-368, 87), 	ES(-418, 34), 
	ES(-236, -27), 	ES(-309, 96), 	ES(-355, 168), 	ES(-510, 204), 	ES(-474, 207), 	ES(-341, 184), 	ES(-339, 156), 	ES(-397, 63), 
	ES(-341, 9), 	ES(11, 81), 	ES(-221, 151), 	ES(-306, 187), 	ES(-159, 187), 	ES(107, 154), 	ES(28, 152), 	ES(-68, 43), 
	ES(-277, -42), 	ES(-143, 62), 	ES(-299, 109), 	ES(77, 43), 	ES(-105, 119), 	ES(-93, 158), 	ES(34, 120), 	ES(-17, 2), 
	ES(125, -383), 	ES(46, -183), 	ES(166, -153), 	ES(-301, 10), 	ES(-126, -56), 	ES(42, -47), 	ES(191, -75), 	ES(380, -434), 
};

EvalScore BISHOP_PAIR = ES(75, 210);

EvalScore KNIGHT_MOB[] = {
	ES(-56, 1),
	ES(-19, 1),
	ES(-10, 33),
	ES(-5, 26),
	ES(26, 11),
	ES(32, 13),
	ES(24, 15),
	ES(35, 17),
	ES(50, 26),
};

EvalScore BISHOP_MOB[] = {
	ES(-337, -23),
	ES(-311, -5),
	ES(-313, -25),
	ES(-254, -46),
	ES(-214, -49),
	ES(-169, -61),
	ES(-139, -35),
	ES(-113, -21),
	ES(-95, 4),
	ES(-71, 18),
	ES(-55, 15),
	ES(-27, 20),
	ES(-16, 29),
	ES(7, 18),
	ES(26, 41),
	ES(46, 58),
	ES(56, 79),
	ES(76, 106),
	ES(101, 110),
	ES(114, 131),
	ES(140, 136),
	ES(150, 166),
	ES(165, 164),
	ES(189, 196),
	ES(213, 194),
	ES(223, 223),
	ES(234, 232),
	ES(258, 255),
	ES(266, 319),
	ES(285, 315),
	ES(298, 324),
	ES(301, 329),
};

EvalScore ROOK_MOB[] = {
	ES(-441, -121),
	ES(-495, -94),
	ES(-201, -130),
	ES(-154, -115),
	ES(-64, -148),
	ES(45, -162),
	ES(43, -144),
	ES(0, -102),
	ES(-30, -67),
	ES(-54, -40),
	ES(-64, -29),
	ES(-45, -17),
	ES(-42, 7),
	ES(-33, 15),
	ES(-39, 24),
	ES(-27, 38),
	ES(-14, 44),
	ES(-3, 56),
	ES(16, 53),
	ES(14, 85),
	ES(25, 100),
	ES(44, 122),
	ES(58, 135),
	ES(74, 149),
	ES(98, 154),
	ES(107, 159),
	ES(140, 146),
	ES(161, 131),
	ES(175, 132),
	ES(206, 114),
	ES(226, 93),
	ES(267, 104),
};

EvalScore KING_MOB[] = {
	ES(0, 0),
	ES(1, 1),
	ES(2, 2),
	ES(3, 3),
	ES(-119, 73),
	ES(-89, 24),
	ES(24, 11),
	ES(60, -29),
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