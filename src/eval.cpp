#include "eval.hpp"

EvalScore MATERIAL_VALUES[] = {
	ES(202, 452),
	ES(867, 1105),
	ES(853, 1081),
	ES(1182, 1832),
	ES(2314, 3097),
};

EvalScore PAWN_PSQT[] = {
	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 
	ES(-75, -5), 	ES(-34, 30), 	ES(-9, -34), 	ES(-40, 0), 	ES(19, 25), 	ES(85, -47), 	ES(91, -22), 	ES(-4, -74), 
	ES(-80, -14), 	ES(-34, 13), 	ES(-7, -55), 	ES(4, -10), 	ES(49, -27), 	ES(21, -70), 	ES(58, -18), 	ES(19, -74), 
	ES(-80, 11), 	ES(-37, 28), 	ES(2, -52), 	ES(57, -49), 	ES(54, -55), 	ES(33, -81), 	ES(-4, -1), 	ES(-3, -59), 
	ES(-55, 96), 	ES(-8, 90), 	ES(20, 3), 	ES(36, -9), 	ES(92, -42), 	ES(88, -59), 	ES(38, 37), 	ES(33, 4), 
	ES(-6, 347), 	ES(1, 410), 	ES(137, 284), 	ES(146, 227), 	ES(144, 198), 	ES(226, 113), 	ES(132, 307), 	ES(42, 259), 
	ES(256, 559), 	ES(305, 561), 	ES(237, 563), 	ES(338, 407), 	ES(260, 409), 	ES(207, 412), 	ES(-65, 596), 	ES(-57, 595), 
	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 
};

EvalScore KNIGHT_PSQT[] = {
	ES(-199, 6), 	ES(-14, -9), 	ES(-45, 77), 	ES(5, 90), 	ES(21, 96), 	ES(65, 49), 	ES(-4, 12), 	ES(-96, -46), 
	ES(-48, 37), 	ES(-7, 101), 	ES(53, 129), 	ES(98, 143), 	ES(105, 142), 	ES(104, 114), 	ES(54, 67), 	ES(48, 74), 
	ES(-5, 84), 	ES(59, 141), 	ES(115, 155), 	ES(124, 207), 	ES(168, 212), 	ES(127, 151), 	ES(134, 129), 	ES(49, 83), 
	ES(40, 140), 	ES(83, 158), 	ES(126, 231), 	ES(141, 232), 	ES(166, 243), 	ES(154, 215), 	ES(149, 169), 	ES(82, 112), 
	ES(72, 134), 	ES(98, 204), 	ES(165, 229), 	ES(245, 243), 	ES(169, 255), 	ES(250, 236), 	ES(126, 216), 	ES(186, 117), 
	ES(65, 96), 	ES(156, 148), 	ES(190, 199), 	ES(222, 213), 	ES(342, 164), 	ES(375, 131), 	ES(226, 123), 	ES(164, 56), 
	ES(21, 24), 	ES(61, 116), 	ES(136, 142), 	ES(176, 153), 	ES(122, 123), 	ES(333, 69), 	ES(53, 100), 	ES(159, -28), 
	ES(-432, -147), 	ES(-333, 52), 	ES(-123, 111), 	ES(-22, 93), 	ES(101, 104), 	ES(-99, 20), 	ES(-260, 78), 	ES(-257, -228), 
};

