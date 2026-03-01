#include "eval.hpp"

EvalScore MATERIAL_VALUES[] = {
	ES(231, 449),
	ES(887, 1125),
	ES(802, 1072),
	ES(1096, 1790),
	ES(1921, 2941),
};

EvalScore PAWN_PSQT[] = {
	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 
	ES(-72, 6), 	ES(-10, 20), 	ES(-30, -28), 	ES(-16, 8), 	ES(31, 17), 	ES(79, -39), 	ES(138, -31), 	ES(-20, -65), 
	ES(-85, -5), 	ES(-22, 7), 	ES(-10, -55), 	ES(11, -18), 	ES(58, -40), 	ES(27, -51), 	ES(100, -28), 	ES(4, -60), 
	ES(-101, 17), 	ES(-5, 18), 	ES(-5, -46), 	ES(49, -58), 	ES(63, -66), 	ES(38, -62), 	ES(44, -22), 	ES(-26, -46), 
	ES(-84, 109), 	ES(12, 74), 	ES(14, 5), 	ES(31, -20), 	ES(90, -60), 	ES(57, -40), 	ES(85, 23), 	ES(2, 25), 
	ES(-44, 370), 	ES(18, 401), 	ES(122, 286), 	ES(117, 205), 	ES(141, 179), 	ES(212, 125), 	ES(162, 285), 	ES(5, 268), 
	ES(176, 592), 	ES(292, 561), 	ES(215, 569), 	ES(298, 389), 	ES(244, 372), 	ES(194, 428), 	ES(-41, 573), 	ES(-143, 623), 
	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 
};

EvalScore KNIGHT_PSQT[] = {
	ES(-218, 25), 	ES(-9, 49), 	ES(-50, 90), 	ES(-5, 100), 	ES(7, 108), 	ES(42, 63), 	ES(5, 63), 	ES(-106, -19), 
	ES(-55, 75), 	ES(-30, 104), 	ES(27, 132), 	ES(101, 136), 	ES(96, 147), 	ES(96, 114), 	ES(41, 76), 	ES(37, 106), 
	ES(-34, 83), 	ES(38, 143), 	ES(102, 153), 	ES(130, 209), 	ES(178, 203), 	ES(131, 143), 	ES(112, 118), 	ES(31, 93), 
	ES(21, 146), 	ES(73, 167), 	ES(147, 230), 	ES(151, 225), 	ES(183, 242), 	ES(159, 208), 	ES(147, 171), 	ES(61, 108), 
	ES(65, 142), 	ES(111, 200), 	ES(185, 226), 	ES(274, 232), 	ES(205, 237), 	ES(287, 224), 	ES(157, 199), 	ES(188, 109), 
	ES(51, 101), 	ES(169, 146), 	ES(244, 197), 	ES(268, 192), 	ES(399, 137), 	ES(411, 127), 	ES(264, 110), 	ES(168, 63), 
	ES(14, 69), 	ES(65, 117), 	ES(150, 142), 	ES(199, 141), 	ES(147, 117), 	ES(357, 63), 	ES(73, 103), 	ES(158, 8), 
	ES(-433, -121), 	ES(-346, 91), 	ES(-147, 123), 	ES(-35, 99), 	ES(81, 110), 	ES(-112, 23), 	ES(-255, 110), 	ES(-258, -208), 
};

EvalScore BISHOP_PSQT[] = {
	ES(95, 139), 	ES(141, 172), 	ES(103, 144), 	ES(64, 159), 	ES(90, 164), 	ES(79, 184), 	ES(154, 118), 	ES(128, 95), 
	ES(131, 177), 	ES(119, 139), 	ES(130, 106), 	ES(67, 160), 	ES(92, 148), 	ES(140, 126), 	ES(175, 164), 	ES(132, 121), 
	ES(105, 180), 	ES(93, 171), 	ES(95, 164), 	ES(78, 161), 	ES(95, 173), 	ES(96, 162), 	ES(109, 145), 	ES(146, 140), 
	ES(66, 171), 	ES(58, 183), 	ES(47, 184), 	ES(129, 156), 	ES(117, 167), 	ES(59, 167), 	ES(51, 176), 	ES(110, 138), 
	ES(63, 184), 	ES(70, 187), 	ES(108, 157), 	ES(151, 188), 	ES(131, 149), 	ES(116, 177), 	ES(90, 171), 	ES(72, 187), 
	ES(78, 208), 	ES(129, 160), 	ES(102, 164), 	ES(153, 121), 	ES(114, 142), 	ES(249, 140), 	ES(200, 149), 	ES(193, 194), 
	ES(46, 133), 	ES(80, 147), 	ES(51, 153), 	ES(-3, 164), 	ES(98, 125), 	ES(73, 130), 	ES(76, 159), 	ES(81, 128), 
	ES(-4, 186), 	ES(-85, 203), 	ES(-65, 193), 	ES(-215, 228), 	ES(-153, 216), 	ES(-98, 174), 	ES(-2, 169), 	ES(-90, 170), 
};

