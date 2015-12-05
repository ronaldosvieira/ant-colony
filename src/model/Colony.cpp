/*
 * Colony.cpp
 *
 *  Created on: Nov 7, 2015
 *      Author: Ronaldo
 */

#include "Colony.h"

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
		ants.push_back(Ant(this->inst, this->pheromoneList, alfa, beta));
	}
}

void Colony::evaporate() {
	for (int i = 0; i < this->pheromoneList.size(); ++i) {
		this->pheromoneList[i] *= this->evaporationRatio;
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

	evaporate();
}

std::vector<long> Colony::getSolutionValues() {
	std::vector<long> solValues;

	for (int i = 0; i < this->numAnts; ++i) {
		solValues.push_back(this->ants.at(i).getValue());
	}

	return solValues;
}

std::vector<double> Colony::getPheromoneList() {
	return this->pheromoneList;
}

Solution Colony::run() {
	for (int i = 0; i < inst.numItems; ++i) {
		iterate();
	}

	std::vector<long> solValues = this->getSolutionValues();
	int bestIndex = 0;

	for (int i = 0; i < this->numAnts; ++i) {
		if (solValues.at(i) > solValues.at(bestIndex)) bestIndex = i;
	}

	return this->ants.at(bestIndex).getSolution();
}

