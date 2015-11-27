/*
 * Colony.cpp
 *
 *  Created on: Nov 7, 2015
 *      Author: Ronaldo
 */

#include "Colony.h"

namespace std {

Colony::Colony(Instance inst, int numAnts, double evaporationRatio, double alfa , double beta) :
	inst(inst), numAnts(numAnts), evaporationRatio(evaporationRatio), alfa(alfa), beta(beta) {
	srand(time(NULL));
	resetPheromoneList();
	populate();
}

Colony::~Colony() {

}

void Colony::populate() {
	for (int i = 0; i < numAnts; ++i) {
		ants.push_back(Ant(this->inst, &this->pheromoneList));
	}
}

void Colony::resetPheromoneList() {
	for (int i = 0; i < this->inst.numItems; ++i) {
		pheromoneList.push_back(INITIAL_PHEROMONE_VALUE);
	}
}

void Colony::iterate() {
	for (int i = 0; i < this->numAnts; ++i) {
		this->ants.at(i).iterate();
	}
}

vector<long> Colony::getSolutionValues() {
	vector<long> solValues;

	for (int i = 0; i < this->numAnts; ++i) {
		solValues.push_back(this->ants.at(i).getValue());
	}

	return solValues;
}

Solution Colony::run() {
	for (int i = 0; i < inst.numItems; ++i) {
		iterate();
	}

	vector<long> solValues = this->getSolutionValues();
	int bestIndex = 0;

	for (int i = 0; i < this->numAnts; ++i) {
		if (solValues.at(i) > solValues.at(bestIndex)) bestIndex = i;
	}

	return this->ants.at(bestIndex).getSolution();
}

} /* namespace std */

