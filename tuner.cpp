#include "includes.hpp"
#include "eval.hpp"
#include <fstream>
#include <random>

double base_lr = 10;
int batch_size = 1024;

std::vector<std::pair<std::string, double>> positions;

double sigmoid(double x) {
	return 1 / (1 + exp(-x / 400.0));
}

std::vector<EvalScore *> params;

void init_params() {
	for (auto &s : MATERIAL_VALUES) params.push_back(&s);
	for (auto &s : PAWN_PSQT) params.push_back(&s);
	for (auto &s : KNIGHT_PSQT) params.push_back(&s);
	for (auto &s : BISHOP_PSQT) params.push_back(&s);
	for (auto &s : ROOK_PSQT) params.push_back(&s);
	for (auto &s : QUEEN_PSQT) params.push_back(&s);
	for (auto &s : KING_PSQT) params.push_back(&s);
}

void dump_params() {
	std::ofstream outfile("tuned_params.txt");
	outfile << "EvalScore MATERIAL_VALUES[] = {" << std::endl;
	for (int i = 0; i < sizeof(MATERIAL_VALUES) / sizeof(EvalScore); i++) {
		outfile << "	ES(" << MATERIAL_VALUES[i].mg << ", " << MATERIAL_VALUES[i].eg << "),\n";
	}
	outfile << "};\n\nEvalScore PAWN_PSQT[] = {" << std::endl;
	for (int i = 0; i < sizeof(PAWN_PSQT) / sizeof(EvalScore); i++) {
		outfile << "	ES(" << PAWN_PSQT[i].mg << ", " << PAWN_PSQT[i].eg << "), ";
		if ((i + 1) % 8 == 0) outfile << std::endl;
	}
	outfile << "};\n\nEvalScore KNIGHT_PSQT[] = {" << std::endl;
	for (int i = 0; i < sizeof(KNIGHT_PSQT) / sizeof(EvalScore); i++) {
		outfile << "	ES(" << KNIGHT_PSQT[i].mg << ", " << KNIGHT_PSQT[i].eg << "), ";
		if ((i + 1) % 8 == 0) outfile << std::endl;
	}
	outfile << "};\n\nEvalScore BISHOP_PSQT[] = {" << std::endl;
	for (int i = 0; i < sizeof(BISHOP_PSQT) / sizeof(EvalScore); i++) {
		outfile << "	ES(" << BISHOP_PSQT[i].mg << ", " << BISHOP_PSQT[i].eg << "), ";
		if ((i + 1) % 8 == 0) outfile << std::endl;
	}
	outfile << "};\n\nEvalScore ROOK_PSQT[] = {" << std::endl;
	for (int i = 0; i < sizeof(ROOK_PSQT) / sizeof(EvalScore); i++) {
		outfile << "	ES(" << ROOK_PSQT[i].mg << ", " << ROOK_PSQT[i].eg << "), ";
		if ((i + 1) % 8 == 0) outfile << std::endl;
	}
	outfile << "};\n\nEvalScore QUEEN_PSQT[] = {" << std::endl;
	for (int i = 0; i < sizeof(QUEEN_PSQT) / sizeof(EvalScore); i++) {
		outfile << "	ES(" << QUEEN_PSQT[i].mg << ", " << QUEEN_PSQT[i].eg << "), ";
		if ((i + 1) % 8 == 0) outfile << std::endl;
	}
	outfile << "};\n\nEvalScore KING_PSQT[] = {" << std::endl;
	for (int i = 0; i < sizeof(KING_PSQT) / sizeof(EvalScore); i++) {
		outfile << "	ES(" << KING_PSQT[i].mg << ", " << KING_PSQT[i].eg << "), ";
		if ((i + 1) % 8 == 0) outfile << std::endl;
	}
	outfile << "};\n";
	outfile.close();
}

int main() {
	std::cout << "Loading positions..." << std::endl;
	std::ifstream infile("lichess-big3-resolved.txt");
	// file format: `fen [result]`
	std::string line;
	while (std::getline(infile, line)) {
		std::string fen = line.substr(0, line.find('[') - 1);
		std::string result = line.substr(line.find('[') + 1, line.find(']') - line.find('[') - 1);
		positions.push_back({fen, std::stod(result)});
	}
	infile.close();

	init_params();

	std::cout << "Begin training..." << std::endl;

	for (int epoch = 1; epoch <= 100; epoch++) {
		double lr = base_lr * pow(0.99, epoch);
		// double lr = base_lr;

		std::shuffle(positions.begin(), positions.end(), std::mt19937(std::random_device()()));
		double total_loss = 0;
		for (int i = 0; i < positions.size(); i += batch_size) {
			std::vector<std::pair<double, double>> avg_grads(params.size(), {0, 0});
			int actual_batch_size = std::min(batch_size, (int)positions.size() - i);
			for (int j = i; j < i + actual_batch_size; j++) {
				auto [fen, result] = positions[j];
				Board board(fen);
				if (board.side == BLACK) result = 1 - result; // flip result for black

				double eval_score = sigmoid(eval(board));
				double loss = pow(eval_score - result, 2);
				total_loss += loss;

				double dloss = 2 * (eval_score - result); // d(loss)/d(eval_score)
				double dsigmoid = eval_score * (1 - eval_score) / 400.0; // d(eval_score)/d(raw_eval)
				double scalar = dloss * dsigmoid;

				std::vector<std::pair<double, double>> grads = calc_grad(board);
				for (size_t k = 0; k < grads.size(); k++) {
					avg_grads[k].first += grads[k].first * scalar;
					avg_grads[k].second += grads[k].second * scalar;
				}
			}

			// Update parameters
			for (size_t k = 0; k < params.size(); k++) {
				*params[k] -= EvalScore(avg_grads[k].first * lr, avg_grads[k].second * lr);
			}
		}
		std::cout << "Epoch " << epoch << ", Loss: " << total_loss / positions.size() << std::endl;
		dump_params();
	}
}