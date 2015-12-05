/*
 * Solution.cpp
 *
 *  Created on: Nov 4, 2015
 *      Author: Ronaldo
 */

#include "Solution.h"

Solution::Solution(Instance inst) : inst(inst), remainingCapacityList(this->inst.capacityList) {
	empty();
}

Solution::~Solution() {
	// TODO Auto-generated destructor stub
}

void Solution::empty() {
	for (int i = 0; i < this->inst.numItems; ++i) {
		solution.push_back(-1);
	}
}

std::vector<int> Solution::getRawSolution() {
	return this->solution;
}

bool Solution::isValidUpdate(int item, int knapsack) {
	if (solution[item] != -1) return false;

	for (int k = 0; k < inst.numKnapsacks; ++k) {
		if (remainingCapacityList[knapsack] - this->inst.weightList[knapsack][item] < 0) {
			return false;
		}
	}

	return true;
}

void Solution::update(int item, int knapsack) {
	solution[item] = knapsack;

	for (int k = 0; k < this->inst.numKnapsacks; ++k) {
		remainingCapacityList[k] -= this->inst.weightList[k][item];
	}
}

std::vector<int> Solution::getRemainingCapacityList() {
	return this->remainingCapacityList;
}

long Solution::getValue() {
	long value = 0;

	for (int i = 0; i < this->inst.numItems; ++i) {
		if (solution[i] != -1) {
			value += inst.profitList.at(i);
		}
	}

	return value;
}

bool Solution::isValid() {
	long totalWeightList[inst.numKnapsacks];
	int i;

	for (i = 0; i < inst.numKnapsacks; i++) {
		totalWeightList[i] = 0;
	}

	for (int k = 0; k < inst.numKnapsacks; k++) {
		for (i = 0; i < inst.numItems; i++) {
			if (solution[i] != -1) {
				totalWeightList[solution[i]] += inst.weightList[k][i];
			}
		}
	}

	for (i = 0; i < inst.numKnapsacks; ++i) {
		if (totalWeightList[i] > inst.capacityList[i]) {
			return false;
		}
	}

	return true;
}

bool Solution::isSelected(int item) {
	return this->solution.at(item) != -1;
}

std::string Solution::toString() {
	std::string solStr = "";

	for (int i = 0; i < inst.numItems; ++i) {
		if (solution[i] == -1) solStr += '-';
		else solStr += solution[i] + '0';
	}

	return solStr;
}
