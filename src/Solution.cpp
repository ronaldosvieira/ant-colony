/*
 * Solution.cpp
 *
 *  Created on: Nov 4, 2015
 *      Author: Ronaldo
 */

#include "Solution.h"

Solution::Solution(Instance *inst) {
	this->inst = inst;
	emptySolution();
}

Solution::~Solution() {
	// TODO Auto-generated destructor stub
}

void Solution::emptySolution() {
	solution.reserve(inst->numItems);

	for (int i = 0; i < inst->numItems; ++i) {
		solution[i] = -1;
	}
}

void Solution::update(int item, int knapsack) {
	solution[item] = knapsack;
}

long Solution::getHeuristicValue() {
	long value = 0;

	for (int i = 0; i < inst->numItems; ++i) {
		if (solution[i] != -1) {
			value += inst->profitList.at(i);
		}
	}

	return value;
}

bool Solution::isValid() {
	long totalWeightList[inst->numKnapsacks];
	int i;

	for (i = 0; i < inst->numKnapsacks; i++) {
		totalWeightList[i] = 0;
	}

	for (i = 0; i < inst->numItems; i++) {
		if (solution[i] != -1) {
			totalWeightList[solution[i]] += inst->weightList[i];
		}
	}

	for (i = 0; i < inst->numKnapsacks; ++i) {
		if (totalWeightList[i] > inst->capacityList[i]) {
			return false;
		}
	}

	return true;
}

string Solution::toString() {
	string solStr = "";

	for (int i = 0; i < inst->numItems; ++i) {
		if (solution[i] == -1) solStr += '-';
		else solStr += solution[i] + '0';
	}

	return solStr;
}
