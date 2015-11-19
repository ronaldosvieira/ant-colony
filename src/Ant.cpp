/*
 * Ant.cpp
 *
 *  Created on: Nov 4, 2015
 *      Author: Ronaldo
 */

#include "Ant.h"

Ant::Ant(Instance *inst, double *pheromoneList) : solution(inst), pheromoneList(pheromoneList) {
	this->inst = inst;
	solution.emptySolution();
}

Ant::~Ant() {
	// TODO Auto-generated destructor stub
}

void Ant::iterate() {
	choose();
}

void Ant::choose() {
	srand(time(NULL));

	double sumProb = 0;
	double randomNum = (double) (rand() / RAND_MAX);

	double probabilities[this->inst->numKnapsacks][this->inst->numItems];
	double sumOfProbabilities = 0;

	for (int k = 0; k < this->inst->numKnapsacks; ++k) {
		for (int i = 0; i < this->inst->numItems; ++i) {
			if (this->solution.isValidUpdate(i, k)) {
				probabilities[k][i] = this->pheromoneList[i] * ((1.0 * this->inst->profitList[i]) / this->solution.getRemainingCapacityList().at(k));
			} else {
				probabilities[k][i] = 0;
			}

			sumOfProbabilities += probabilities[k][i];
		}
	}

	for (int k = 0; k < this->inst->numKnapsacks; ++k) {
		for (int i = 0; i < this->inst->numItems; ++i) {
			probabilities[k][i] = 1.0 * probabilities[k][i] / sumOfProbabilities;
		}
	}

	for (int k = 0; k < this->inst->numKnapsacks; ++k) {
		for (int i = 0; i < this->inst->numItems; ++i) {
			if (randomNum < sumProb + probabilities[k][i]) {
				this->solution.update(i, k);
				return;
			}
			sumProb += probabilities[k][i];
		}
	}
}

long Ant::getValue() {
	return solution.getHeuristicValue();
}

Solution* Ant::getSolution() {
	return &this->solution;
}