EvalScore ROOK_PSQT[] = {
	ES(104, 338), 	ES(103, 326), 	ES(127, 343), 	ES(143, 340), 	ES(162, 307), 	ES(152, 315), 	ES(166, 283), 	ES(114, 292), 
	ES(22, 322), 	ES(39, 338), 	ES(95, 331), 	ES(91, 345), 	ES(94, 305), 	ES(116, 291), 	ES(165, 264), 	ES(83, 282), 
	ES(14, 342), 	ES(8, 343), 	ES(42, 336), 	ES(46, 342), 	ES(70, 326), 	ES(74, 296), 	ES(170, 243), 	ES(112, 251), 
	ES(15, 360), 	ES(4, 372), 	ES(34, 385), 	ES(64, 376), 	ES(57, 354), 	ES(33, 351), 	ES(103, 312), 	ES(81, 304), 
	ES(54, 386), 	ES(81, 377), 	ES(78, 411), 	ES(87, 389), 	ES(102, 349), 	ES(139, 326), 	ES(181, 312), 	ES(190, 296), 
	ES(74, 379), 	ES(155, 391), 	ES(124, 390), 	ES(137, 384), 	ES(238, 344), 	ES(257, 317), 	ES(428, 291), 	ES(352, 275), 
	ES(143, 386), 	ES(125, 425), 	ES(193, 436), 	ES(259, 400), 	ES(207, 401), 	ES(308, 365), 	ES(298, 335), 	ES(410, 297), 
	ES(213, 364), 	ES(166, 405), 	ES(173, 434), 	ES(180, 412), 	ES(228, 389), 	ES(310, 356), 	ES(295, 357), 	ES(361, 343), 
};

EvalScore QUEEN_PSQT[] = {
	ES(392, 930), 	ES(382, 932), 	ES(408, 926), 	ES(436, 972), 	ES(427, 916), 	ES(385, 914), 	ES(464, 842), 	ES(461, 819), 
	ES(413, 939), 	ES(400, 936), 	ES(429, 911), 	ES(445, 911), 	ES(432, 938), 	ES(468, 852), 	ES(481, 777), 	ES(552, 724), 
	ES(374, 960), 	ES(389, 984), 	ES(380, 1020), 	ES(380, 989), 	ES(389, 1009), 	ES(408, 1012), 	ES(447, 979), 	ES(439, 971), 
	ES(377, 993), 	ES(340, 1055), 	ES(344, 1047), 	ES(378, 1097), 	ES(373, 1083), 	ES(374, 1083), 	ES(403, 1068), 	ES(441, 1070), 
	ES(365, 1013), 	ES(356, 1036), 	ES(351, 1074), 	ES(358, 1131), 	ES(354, 1177), 	ES(407, 1150), 	ES(430, 1136), 	ES(468, 1112), 
	ES(414, 980), 	ES(383, 1012), 	ES(362, 1117), 	ES(397, 1146), 	ES(432, 1182), 	ES(580, 1126), 	ES(620, 1014), 	ES(630, 1033), 
	ES(409, 968), 	ES(323, 1069), 	ES(329, 1182), 	ES(297, 1246), 	ES(315, 1302), 	ES(441, 1166), 	ES(413, 1105), 	ES(581, 1084), 
	ES(351, 1035), 	ES(285, 1104), 	ES(345, 1165), 	ES(450, 1111), 	ES(464, 1112), 	ES(483, 1111), 	ES(633, 920), 	ES(474, 1039), 
};

