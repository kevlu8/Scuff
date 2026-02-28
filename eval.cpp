#include "eval.hpp"


constexpr int PAWN_PSQT[] = {
	0, 0, 0, 0, 0, 0, 0, 0, // 8
	80, 80, 80, 80, 80, 80, 80, 80, // 7
	40, 40, 50, 50, 50, 50, 40, 40, // 6
	20, 20, 30, 40, 40, 30, 20, 20, // 5
	10, 10, 20, 40, 40, 20, 10, 10, // 4
	5, 5, 10, 20, 20, 10, 5, 5, // 3
	0, 0, 0, -10, -10, 0, 0, 0, // 2
	0, 0, 0, 0, 0, 0, 0, 0 // 1
};

constexpr int KNIGHT_PSQT[] = {
	-50, -30, -20, -20, -20, -20, -30, -50,
	-30, -20, 0, 0, 0, 0, -20, -30,
	-20, 0, 10, 15, 15, 10, 0, -20,
	-20, 5, 15, 20, 20, 15, 5, -20,
	-20, 0, 15, 20, 20, 15, 0, -20,
	-20, 5, 10, 15, 15, 10, 5, -20,
	-30, -20, 0, 5, 5, 0, -20, -30,
	-50, -30, -20, -20, -20, -20, -30, -50
};

constexpr int BISHOP_PSQT[] = {
	-20, -10, -10, -10, -10, -10, -10, -20,
	-10, 0, 0, 0, 0, 0, 0, -10,
	-10, 0, 10, 10, 10, 10, 0, -10,
	-10, 0, 10, 10, 10, 10, 0, -10,
	-10, 0, 10, 10, 10, 10, 0, -10,
	-10, 10, 10, 10, 10, 10, 10, -10,
	-10, 20, 0, 0, 0, 0, 20, -10,
	-20, -10, -10, -10, -10, -10, -10, -20
};

constexpr int ROOK_PSQT[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
	5, 10, 10, 10, 10, 10, 10, 5,
	-5, 0, 0, 0, 0, 0, 0, -5,
	-5, 0, 0, 0, 0, 0, 0, -5,
	-5, 0, 0, 0, 0, 0, 0, -5,
	-5, 0, 0, 0, 0, 0, -5,
	-5, 0, 0, 0, 0, 0, 0, -5,
	0, 0, 5, 10, 10, 5, 0, 0
};

constexpr int QUEEN_PSQT[] = {
	-20, -10, -10, -5, -5, -10, -10, -20,
	-10, 0, 0, 0, 0, 0, 0, -10,
	-10, 0, 5, 5, 5, 5, 0, -10,
	-5, 0, 5, 5, 5, 5, 0, -5,
	0, 0, 5, 5, 5, 5, 0, -10,
	-10, 5, 5, 5, 5, 5, 0, -10,
	-10, 0, 5, 0, 0, 0, 0, -10,
	-20, -10, -10, -5, -5, -10, -10, -20
};

constexpr int KING_PSQT[] = {
	-30, -40, -40, -50, -50, -40, -40, -30,
	-30, -40, -40, -50, -50, -40, -40, -30,
	-30, -40, -40, -50, -50, -40, -40, -30,
	-30, -40, -40, -50, -50, -40, -40, -30,
	-20, -30, -30, -40, -40, -30, -30, -20,
	-10, 20, 20, 0, 0, 20, 20, -10,
	20, 20, 20, 20, 20, 20, 20, 20,
	20, 30, 10, 0, 0, 10, 30, 20
};

Value eval(const Board &board) {
	Value material = 0;

	material += PieceValue[PAWN] * (_mm_popcnt_u64(board.piece_boards[OCC(WHITE)] & board.piece_boards[PAWN]) - _mm_popcnt_u64(board.piece_boards[OCC(BLACK)] & board.piece_boards[PAWN]));
	material += PieceValue[KNIGHT] * (_mm_popcnt_u64(board.piece_boards[OCC(WHITE)] & board.piece_boards[KNIGHT]) - _mm_popcnt_u64(board.piece_boards[OCC(BLACK)] & board.piece_boards[KNIGHT]));
	material += PieceValue[BISHOP] * (_mm_popcnt_u64(board.piece_boards[OCC(WHITE)] & board.piece_boards[BISHOP]) - _mm_popcnt_u64(board.piece_boards[OCC(BLACK)] & board.piece_boards[BISHOP]));
	material += PieceValue[ROOK] * (_mm_popcnt_u64(board.piece_boards[OCC(WHITE)] & board.piece_boards[ROOK]) - _mm_popcnt_u64(board.piece_boards[OCC(BLACK)] & board.piece_boards[ROOK]));
	material += PieceValue[QUEEN] * (_mm_popcnt_u64(board.piece_boards[OCC(WHITE)] & board.piece_boards[QUEEN]) - _mm_popcnt_u64(board.piece_boards[OCC(BLACK)] & board.piece_boards[QUEEN]));

	Value psqt = 0;
	for (int i = 0; i < 64; i++) {
		Piece p = board.mailbox[i];
		PieceType pt = PieceType(p & 7);
		int side = p >> 3;
		if (p == NO_PIECE) continue;
		if (pt == PAWN)
			psqt += PAWN_PSQT[56 ^ i] * (side == WHITE ? 1 : -1);
		else if (pt == KNIGHT)
			psqt += KNIGHT_PSQT[56 ^ i] * (side == WHITE ? 1 : -1);
		else if (pt == BISHOP)
			psqt += BISHOP_PSQT[56 ^ i] * (side == WHITE ? 1 : -1);
		else if (pt == ROOK)
			psqt += ROOK_PSQT[56 ^ i] * (side == WHITE ? 1 : -1);
		else if (pt == QUEEN)
			psqt += QUEEN_PSQT[56 ^ i] * (side == WHITE ? 1 : -1);
		else if (pt == KING)
			psqt += KING_PSQT[56 ^ i] * (side == WHITE ? 1 : -1);
	}

	Value eval = material + psqt;
	if (board.side == BLACK) eval = -eval;

	return eval;
}
