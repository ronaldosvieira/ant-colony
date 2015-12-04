/*
 * Ant.cpp
 *
 *  Created on: Nov 4, 2015
 *      Author: Ronaldo
 */

#include "Ant.h"

#define DEBUG_BUILD 1

#ifdef DEBUG_BUILD
#  define DEBUG(x) std::cout << x
#else
#  define DEBUG(x) do {} while (0)
#endif

Ant::Ant(Instance inst, std::vector<double> *pheromoneList) : pheromoneList(pheromoneList), inst(inst), solution(inst) {
	solution.empty();
}

Ant::~Ant() {
	// TODO Auto-generated destructor stub
}

void Ant::iterate() {
	while(findSolution());
}

double Ant::calcProbability(int i, int k) {
	double ph = 1.0;//this->pheromoneList->at(i);
	double hI = 1.0 * this->inst.profitList.at(i) / this->solution.getRemainingCapacityList().at(k);

	return pow(ph, 1.0) * pow(hI, 1.0);
}

bool Ant::findSolution() {
	rand(); rand();
	double chosenProb = (double) rand() / RAND_MAX;

	double probabilities[this->inst.numKnapsacks][this->inst.numItems];
	double sumOfProbabilities = 0;

	bool itemAvailable = false;

	for (int k = 0; k < this->inst.numKnapsacks; ++k) {
		for (int i = 0; i < this->inst.numItems; ++i) {
			if (this->solution.isValidUpdate(i, k)) {
				probabilities[k][i] = calcProbability(i, k);
				itemAvailable = true;
			} else {
				probabilities[k][i] = 0.0f;
			}

			sumOfProbabilities += probabilities[k][i];
		}
	}

	if (!itemAvailable) return false;

	DEBUG("Probabilities matrix:\n");

	for (int k = 0; k < inst.numKnapsacks; ++k) {
		DEBUG("k = " << k << " [");
		for (int i = 0; i < inst.numItems; ++i) {
			probabilities[k][i] = (1.0 * probabilities[k][i]) / sumOfProbabilities;
			DEBUG(probabilities[k][i] << "\t");
		}
		DEBUG("]\n");
	}

	DEBUG("\n");

	DEBUG("Chosen random number: " << chosenProb << "\n");

	float sum = 0.0f;
	for (int k = 0; k < this->inst.numKnapsacks; ++k) {
		for (int i = 0; i < this->inst.numItems; ++i) {
			if (chosenProb < sum + probabilities[k][i]) {
				this->solution.update(i, k);
				DEBUG("Chosen i/k: " << i << ", " << k << "\n");
				return true;
			}
			sum += probabilities[k][i];
		}
	}

	return false;
}

long Ant::getValue() {
	return solution.getValue();
}

Solution Ant::getSolution() {
	return this->solution;
}