EvalScore KING_PSQT[] = {
	ES(312, -354), 	ES(285, -240), 	ES(213, -173), 	ES(-134, -95), 	ES(67, -174), 	ES(-47, -109), 	ES(211, -206), 	ES(335, -367), 
	ES(209, -182), 	ES(61, -72), 	ES(4, -28), 	ES(-108, 3), 	ES(-125, 21), 	ES(-58, -17), 	ES(102, -74), 	ES(138, -148), 
	ES(-95, -111), 	ES(-44, -10), 	ES(-242, 64), 	ES(-289, 104), 	ES(-270, 108), 	ES(-264, 67), 	ES(-114, 6), 	ES(-153, -50), 
	ES(-228, -64), 	ES(-276, 45), 	ES(-385, 133), 	ES(-489, 185), 	ES(-487, 185), 	ES(-352, 136), 	ES(-370, 97), 	ES(-437, 28), 
	ES(-249, -27), 	ES(-301, 104), 	ES(-355, 171), 	ES(-504, 210), 	ES(-475, 212), 	ES(-347, 188), 	ES(-348, 155), 	ES(-425, 65), 
	ES(-355, 3), 	ES(18, 80), 	ES(-226, 148), 	ES(-295, 187), 	ES(-157, 183), 	ES(89, 155), 	ES(17, 155), 	ES(-104, 36), 
	ES(-287, -42), 	ES(-116, 62), 	ES(-262, 103), 	ES(93, 36), 	ES(-90, 115), 	ES(-74, 155), 	ES(31, 121), 	ES(-36, 6), 
	ES(213, -417), 	ES(82, -193), 	ES(205, -165), 	ES(-294, 5), 	ES(-131, -60), 	ES(35, -51), 	ES(199, -83), 	ES(496, -473), 
};

EvalScore BISHOP_PAIR = ES(39, 120);

EvalScore KNIGHT_MOB[] = {
	ES(-2, 31),
	ES(-19, 1),
	ES(-11, 9),
	ES(-14, -17),
	ES(18, 0),
	ES(-63, -92),
	ES(24, 6),
	ES(-5, 52),
	ES(29, 21),
};

EvalScore BISHOP_MOB[] = {
	ES(-301, -68),
	ES(-424, -168),
	ES(-317, -244),
	ES(-277, -144),
	ES(-218, -128),
	ES(-214, -98),
	ES(-164, -41),
	ES(-132, -23),
	ES(-115, 10),
	ES(-101, 18),
	ES(-72, 43),
	ES(-40, 26),
	ES(-5, 36),
	ES(19, 68),
	ES(43, 133),
	ES(74, 173),
	ES(93, 182),
	ES(102, 216),
	ES(128, 221),
	ES(139, 244),
	ES(166, 216),
	ES(155, 273),
	ES(238, 228),
	ES(213, 258),
	ES(330, 102),
	ES(150, 177),
	ES(235, 177),
	ES(258, 255),
	ES(266, 319),
	ES(285, 315),
	ES(298, 324),
	ES(301, 329),
};

EvalScore ROOK_MOB[] = {
	ES(-148, -204),
	ES(-495, -94),
	ES(-372, -165),
	ES(-307, -110),
	ES(-224, -126),
	ES(-192, -65),
	ES(-141, -54),
	ES(-116, -48),
	ES(-106, -38),
	ES(-86, -25),
	ES(-72, -9),
	ES(-45, -9),
	ES(-23, 3),
	ES(0, 13),
	ES(30, 17),
	ES(56, 23),
	ES(80, 39),
	ES(109, 54),
	ES(128, 59),
	ES(148, 75),
	ES(172, 75),
	ES(182, 101),
	ES(194, 108),
	ES(216, 96),
	ES(262, 84),
	ES(257, 98),
	ES(243, 136),
	ES(171, 137),
	ES(152, 116),
	ES(206, 114),
	ES(218, 81),
	ES(267, 103),
};

EvalScore QUEEN_MOB[] = {
	ES(-554, -188),
	ES(-495, -94),
	ES(-201, -130),
	ES(-183, -136),
	ES(-224, -444),
	ES(-77, -454),
	ES(-58, -404),
	ES(-70, -213),
	ES(-52, -154),
	ES(-50, -98),
	ES(-35, -74),
	ES(-22, -32),
	ES(-17, 0),
	ES(-9, 12),
	ES(-2, 28),
	ES(7, 61),
	ES(6, 82),
	ES(13, 106),
	ES(15, 130),
	ES(19, 148),
	ES(21, 176),
	ES(37, 174),
	ES(42, 188),
	ES(77, 186),
	ES(73, 179),
	ES(117, 179),
	ES(210, 135),
	ES(227, 161),
	ES(243, 182),
	ES(263, 188),
	ES(288, 188),
	ES(295, 195),
};

