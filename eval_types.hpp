#pragma once

#include "includes.hpp"

struct EvalScore {
	Value mg, eg;
	EvalScore() : mg(0), eg(0) {}
	EvalScore(Value v) : mg(v), eg(v) {}
	EvalScore(Value mg, Value eg) : mg(mg), eg(eg) {}
	Value operator()(int phase) const {
		return (mg * phase + eg * (24 - phase)) / 24;
	}

	EvalScore operator+(const EvalScore &other) const {
		return EvalScore(mg + other.mg, eg + other.eg);
	}

	EvalScore operator-(const EvalScore &other) const {
		return EvalScore(mg - other.mg, eg - other.eg);
	}

	EvalScore operator*(int scalar) const {
		return EvalScore(mg * scalar, eg * scalar);
	}

	EvalScore operator*(long long scalar) const {
		return EvalScore(mg * scalar, eg * scalar);
	}

	EvalScore operator*(double scalar) const {
		return EvalScore(round(mg * scalar), round(eg * scalar));
	}

	EvalScore operator+=(const EvalScore &other) {
		mg += other.mg;
		eg += other.eg;
		return *this;
	}

	EvalScore operator-=(const EvalScore &other) {
		mg -= other.mg;
		eg -= other.eg;
		return *this;
	}

	EvalScore operator*=(int scalar) {
		mg *= scalar;
		eg *= scalar;
		return *this;
	}
};

#define ES(a, b) EvalScore((a), (b))
