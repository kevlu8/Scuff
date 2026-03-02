#include "eval.hpp"

EvalScore MATERIAL_VALUES[] = {
	ES(216, 445),
	ES(850, 1107),
	ES(840, 1075),
	ES(1082, 1711),
	ES(2279, 3073),
};

EvalScore PAWN_PSQT[] = {
	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 
	ES(-86, 9), 	ES(-11, 22), 	ES(-17, -33), 	ES(-41, -8), 	ES(22, 15), 	ES(78, -32), 	ES(143, -26), 	ES(-16, -62), 
	ES(-92, -2), 	ES(-14, 9), 	ES(-14, -56), 	ES(0, -12), 	ES(50, -35), 	ES(13, -52), 	ES(105, -30), 	ES(4, -59), 
	ES(-93, 18), 	ES(-16, 17), 	ES(-6, -51), 	ES(44, -66), 	ES(51, -64), 	ES(23, -69), 	ES(41, -19), 	ES(-24, -42), 
	ES(-68, 111), 	ES(12, 73), 	ES(9, 7), 	ES(28, -24), 	ES(88, -52), 	ES(73, -44), 	ES(81, 27), 	ES(14, 21), 
	ES(-22, 368), 	ES(8, 395), 	ES(118, 278), 	ES(128, 207), 	ES(131, 175), 	ES(212, 125), 	ES(155, 280), 	ES(13, 274), 
	ES(223, 572), 	ES(301, 548), 	ES(212, 553), 	ES(307, 372), 	ES(245, 368), 	ES(199, 411), 	ES(-41, 564), 	ES(-104, 609), 
	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 
};

EvalScore KNIGHT_PSQT[] = {
	ES(-200, 9), 	ES(-11, -2), 	ES(-49, 79), 	ES(7, 96), 	ES(15, 100), 	ES(55, 53), 	ES(-2, 15), 	ES(-102, -42), 
	ES(-45, 43), 	ES(-11, 104), 	ES(52, 128), 	ES(96, 149), 	ES(101, 137), 	ES(112, 123), 	ES(54, 65), 	ES(41, 75), 
	ES(-13, 77), 	ES(56, 138), 	ES(115, 155), 	ES(120, 209), 	ES(162, 204), 	ES(124, 145), 	ES(129, 124), 	ES(46, 82), 
	ES(37, 144), 	ES(80, 162), 	ES(123, 231), 	ES(142, 233), 	ES(170, 253), 	ES(151, 209), 	ES(153, 177), 	ES(74, 104), 
	ES(74, 141), 	ES(98, 203), 	ES(161, 232), 	ES(244, 249), 	ES(173, 264), 	ES(250, 241), 	ES(127, 221), 	ES(180, 117), 
	ES(65, 98), 	ES(151, 146), 	ES(197, 201), 	ES(216, 210), 	ES(340, 164), 	ES(368, 130), 	ES(228, 120), 	ES(157, 58), 
	ES(24, 28), 	ES(80, 115), 	ES(148, 144), 	ES(170, 150), 	ES(128, 120), 	ES(342, 69), 	ES(75, 100), 	ES(164, -21), 
	ES(-422, -144), 	ES(-328, 51), 	ES(-120, 111), 	ES(-13, 89), 	ES(98, 101), 	ES(-96, 16), 	ES(-247, 77), 	ES(-236, -229), 
};

EvalScore BISHOP_PSQT[] = {
	ES(48, 93), 	ES(130, 150), 	ES(59, 89), 	ES(41, 146), 	ES(54, 133), 	ES(40, 141), 	ES(133, 93), 	ES(101, 44), 
	ES(112, 147), 	ES(104, 129), 	ES(146, 119), 	ES(71, 167), 	ES(101, 165), 	ES(143, 133), 	ES(162, 146), 	ES(125, 86), 
	ES(80, 162), 	ES(110, 178), 	ES(109, 193), 	ES(117, 186), 	ES(111, 202), 	ES(112, 186), 	ES(107, 154), 	ES(139, 125), 
	ES(61, 149), 	ES(55, 206), 	ES(82, 213), 	ES(149, 200), 	ES(149, 195), 	ES(86, 189), 	ES(88, 188), 	ES(89, 127), 
	ES(60, 176), 	ES(103, 199), 	ES(133, 186), 	ES(182, 232), 	ES(162, 195), 	ES(171, 208), 	ES(100, 197), 	ES(70, 177), 
	ES(91, 187), 	ES(143, 161), 	ES(136, 178), 	ES(184, 155), 	ES(156, 171), 	ES(280, 169), 	ES(223, 161), 	ES(179, 182), 
	ES(58, 101), 	ES(118, 137), 	ES(83, 160), 	ES(40, 168), 	ES(101, 143), 	ES(129, 145), 	ES(98, 162), 	ES(112, 92), 
	ES(5, 151), 	ES(-84, 187), 	ES(-54, 179), 	ES(-218, 218), 	ES(-159, 202), 	ES(-92, 170), 	ES(0, 154), 	ES(-97, 135), 
};

