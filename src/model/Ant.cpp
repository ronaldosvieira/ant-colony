/*
 * Ant.cpp
 *
 *  Created on: Nov 4, 2015
 *      Author: Ronaldo
 */

#include "Ant.h"

Ant::Ant(Instance inst, std::vector<double> *pheromoneList) : inst(inst), solution(inst), pheromoneList(pheromoneList) {
	solution.empty();
}

Ant::~Ant() {
	// TODO Auto-generated destructor stub
}

void Ant::iterate() {
	while(findSolution());
}

bool Ant::findSolution() {
	srand(time(NULL));

	double sumProb = 0;
	double randomNum = (double) (rand() / RAND_MAX);

	double probabilities[this->inst.numKnapsacks][this->inst.numItems];
	double sumOfProbabilities = 0;

	bool itemAvailable = false;

	for (int k = 0; k < this->inst.numKnapsacks; ++k) {
		for (int i = 0; i < this->inst.numItems; ++i) {
			if (this->solution.isValidUpdate(i, k)) {
				probabilities[k][i] = this->pheromoneList->at(i) * ((1.0 * this->inst.profitList[i]) / this->solution.getRemainingCapacityList().at(k));
				itemAvailable = true;
			} else {
				probabilities[k][i] = 0;
			}

			sumOfProbabilities += probabilities[k][i];
		}
	}

	if (!itemAvailable) return false;

	for (int k = 0; k < this->inst.numKnapsacks; ++k) {
		for (int i = 0; i < this->inst.numItems; ++i) {
			probabilities[k][i] = 1.0 * probabilities[k][i] / sumOfProbabilities;
		}
	}

	for (int k = 0; k < this->inst.numKnapsacks; ++k) {
		for (int i = 0; i < this->inst.numItems; ++i) {
			if (randomNum < sumProb + probabilities[k][i]) {
				this->solution.update(i, k);
				return true;
			}
			sumProb += probabilities[k][i];
		}
	}
}

long Ant::getValue() {
	return solution.getValue();
}

Solution* Ant::getSolution() {
	return &this->solution;
}
