#include "eval.hpp"

EvalScore MATERIAL_VALUES[] = {
	ES(205, 453),
	ES(889, 1109),
	ES(927, 1122),
	ES(1208, 1935),
	ES(2408, 3272),
};

EvalScore PAWN_PSQT[] = {
	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 
	ES(-98, 4), 	ES(-34, 32), 	ES(-22, -26), 	ES(-64, 11), 	ES(-2, 25), 	ES(58, -44), 	ES(91, -17), 	ES(-15, -68), 
	ES(-99, -13), 	ES(-31, 10), 	ES(-13, -55), 	ES(-11, -4), 	ES(36, -23), 	ES(13, -58), 	ES(65, -17), 	ES(15, -74), 
	ES(-96, 7), 	ES(-19, 21), 	ES(-1, -48), 	ES(59, -47), 	ES(51, -52), 	ES(24, -77), 	ES(12, -6), 	ES(-6, -60), 
	ES(-56, 98), 	ES(14, 86), 	ES(41, -1), 	ES(48, -8), 	ES(123, -44), 	ES(99, -63), 	ES(61, 36), 	ES(31, 5), 
	ES(4, 346), 	ES(39, 405), 	ES(168, 275), 	ES(192, 220), 	ES(195, 186), 	ES(280, 99), 	ES(174, 296), 	ES(75, 262), 
	ES(294, 561), 	ES(364, 558), 	ES(292, 557), 	ES(399, 405), 	ES(327, 394), 	ES(264, 396), 	ES(1, 577), 	ES(-26, 600), 
	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 	ES(0, 0), 
};

EvalScore KNIGHT_PSQT[] = {
	ES(-224, 20), 	ES(-43, -22), 	ES(-87, 80), 	ES(-31, 91), 	ES(-17, 99), 	ES(20, 52), 	ES(-34, 1), 	ES(-122, -29), 
	ES(-73, 45), 	ES(-33, 97), 	ES(25, 133), 	ES(63, 147), 	ES(63, 145), 	ES(76, 125), 	ES(26, 63), 	ES(17, 78), 
	ES(-35, 83), 	ES(50, 147), 	ES(96, 182), 	ES(106, 230), 	ES(153, 227), 	ES(113, 171), 	ES(126, 129), 	ES(29, 85), 
	ES(43, 139), 	ES(92, 163), 	ES(137, 240), 	ES(149, 250), 	ES(183, 263), 	ES(158, 220), 	ES(158, 169), 	ES(73, 104), 
	ES(85, 132), 	ES(129, 203), 	ES(215, 234), 	ES(290, 243), 	ES(232, 250), 	ES(311, 229), 	ES(167, 198), 	ES(200, 97), 
	ES(93, 83), 	ES(217, 141), 	ES(279, 201), 	ES(322, 204), 	ES(444, 139), 	ES(452, 121), 	ES(299, 97), 	ES(190, 43), 
	ES(39, 26), 	ES(91, 102), 	ES(192, 133), 	ES(256, 134), 	ES(197, 106), 	ES(404, 45), 	ES(85, 95), 	ES(176, -29), 
	ES(-429, -160), 	ES(-308, 57), 	ES(-80, 104), 	ES(32, 74), 	ES(146, 84), 	ES(-54, 2), 	ES(-247, 74), 	ES(-235, -239), 
};

