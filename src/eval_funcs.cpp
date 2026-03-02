#include "eval_funcs.hpp"

namespace Eval {
	Bitboard passed_pawn_mask[2][64];
};

Bitboard reverse_mask(Bitboard b) {
	Bitboard result = 0;
	for (int i = 0; i < 64; i++) {
		if (b & (1ULL << i)) {
			result |= 1ULL << (56 ^ i);
		}
	}
	return result;
}

__attribute__((constructor)) void init_eval() {
	// precompute passed pawn masks
	// for a pawn square, we want to have a mask of all squares in front of it and on adjacent files
	for (int i = 0; i < 64; i++) {
		Bitboard mask = 0;
		int rank = i >> 3, file = i & 7;
		for (int r = rank + 1; r < 8; r++) {
			mask |= square_bits(Square(r * 8 + file));
			if (file > 0) mask |= square_bits(Square(r * 8 + file - 1));
			if (file < 7) mask |= square_bits(Square(r * 8 + file + 1));
		}
		Eval::passed_pawn_mask[0][i] = mask;
		Eval::passed_pawn_mask[1][56 ^ i] = reverse_mask(mask);
	}
}
