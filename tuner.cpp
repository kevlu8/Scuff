#include "includes.hpp"
#include "eval.hpp"
#include "search.hpp"
#include <fstream>
#include <random>
#include <cmath>

// Adam hyperparameters
double base_lr = 1.0;
double beta1 = 0.9;
double beta2 = 0.999;
double epsilon = 1e-8;
int batch_size = 32768;

std::vector<std::pair<std::string, double>> positions;

double sigmoid(double x) {
	return 1 / (1 + exp(-x / 400.0));
}

std::vector<EvalScore *> params;
std::vector<std::pair<double, double>> float_params;
std::vector<std::pair<double, double>> adam_m;
std::vector<std::pair<double, double>> adam_v;
int adam_t = 0; // timestep

void init_params() {
	for (auto &s : MATERIAL_VALUES) params.push_back(&s);
	for (auto &s : PAWN_PSQT) params.push_back(&s);
	for (auto &s : KNIGHT_PSQT) params.push_back(&s);
	for (auto &s : BISHOP_PSQT) params.push_back(&s);
	for (auto &s : ROOK_PSQT) params.push_back(&s);
	for (auto &s : QUEEN_PSQT) params.push_back(&s);
	for (auto &s : KING_PSQT) params.push_back(&s);
	params.push_back(&BISHOP_PAIR);
	for (auto &s : KNIGHT_MOB) params.push_back(&s);
	for (auto &s : BISHOP_MOB) params.push_back(&s);
	for (auto &s : ROOK_MOB) params.push_back(&s);
	for (auto &s : QUEEN_MOB) params.push_back(&s);
	for (auto &s : KING_MOB) params.push_back(&s);

	// init adam stuff too
	for (auto &p : params) {
		float_params.push_back({(double)p->mg, (double)p->eg});
		adam_m.push_back({0.0, 0.0});
		adam_v.push_back({0.0, 0.0});
	}
}

void sync_params() {
	for (size_t i = 0; i < params.size(); i++) {
		params[i]->mg = (int)round(float_params[i].first);
		params[i]->eg = (int)round(float_params[i].second);
	}
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
	outfile << "};\n\nEvalScore BISHOP_PAIR = ES(" << BISHOP_PAIR.mg << ", " << BISHOP_PAIR.eg << ");\n";
	outfile << "\nEvalScore KNIGHT_MOB[] = {" << std::endl;
	for (int i = 0; i < sizeof(KNIGHT_MOB) / sizeof(EvalScore); i++) {
		outfile << "	ES(" << KNIGHT_MOB[i].mg << ", " << KNIGHT_MOB[i].eg << "),\n";
	}
	outfile << "};\n\nEvalScore BISHOP_MOB[] = {" << std::endl;
	for (int i = 0; i < sizeof(BISHOP_MOB) / sizeof(EvalScore); i++) {
		outfile << "	ES(" << BISHOP_MOB[i].mg << ", " << BISHOP_MOB[i].eg << "),\n";
	}
	outfile << "};\n\nEvalScore ROOK_MOB[] = {" << std::endl;
	for (int i = 0; i < sizeof(ROOK_MOB) / sizeof(EvalScore); i++) {
		outfile << "	ES(" << ROOK_MOB[i].mg << ", " << ROOK_MOB[i].eg << "),\n";
	}
	outfile << "};\n\nEvalScore QUEEN_MOB[] = {" << std::endl;
	for (int i = 0; i < sizeof(QUEEN_MOB) / sizeof(EvalScore); i++) {
		outfile << "	ES(" << QUEEN_MOB[i].mg << ", " << QUEEN_MOB[i].eg << "),\n";
	}
	outfile << "};\n\nEvalScore KING_MOB[] = {" << std::endl;
	for (int i = 0; i < sizeof(KING_MOB) / sizeof(EvalScore); i++) {
		outfile << "	ES(" << KING_MOB[i].mg << ", " << KING_MOB[i].eg << "),\n";
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

	std::cout << "Detected " << params.size() << " parameters to tune." << std::endl;

	std::cout << "Begin training..." << std::endl;

	for (int epoch = 1; epoch <= 100; epoch++) {
		std::shuffle(positions.begin(), positions.end(), std::mt19937(std::random_device()()));
		double total_loss = 0;
		for (int i = 0; i < (int)positions.size(); i += batch_size) {
			std::vector<std::pair<double, double>> avg_grads(params.size(), {0, 0});
			int actual_batch_size = std::min(batch_size, (int)positions.size() - i);
			for (int j = i; j < i + actual_batch_size; j++) {
				auto [fen, result] = positions[j];
				Board board(fen);

				double eval_score = sigmoid(white_eval(board));
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

			adam_t++;
			for (size_t k = 0; k < params.size(); k++) {
				double g_mg = avg_grads[k].first / actual_batch_size;
				double g_eg = avg_grads[k].second / actual_batch_size;

				// Update biased first moment
				adam_m[k].first  = beta1 * adam_m[k].first  + (1 - beta1) * g_mg;
				adam_m[k].second = beta1 * adam_m[k].second + (1 - beta1) * g_eg;

				// Update biased second moment
				adam_v[k].first  = beta2 * adam_v[k].first  + (1 - beta2) * g_mg * g_mg;
				adam_v[k].second = beta2 * adam_v[k].second + (1 - beta2) * g_eg * g_eg;

				// Bias-corrected moments
				double m_hat_mg = adam_m[k].first  / (1 - pow(beta1, adam_t));
				double m_hat_eg = adam_m[k].second / (1 - pow(beta1, adam_t));
				double v_hat_mg = adam_v[k].first  / (1 - pow(beta2, adam_t));
				double v_hat_eg = adam_v[k].second / (1 - pow(beta2, adam_t));

				// Update float shadow params
				float_params[k].first  -= base_lr * m_hat_mg / (sqrt(v_hat_mg) + epsilon);
				float_params[k].second -= base_lr * m_hat_eg / (sqrt(v_hat_eg) + epsilon);
			}

			// Sync float params back to integer EvalScore for next evaluation
			sync_params();
		}
		std::cout << "Epoch " << epoch << ", Loss: " << total_loss / positions.size() << std::endl;
		dump_params();
	}
}