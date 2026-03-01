#pragma once

#include "bitboard.hpp"
#include "includes.hpp"
#include "eval_types.hpp"

extern EvalScore MATERIAL_VALUES[5];
extern EvalScore PAWN_PSQT[64];
extern EvalScore KNIGHT_PSQT[64];
extern EvalScore BISHOP_PSQT[64];
extern EvalScore ROOK_PSQT[64];
extern EvalScore QUEEN_PSQT[64];
extern EvalScore KING_PSQT[64];

int white_eval(const Board &board);

int eval(const Board &board);

std::vector<std::pair<double, double>> calc_grad(const Board &board);