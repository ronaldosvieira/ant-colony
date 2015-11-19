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

namespace std {

class Colony {
private:
	int numAnts;
	double evaporationRatio;
	double alfa;
	double beta;

	double pheromoneList[];

	vector<Ant> ants;
	Instance inst;

	void populate();
	void iterate();
	vector<long> getSolutionValues();
	void resetPheromoneList();
public:
	Colony(int numAnts, double evaporationRatio, double alfa, double beta);
	Solution* run();
	virtual ~Colony();
};

} /* namespace std */

#endif /* COLONY_H_ */
