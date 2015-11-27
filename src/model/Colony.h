/*
 * Colony.h
 *
 *  Created on: Nov 7, 2015
 *      Author: Ronaldo
 */

#ifndef COLONY_H_
#define COLONY_H_

#include <iostream>

#include "Ant.h"

#define INITIAL_PHEROMONE_VALUE 1

namespace std {

class Colony {
private:
	int numAnts;
	double evaporationRatio;
	double alfa;
	double beta;

	vector<double> pheromoneList;

	vector<Ant> ants;
	Instance inst;

	void populate();
	void iterate();

	void resetPheromoneList();
public:
	Colony(Instance inst, int numAnts, double evaporationRatio, double alfa, double beta);
	Solution run();vector<long> getSolutionValues();
	virtual ~Colony();
};

} /* namespace std */

#endif /* COLONY_H_ */