EvalScore BISHOP_PSQT[] = {
	ES(12, 66), 	ES(88, 123), 	ES(32, 57), 	ES(6, 132), 	ES(15, 115), 	ES(12, 127), 	ES(99, 71), 	ES(53, 19), 
	ES(93, 126), 	ES(93, 123), 	ES(143, 124), 	ES(61, 175), 	ES(90, 178), 	ES(131, 146), 	ES(155, 155), 	ES(109, 59), 
	ES(79, 141), 	ES(116, 189), 	ES(113, 215), 	ES(125, 214), 	ES(122, 227), 	ES(115, 218), 	ES(114, 151), 	ES(130, 109), 
	ES(51, 149), 	ES(96, 209), 	ES(122, 239), 	ES(193, 230), 	ES(177, 232), 	ES(127, 219), 	ES(94, 196), 	ES(79, 114), 
	ES(71, 160), 	ES(125, 220), 	ES(198, 201), 	ES(236, 253), 	ES(227, 221), 	ES(210, 219), 	ES(128, 206), 	ES(75, 160), 
	ES(104, 171), 	ES(189, 165), 	ES(183, 201), 	ES(270, 161), 	ES(221, 181), 	ES(330, 177), 	ES(259, 161), 	ES(209, 151), 
	ES(65, 74), 	ES(137, 152), 	ES(121, 159), 	ES(69, 177), 	ES(170, 133), 	ES(169, 145), 	ES(118, 165), 	ES(102, 72), 
	ES(1, 129), 	ES(-46, 161), 	ES(-16, 153), 	ES(-169, 195), 	ES(-122, 183), 	ES(-69, 141), 	ES(41, 131), 	ES(-98, 117), 
};

EvalScore ROOK_PSQT[] = {
	ES(54, 309), 	ES(61, 341), 	ES(99, 377), 	ES(111, 367), 	ES(134, 340), 	ES(91, 323), 	ES(149, 309), 	ES(61, 284), 
	ES(-16, 329), 	ES(35, 341), 	ES(88, 347), 	ES(79, 362), 	ES(84, 317), 	ES(96, 309), 	ES(157, 263), 	ES(49, 291), 
	ES(0, 351), 	ES(36, 351), 	ES(67, 347), 	ES(53, 353), 	ES(78, 348), 	ES(74, 318), 	ES(194, 241), 	ES(116, 250), 
	ES(20, 359), 	ES(32, 380), 	ES(65, 386), 	ES(112, 383), 	ES(117, 369), 	ES(57, 362), 	ES(147, 313), 	ES(113, 299), 
	ES(88, 388), 	ES(137, 379), 	ES(146, 411), 	ES(179, 404), 	ES(195, 353), 	ES(198, 332), 	ES(233, 315), 	ES(238, 300), 
	ES(152, 376), 	ES(220, 391), 	ES(223, 391), 	ES(232, 383), 	ES(339, 344), 	ES(342, 317), 	ES(486, 298), 	ES(396, 272), 
	ES(217, 377), 	ES(209, 423), 	ES(280, 436), 	ES(345, 407), 	ES(296, 398), 	ES(403, 355), 	ES(353, 344), 	ES(470, 295), 
	ES(283, 378), 	ES(246, 407), 	ES(271, 429), 	ES(297, 430), 	ES(354, 393), 	ES(412, 350), 	ES(347, 380), 	ES(422, 347), 
};

EvalScore QUEEN_PSQT[] = {
	ES(354, 901), 	ES(327, 925), 	ES(354, 939), 	ES(405, 902), 	ES(371, 919), 	ES(321, 915), 	ES(408, 806), 	ES(379, 810), 
	ES(360, 914), 	ES(385, 932), 	ES(428, 923), 	ES(417, 957), 	ES(421, 973), 	ES(452, 881), 	ES(473, 771), 	ES(505, 668), 
	ES(371, 929), 	ES(403, 1002), 	ES(382, 1086), 	ES(384, 1067), 	ES(390, 1083), 	ES(409, 1048), 	ES(465, 978), 	ES(437, 926), 
	ES(385, 979), 	ES(379, 1079), 	ES(375, 1121), 	ES(401, 1193), 	ES(402, 1185), 	ES(397, 1150), 	ES(431, 1070), 	ES(439, 1025), 
	ES(376, 987), 	ES(393, 1071), 	ES(412, 1128), 	ES(409, 1215), 	ES(405, 1256), 	ES(456, 1206), 	ES(459, 1151), 	ES(474, 1071), 
	ES(436, 953), 	ES(429, 1020), 	ES(411, 1161), 	ES(480, 1175), 	ES(492, 1221), 	ES(635, 1153), 	ES(652, 1014), 	ES(648, 972), 
	ES(436, 906), 	ES(344, 1077), 	ES(376, 1190), 	ES(335, 1253), 	ES(372, 1311), 	ES(508, 1165), 	ES(418, 1114), 	ES(601, 1007), 
	ES(304, 1030), 	ES(324, 1082), 	ES(439, 1145), 	ES(554, 1093), 	ES(551, 1086), 	ES(582, 1054), 	ES(645, 904), 	ES(446, 1014), 
};

