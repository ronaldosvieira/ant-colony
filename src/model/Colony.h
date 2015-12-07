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

#define DEBUG_BUILD
#undef DEBUG_BUILD

#ifdef DEBUG_BUILD
#  define DEBUG(x) std::cout << x
#else
#  define DEBUG(x) do {} while (0)
#endif

constexpr auto INITIAL_PHEROMONE_VALUE = 1;
constexpr auto NUM_ITERATIONS = 50;

class Colony {
private:
	int numAnts;
	double evaporationRatio;
	double alpha;
	double beta;

	std::vector<std::vector<double>> pheromoneList;

	std::vector<Ant> ants;
	Instance &inst;

	void populate();
	void iterate();
	void evaporate();
	void reinforce();

	void resetPheromoneList();
public:
	Colony(Instance &inst, int numAnts, double evaporationRatio = 0.5,
			double alpha = 1.0, double beta = 1.0);
	Solution run();
	std::vector<long> getSolutionValues();
	std::vector<std::vector<double>> getPheromoneList();
	void setAlpha(double alpha);
	void setBeta(double beta);
	void setEvaporationRatio(double evaporationRatio);
	virtual ~Colony();
};

#endif /* COLONY_H_ */