EvalScore ROOK_PSQT[] = {
	ES(75, 283), 	ES(73, 299), 	ES(101, 323), 	ES(121, 317), 	ES(134, 289), 	ES(114, 294), 	ES(150, 273), 	ES(77, 256), 
	ES(-3, 290), 	ES(31, 304), 	ES(86, 305), 	ES(76, 315), 	ES(94, 286), 	ES(101, 270), 	ES(157, 245), 	ES(56, 261), 
	ES(8, 321), 	ES(26, 322), 	ES(64, 313), 	ES(50, 324), 	ES(81, 316), 	ES(70, 293), 	ES(182, 238), 	ES(99, 226), 
	ES(19, 343), 	ES(16, 346), 	ES(54, 359), 	ES(90, 354), 	ES(97, 346), 	ES(40, 346), 	ES(128, 314), 	ES(102, 286), 
	ES(64, 373), 	ES(104, 350), 	ES(118, 402), 	ES(127, 382), 	ES(160, 344), 	ES(157, 319), 	ES(211, 317), 	ES(201, 284), 
	ES(88, 364), 	ES(173, 375), 	ES(168, 387), 	ES(174, 382), 	ES(268, 330), 	ES(286, 323), 	ES(426, 289), 	ES(354, 273), 
	ES(145, 370), 	ES(142, 412), 	ES(194, 426), 	ES(268, 391), 	ES(226, 407), 	ES(317, 357), 	ES(309, 336), 	ES(415, 286), 
	ES(218, 353), 	ES(184, 383), 	ES(198, 422), 	ES(218, 395), 	ES(266, 378), 	ES(337, 344), 	ES(298, 354), 	ES(370, 329), 
};

EvalScore QUEEN_PSQT[] = {
	ES(430, 886), 	ES(388, 924), 	ES(412, 913), 	ES(451, 928), 	ES(437, 899), 	ES(395, 909), 	ES(479, 814), 	ES(470, 795), 
	ES(420, 921), 	ES(409, 913), 	ES(439, 904), 	ES(447, 936), 	ES(444, 937), 	ES(465, 867), 	ES(497, 777), 	ES(541, 697), 
	ES(394, 940), 	ES(401, 989), 	ES(395, 1031), 	ES(386, 1026), 	ES(390, 1034), 	ES(417, 1017), 	ES(452, 981), 	ES(454, 964), 
	ES(413, 968), 	ES(342, 1068), 	ES(345, 1087), 	ES(383, 1116), 	ES(374, 1113), 	ES(359, 1132), 	ES(414, 1084), 	ES(454, 1068), 
	ES(382, 983), 	ES(369, 1039), 	ES(347, 1097), 	ES(335, 1171), 	ES(333, 1228), 	ES(405, 1198), 	ES(432, 1168), 	ES(476, 1110), 
	ES(427, 970), 	ES(389, 1016), 	ES(356, 1156), 	ES(373, 1190), 	ES(402, 1239), 	ES(571, 1172), 	ES(607, 1048), 	ES(627, 1038), 
	ES(424, 943), 	ES(298, 1076), 	ES(299, 1210), 	ES(273, 1268), 	ES(285, 1349), 	ES(426, 1200), 	ES(399, 1120), 	ES(602, 1050), 
	ES(325, 1031), 	ES(268, 1124), 	ES(361, 1177), 	ES(462, 1135), 	ES(483, 1138), 	ES(518, 1107), 	ES(630, 926), 	ES(477, 1029), 
};

EvalScore KING_PSQT[] = {
	ES(301, -347), 	ES(290, -230), 	ES(194, -159), 	ES(-148, -101), 	ES(64, -178), 	ES(-64, -111), 	ES(209, -198), 	ES(330, -359), 
	ES(223, -179), 	ES(48, -76), 	ES(11, -30), 	ES(-108, 3), 	ES(-110, 17), 	ES(-56, -20), 	ES(113, -82), 	ES(152, -148), 
	ES(-79, -105), 	ES(-48, -17), 	ES(-248, 60), 	ES(-295, 99), 	ES(-271, 100), 	ES(-266, 69), 	ES(-107, 3), 	ES(-148, -51), 
	ES(-223, -75), 	ES(-282, 42), 	ES(-384, 129), 	ES(-489, 183), 	ES(-487, 181), 	ES(-356, 138), 	ES(-368, 91), 	ES(-423, 31), 
	ES(-232, -27), 	ES(-299, 104), 	ES(-352, 163), 	ES(-504, 214), 	ES(-477, 204), 	ES(-338, 189), 	ES(-340, 154), 	ES(-401, 56), 
	ES(-335, 13), 	ES(17, 79), 	ES(-219, 150), 	ES(-299, 192), 	ES(-161, 181), 	ES(108, 148), 	ES(32, 155), 	ES(-70, 37), 
	ES(-273, -42), 	ES(-130, 68), 	ES(-290, 106), 	ES(79, 44), 	ES(-105, 118), 	ES(-90, 157), 	ES(40, 121), 	ES(-13, -2), 
	ES(191, -397), 	ES(75, -190), 	ES(195, -163), 	ES(-298, 11), 	ES(-117, -54), 	ES(50, -46), 	ES(211, -78), 	ES(467, -454), 
};