EvalScore KING_MOB[] = {
	ES(0, 0),
	ES(1, 1),
	ES(2, 2),
	ES(3, 3),
	ES(-111, 50),
	ES(-89, 24),
	ES(28, -1),
	ES(48, -8),
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
	int w_knight_mob = _mm_popcnt_u64(board.piece_control[WHITE_KNIGHT]);
	int b_knight_mob = _mm_popcnt_u64(board.piece_control[BLACK_KNIGHT]);
	mobility += KNIGHT_MOB[std::min(w_knight_mob, 8)] - KNIGHT_MOB[std::min(b_knight_mob, 8)];
	int w_bishop_mob = _mm_popcnt_u64(board.piece_control[WHITE_BISHOP]);
	int b_bishop_mob = _mm_popcnt_u64(board.piece_control[BLACK_BISHOP]);
	mobility += BISHOP_MOB[std::min(w_bishop_mob, 31)] - BISHOP_MOB[std::min(b_bishop_mob, 31)];
	int w_rook_mob = _mm_popcnt_u64(board.piece_control[WHITE_ROOK]);
	int b_rook_mob = _mm_popcnt_u64(board.piece_control[BLACK_ROOK]);
	mobility += ROOK_MOB[std::min(w_rook_mob, 31)] - ROOK_MOB[std::min(b_rook_mob, 31)];
	int w_queen_mob = _mm_popcnt_u64(board.piece_control[WHITE_QUEEN]);
	int b_queen_mob = _mm_popcnt_u64(board.piece_control[BLACK_QUEEN]);
	mobility += QUEEN_MOB[std::min(w_queen_mob, 31)] - QUEEN_MOB[std::min(b_queen_mob, 31)];
	int w_king_mob = _mm_popcnt_u64(board.piece_control[WHITE_KING]);
	int b_king_mob = _mm_popcnt_u64(board.piece_control[BLACK_KING]);
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

	std::vector<std::pair<double, double>> knight_mob_grads(9), bishop_mob_grads(32), rook_mob_grads(32), queen_mob_grads(32), king_mob_grads(8);
	
	int w_knight_mob = _mm_popcnt_u64(board.piece_control[WHITE_KNIGHT]);
	int b_knight_mob = _mm_popcnt_u64(board.piece_control[BLACK_KNIGHT]);
	knight_mob_grads[std::min(w_knight_mob, 8)].first += alpha, knight_mob_grads[std::min(w_knight_mob, 8)].second += beta;
	knight_mob_grads[std::min(b_knight_mob, 8)].first -= alpha, knight_mob_grads[std::min(b_knight_mob, 8)].second -= beta;
	int w_bishop_mob = _mm_popcnt_u64(board.piece_control[WHITE_BISHOP]);
	int b_bishop_mob = _mm_popcnt_u64(board.piece_control[BLACK_BISHOP]);
	bishop_mob_grads[std::min(w_bishop_mob, 31)].first += alpha, bishop_mob_grads[std::min(w_bishop_mob, 31)].second += beta;
	bishop_mob_grads[std::min(b_bishop_mob, 31)].first -= alpha, bishop_mob_grads[std::min(b_bishop_mob, 31)].second -= beta;
	int w_rook_mob = _mm_popcnt_u64(board.piece_control[WHITE_ROOK]);
	int b_rook_mob = _mm_popcnt_u64(board.piece_control[BLACK_ROOK]);
	rook_mob_grads[std::min(w_rook_mob, 31)].first += alpha, rook_mob_grads[std::min(w_rook_mob, 31)].second += beta;
	rook_mob_grads[std::min(b_rook_mob, 31)].first -= alpha, rook_mob_grads[std::min(b_rook_mob, 31)].second -= beta;
	int w_queen_mob = _mm_popcnt_u64(board.piece_control[WHITE_QUEEN]);
	int b_queen_mob = _mm_popcnt_u64(board.piece_control[BLACK_QUEEN]);
	queen_mob_grads[std::min(w_queen_mob, 31)].first += alpha, queen_mob_grads[std::min(w_queen_mob, 31)].second += beta;
	queen_mob_grads[std::min(b_queen_mob, 31)].first -= alpha, queen_mob_grads[std::min(b_queen_mob, 31)].second -= beta;
	int w_king_mob = _mm_popcnt_u64(board.piece_control[WHITE_KING]);
	int b_king_mob = _mm_popcnt_u64(board.piece_control[BLACK_KING]);
	king_mob_grads[std::min(w_king_mob, 7)].first += alpha, king_mob_grads[std::min(w_king_mob, 7)].second += beta;
	king_mob_grads[std::min(b_king_mob, 7)].first -= alpha, king_mob_grads[std::min(b_king_mob, 7)].second -= beta;

	grads.insert(grads.end(), knight_mob_grads.begin(), knight_mob_grads.end());
	grads.insert(grads.end(), bishop_mob_grads.begin(), bishop_mob_grads.end());
	grads.insert(grads.end(), rook_mob_grads.begin(), rook_mob_grads.end());
	grads.insert(grads.end(), queen_mob_grads.begin(), queen_mob_grads.end());
	grads.insert(grads.end(), king_mob_grads.begin(), king_mob_grads.end());

	return grads;
}