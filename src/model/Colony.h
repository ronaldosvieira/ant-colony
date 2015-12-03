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

constexpr auto INITIAL_PHEROMONE_VALUE = 1;

class Colony {
private:
	int numAnts;
	double evaporationRatio;
	double alfa;
	double beta;

	std::vector<double> pheromoneList;

	std::vector<Ant> ants;
	Instance inst;

	void populate();
	void iterate();
	void evaporate();

	void resetPheromoneList();
public:
	Colony(Instance inst, int numAnts, double evaporationRatio, double alfa, double beta);
	Solution run();
	std::vector<long> getSolutionValues();
	std::vector<double> getPheromoneList();
	virtual ~Colony();
};

#endif /* COLONY_H_ */