EvalScore BISHOP_PSQT[] = {
	ES(50, 93), 	ES(136, 144), 	ES(62, 92), 	ES(39, 142), 	ES(63, 134), 	ES(45, 141), 	ES(131, 86), 	ES(103, 42), 
	ES(122, 153), 	ES(98, 121), 	ES(156, 120), 	ES(71, 166), 	ES(99, 163), 	ES(151, 131), 	ES(163, 148), 	ES(124, 84), 
	ES(79, 155), 	ES(114, 177), 	ES(107, 184), 	ES(127, 189), 	ES(117, 206), 	ES(117, 184), 	ES(104, 141), 	ES(135, 123), 
	ES(68, 153), 	ES(57, 204), 	ES(98, 219), 	ES(153, 198), 	ES(151, 192), 	ES(88, 191), 	ES(81, 183), 	ES(89, 124), 
	ES(59, 172), 	ES(105, 193), 	ES(128, 188), 	ES(177, 227), 	ES(161, 197), 	ES(163, 201), 	ES(104, 184), 	ES(71, 179), 
	ES(99, 183), 	ES(148, 159), 	ES(136, 180), 	ES(179, 149), 	ES(158, 169), 	ES(282, 172), 	ES(222, 157), 	ES(182, 176), 
	ES(51, 94), 	ES(101, 144), 	ES(74, 156), 	ES(32, 170), 	ES(96, 139), 	ES(125, 144), 	ES(68, 164), 	ES(105, 91), 
	ES(-3, 157), 	ES(-88, 178), 	ES(-55, 179), 	ES(-217, 216), 	ES(-156, 209), 	ES(-102, 162), 	ES(-7, 162), 	ES(-112, 136), 
};

EvalScore ROOK_PSQT[] = {
	ES(80, 305), 	ES(87, 318), 	ES(112, 346), 	ES(131, 335), 	ES(145, 314), 	ES(122, 312), 	ES(167, 291), 	ES(85, 269), 
	ES(6, 310), 	ES(38, 319), 	ES(95, 324), 	ES(84, 334), 	ES(101, 299), 	ES(119, 297), 	ES(174, 264), 	ES(62, 280), 
	ES(8, 336), 	ES(33, 331), 	ES(68, 335), 	ES(70, 348), 	ES(98, 339), 	ES(78, 311), 	ES(188, 254), 	ES(110, 252), 
	ES(32, 362), 	ES(32, 375), 	ES(66, 379), 	ES(101, 376), 	ES(98, 362), 	ES(47, 368), 	ES(137, 321), 	ES(105, 303), 
	ES(73, 388), 	ES(125, 384), 	ES(122, 414), 	ES(137, 403), 	ES(159, 358), 	ES(166, 340), 	ES(225, 331), 	ES(217, 313), 
	ES(114, 387), 	ES(185, 392), 	ES(172, 397), 	ES(185, 401), 	ES(288, 362), 	ES(293, 332), 	ES(448, 305), 	ES(364, 275), 
	ES(154, 390), 	ES(145, 435), 	ES(203, 444), 	ES(274, 414), 	ES(227, 416), 	ES(323, 368), 	ES(307, 358), 	ES(424, 302), 
	ES(229, 374), 	ES(190, 404), 	ES(206, 434), 	ES(224, 419), 	ES(274, 400), 	ES(342, 361), 	ES(288, 379), 	ES(371, 344), 
};

EvalScore QUEEN_PSQT[] = {
	ES(421, 877), 	ES(377, 903), 	ES(415, 906), 	ES(452, 920), 	ES(436, 891), 	ES(391, 894), 	ES(480, 805), 	ES(465, 785), 
	ES(406, 904), 	ES(413, 911), 	ES(447, 902), 	ES(443, 929), 	ES(448, 931), 	ES(463, 854), 	ES(499, 763), 	ES(542, 685), 
	ES(393, 925), 	ES(404, 985), 	ES(388, 1024), 	ES(378, 1016), 	ES(394, 1036), 	ES(419, 1013), 	ES(449, 968), 	ES(454, 950), 
	ES(407, 960), 	ES(351, 1068), 	ES(335, 1082), 	ES(384, 1124), 	ES(372, 1116), 	ES(355, 1124), 	ES(419, 1081), 	ES(453, 1066), 
	ES(383, 986), 	ES(372, 1041), 	ES(347, 1100), 	ES(338, 1182), 	ES(336, 1234), 	ES(397, 1196), 	ES(434, 1166), 	ES(468, 1102), 
	ES(424, 967), 	ES(389, 1021), 	ES(339, 1155), 	ES(374, 1193), 	ES(402, 1242), 	ES(562, 1170), 	ES(609, 1040), 	ES(640, 1037), 
	ES(423, 940), 	ES(280, 1088), 	ES(294, 1209), 	ES(262, 1278), 	ES(277, 1347), 	ES(423, 1198), 	ES(378, 1130), 	ES(614, 1039), 
	ES(320, 1031), 	ES(262, 1115), 	ES(349, 1175), 	ES(464, 1131), 	ES(481, 1126), 	ES(510, 1108), 	ES(635, 924), 	ES(466, 1033), 
};