EvalScore KING_PSQT[] = {
	ES(228, -302), 	ES(303, -237), 	ES(200, -171), 	ES(-159, -108), 	ES(73, -192), 	ES(-59, -107), 	ES(229, -206), 	ES(239, -306), 
	ES(229, -187), 	ES(86, -89), 	ES(27, -46), 	ES(-85, 0), 	ES(-92, 15), 	ES(-29, -17), 	ES(141, -86), 	ES(176, -153), 
	ES(-87, -108), 	ES(-28, -27), 	ES(-231, 59), 	ES(-279, 95), 	ES(-259, 97), 	ES(-248, 65), 	ES(-86, -9), 	ES(-146, -49), 
	ES(-236, -70), 	ES(-277, 41), 	ES(-380, 128), 	ES(-474, 179), 	ES(-469, 184), 	ES(-335, 139), 	ES(-351, 92), 	ES(-438, 33), 
	ES(-267, -29), 	ES(-301, 98), 	ES(-363, 160), 	ES(-514, 213), 	ES(-470, 207), 	ES(-341, 182), 	ES(-326, 163), 	ES(-419, 60), 
	ES(-376, 11), 	ES(-16, 75), 	ES(-256, 151), 	ES(-315, 188), 	ES(-172, 185), 	ES(97, 162), 	ES(29, 154), 	ES(-100, 46), 
	ES(-294, -39), 	ES(-156, 66), 	ES(-312, 107), 	ES(59, 45), 	ES(-118, 114), 	ES(-98, 162), 	ES(37, 122), 	ES(-26, 1), 
	ES(31, -350), 	ES(-16, -183), 	ES(98, -146), 	ES(-317, 12), 	ES(-147, -52), 	ES(16, -37), 	ES(156, -68), 	ES(273, -387), 
};

EvalScore BISHOP_PAIR = ES(72, 232);

EvalScore ISO_PAWN[] = {
	ES(-20, 8), 	ES(-57, -25), 	ES(-100, -13), 	ES(-76, -63), 	ES(-88, -65), 	ES(-84, -12), 	ES(-82, -20), 	ES(-74, 18), 
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

	EvalScore final_eval = material + psqt + bishop_pair + iso_pawn;

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

	std::vector<std::pair<double, double>> iso_pawn_grads(8);
	Bitboard mask = FileABits;
	for (int f = 0; f < 8; f++) {
		if (board.piece_boards[OCC(WHITE)] & board.piece_boards[PAWN] & mask) {
			bool left_isolated = f > 0 && !(board.piece_boards[OCC(WHITE)] & board.piece_boards[PAWN] & (mask >> 1));
			bool right_isolated = f < 7 && !(board.piece_boards[OCC(WHITE)] & board.piece_boards[PAWN] & (mask << 1));
			if ((f == 0 || left_isolated) && (f == 7 || right_isolated))
				iso_pawn_grads[f].first += alpha, iso_pawn_grads[f].second += beta;
		}

		if (board.piece_boards[OCC(BLACK)] & board.piece_boards[PAWN] & mask) {
			bool left_isolated = f > 0 && !(board.piece_boards[OCC(BLACK)] & board.piece_boards[PAWN] & (mask >> 1));
			bool right_isolated = f < 7 && !(board.piece_boards[OCC(BLACK)] & board.piece_boards[PAWN] & (mask << 1));
			if ((f == 0 || left_isolated) && (f == 7 || right_isolated))
				iso_pawn_grads[f].first -= alpha, iso_pawn_grads[f].second -= beta;
		}

		mask <<= 1;
	}
	grads.insert(grads.end(), iso_pawn_grads.begin(), iso_pawn_grads.end());

	return grads;
}