EvalScore BISHOP_PAIR = ES(81, 211);

EvalScore KNIGHT_MOB[] = {
	ES(-56, 0),
	ES(-15, -2),
	ES(-8, 33),
	ES(-2, 36),
	ES(21, 13),
	ES(33, 8),
	ES(24, 12),
	ES(44, 21),
	ES(49, 24),
};

EvalScore BISHOP_MOB[] = {
	ES(-345, -21),
	ES(-316, -4),
	ES(-318, -25),
	ES(-261, -45),
	ES(-216, -43),
	ES(-172, -59),
	ES(-139, -30),
	ES(-113, -15),
	ES(-97, 4),
	ES(-73, 21),
	ES(-55, 15),
	ES(-32, 15),
	ES(-20, 31),
	ES(6, 23),
	ES(20, 40),
	ES(49, 55),
	ES(66, 87),
	ES(80, 109),
	ES(100, 110),
	ES(109, 124),
	ES(144, 134),
	ES(153, 163),
	ES(173, 165),
	ES(186, 187),
	ES(216, 190),
	ES(225, 222),
	ES(234, 222),
	ES(258, 251),
	ES(265, 307),
	ES(289, 305),
	ES(297, 319),
	ES(307, 329),
};

EvalScore ROOK_MOB[] = {
	ES(-619, -90),
	ES(-673, -56),
	ES(-214, -131),
	ES(-154, -127),
	ES(-56, -152),
	ES(49, -172),
	ES(54, -150),
	ES(7, -108),
	ES(-26, -72),
	ES(-50, -37),
	ES(-54, -26),
	ES(-51, -16),
	ES(-44, -1),
	ES(-38, 7),
	ES(-35, 30),
	ES(-28, 29),
	ES(-7, 45),
	ES(-1, 46),
	ES(14, 56),
	ES(19, 80),
	ES(25, 102),
	ES(41, 113),
	ES(59, 132),
	ES(75, 148),
	ES(97, 151),
	ES(111, 166),
	ES(135, 142),
	ES(161, 138),
	ES(175, 138),
	ES(211, 122),
	ES(228, 100),
	ES(267, 118),
};

EvalScore KING_MOB[] = {
	ES(0, 0),
	ES(1, 1),
	ES(2, 2),
	ES(3, 3),
	ES(-126, 70),
	ES(-93, 24),
	ES(21, 6),
	ES(66, -22),
};

EvalScore ROOK_PAWN_BONUS[] = {
	ES(154, 90), 	ES(83, -15), 	ES(147, 117), 	ES(85, 134), 	ES(131, 111), 	ES(91, 152), 	ES(79, 160), 	ES(43, 187), 	ES(8, 186), 	ES(-25, 204), 	ES(-62, 183), 	ES(19, 128), 	ES(98, 76), 	ES(301, -52), 	ES(387, 12), 	ES(694, -197), 	ES(320, 320), 
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

	EvalScore rook_pawn_bonus = 0;
	int pawn_cnt = _mm_popcnt_u64(board.piece_boards[PAWN]);
	rook_pawn_bonus += ROOK_PAWN_BONUS[16 - pawn_cnt] * _mm_popcnt_u64(board.piece_boards[OCC(WHITE)] & board.piece_boards[ROOK]);
	rook_pawn_bonus -= ROOK_PAWN_BONUS[16 - pawn_cnt] * _mm_popcnt_u64(board.piece_boards[OCC(BLACK)] & board.piece_boards[ROOK]);

	EvalScore final_eval = material + psqt + bishop_pair + mobility + rook_pawn_bonus;

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

	std::vector<std::pair<double, double>> rook_pawn_bonus_grads(17);
	int pawn_cnt = _mm_popcnt_u64(board.piece_boards[PAWN]);
	rook_pawn_bonus_grads[16 - pawn_cnt].first += alpha * _mm_popcnt_u64(board.piece_boards[OCC(WHITE)] & board.piece_boards[ROOK]);
	rook_pawn_bonus_grads[16 - pawn_cnt].first -= alpha * _mm_popcnt_u64(board.piece_boards[OCC(BLACK)] & board.piece_boards[ROOK]);
	rook_pawn_bonus_grads[16 - pawn_cnt].second += beta * _mm_popcnt_u64(board.piece_boards[OCC(WHITE)] & board.piece_boards[ROOK]);
	rook_pawn_bonus_grads[16 - pawn_cnt].second -= beta * _mm_popcnt_u64(board.piece_boards[OCC(BLACK)] & board.piece_boards[ROOK]);
	grads.insert(grads.end(), rook_pawn_bonus_grads.begin(), rook_pawn_bonus_grads.end());

	return grads;
}