EvalScore KING_PSQT[] = {
	ES(315, -353), 	ES(279, -239), 	ES(198, -171), 	ES(-150, -103), 	ES(64, -179), 	ES(-64, -102), 	ES(206, -197), 	ES(336, -365), 
	ES(222, -181), 	ES(56, -77), 	ES(12, -35), 	ES(-102, 3), 	ES(-116, 17), 	ES(-51, -21), 	ES(109, -76), 	ES(153, -149), 
	ES(-81, -107), 	ES(-44, -20), 	ES(-250, 58), 	ES(-299, 100), 	ES(-280, 99), 	ES(-262, 72), 	ES(-103, 2), 	ES(-150, -46), 
	ES(-222, -68), 	ES(-286, 46), 	ES(-386, 131), 	ES(-486, 187), 	ES(-489, 177), 	ES(-356, 135), 	ES(-364, 94), 	ES(-427, 27), 
	ES(-237, -33), 	ES(-297, 110), 	ES(-363, 167), 	ES(-510, 206), 	ES(-472, 215), 	ES(-337, 192), 	ES(-330, 159), 	ES(-390, 56), 
	ES(-335, 0), 	ES(3, 79), 	ES(-236, 149), 	ES(-299, 193), 	ES(-156, 188), 	ES(117, 167), 	ES(42, 153), 	ES(-56, 33), 
	ES(-277, -44), 	ES(-144, 67), 	ES(-314, 115), 	ES(71, 49), 	ES(-103, 123), 	ES(-97, 159), 	ES(25, 125), 	ES(-6, -2), 
	ES(250, -417), 	ES(82, -185), 	ES(206, -159), 	ES(-302, 16), 	ES(-115, -48), 	ES(74, -46), 	ES(221, -76), 	ES(577, -470), 
};

EvalScore BISHOP_PAIR = ES(78, 208);

EvalScore KNIGHT_MOB[] = {
	ES(-54, 6),
	ES(-14, 3),
	ES(-8, 34),
	ES(-7, 32),
	ES(23, 11),
	ES(30, 6),
	ES(24, 13),
	ES(38, 20),
	ES(50, 25),
};

EvalScore BISHOP_MOB[] = {
	ES(-336, -20),
	ES(-315, -8),
	ES(-310, -21),
	ES(-255, -46),
	ES(-208, -35),
	ES(-162, -44),
	ES(-137, -26),
	ES(-111, -15),
	ES(-96, 8),
	ES(-64, 26),
	ES(-51, 18),
	ES(-30, 19),
	ES(-12, 25),
	ES(8, 22),
	ES(22, 35),
	ES(46, 52),
	ES(59, 79),
	ES(78, 101),
	ES(99, 99),
	ES(110, 120),
	ES(138, 126),
	ES(154, 159),
	ES(169, 160),
	ES(184, 185),
	ES(212, 186),
	ES(213, 209),
	ES(233, 220),
	ES(266, 247),
	ES(251, 293),
	ES(283, 299),
	ES(291, 310),
	ES(306, 311),
};

EvalScore ROOK_MOB[] = {
	ES(-825, -51),
	ES(-882, -19),
	ES(-224, -131),
	ES(-169, -117),
	ES(-76, -153),
	ES(41, -170),
	ES(37, -156),
	ES(2, -105),
	ES(-27, -59),
	ES(-57, -42),
	ES(-54, -31),
	ES(-47, -14),
	ES(-42, 3),
	ES(-44, 8),
	ES(-39, 23),
	ES(-25, 33),
	ES(-11, 51),
	ES(1, 49),
	ES(11, 60),
	ES(15, 79),
	ES(29, 106),
	ES(46, 117),
	ES(60, 139),
	ES(77, 143),
	ES(98, 143),
	ES(116, 159),
	ES(142, 139),
	ES(162, 130),
	ES(179, 122),
	ES(218, 112),
	ES(235, 87),
	ES(280, 97),
};

EvalScore KING_MOB[] = {
	ES(0, 0),
	ES(1, 1),
	ES(2, 2),
	ES(3, 3),
	ES(-126, 72),
	ES(-96, 20),
	ES(26, 7),
	ES(60, -26),
};

EvalScore ISO_PAWN[] = {
	ES(-33, 10), 	ES(-47, -23), 	ES(-98, -13), 	ES(-74, -60), 	ES(-89, -63), 	ES(-76, -8), 	ES(-74, -24), 	ES(-83, 16), 
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

	EvalScore iso_pawn = 0;
	Bitboard mask = FileABits;
	for (int f = 0; f < 8; f++) {
		if (board.piece_boards[OCC(WHITE)] & board.piece_boards[PAWN] & mask) {
			bool left_isolated = f > 0 && !(board.piece_boards[OCC(WHITE)] & board.piece_boards[PAWN] & (mask >> 1));
			bool right_isolated = f < 7 && !(board.piece_boards[OCC(WHITE)] & board.piece_boards[PAWN] & (mask << 1));
			if ((f == 0 || left_isolated) && (f == 7 || right_isolated))
				iso_pawn += ISO_PAWN[f];
		}

		if (board.piece_boards[OCC(BLACK)] & board.piece_boards[PAWN] & mask) {
			bool left_isolated = f > 0 && !(board.piece_boards[OCC(BLACK)] & board.piece_boards[PAWN] & (mask >> 1));
			bool right_isolated = f < 7 && !(board.piece_boards[OCC(BLACK)] & board.piece_boards[PAWN] & (mask << 1));
			if ((f == 0 || left_isolated) && (f == 7 || right_isolated))
				iso_pawn -= ISO_PAWN[f];
		}

		mask <<= 1;
	}

	EvalScore final_eval = material + psqt + bishop_pair + mobility + iso_pawn;

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

	std::vector<std::pair<double, double>> iso_pawn_grads(8);
	Bitboard mask = FileABits;
	for (int f = 0; f < 8; f++) {
		if (board.piece_boards[OCC(WHITE)] & board.piece_boards[PAWN] & mask) {
			bool left_isolated = f > 0 && !(board.piece_boards[OCC(WHITE)] & board.piece_boards[PAWN] & (mask >> 1));
			bool right_isolated = f < 7 && !(board.piece_boards[OCC(WHITE)] & board.piece_boards[PAWN] & (mask << 1));
			if ((f == 0 || left_isolated) && (f == 7 || right_isolated))
				iso_pawn_grads[f] = {iso_pawn_grads[f].first + alpha, iso_pawn_grads[f].second + beta};
		}

		if (board.piece_boards[OCC(BLACK)] & board.piece_boards[PAWN] & mask) {
			bool left_isolated = f > 0 && !(board.piece_boards[OCC(BLACK)] & board.piece_boards[PAWN] & (mask >> 1));
			bool right_isolated = f < 7 && !(board.piece_boards[OCC(BLACK)] & board.piece_boards[PAWN] & (mask << 1));
			if ((f == 0 || left_isolated) && (f == 7 || right_isolated))
				iso_pawn_grads[f] = {iso_pawn_grads[f].first - alpha, iso_pawn_grads[f].second - beta};
		}

		mask <<= 1;
	}
	grads.insert(grads.end(), iso_pawn_grads.begin(), iso_pawn_grads.end());

	return grads;
}