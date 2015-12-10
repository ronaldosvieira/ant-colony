/*
 * Ant.h
 *
 *  Created on: Nov 4, 2015
 *      Author: Ronaldo
 */

#ifndef ANT_H_
#define ANT_H_

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Solution.h"

class Ant {
private:
	Solution solution;

	Instance &inst;
	std::vector<std::vector<double>> &pheromoneList;

	double &alpha, &beta;

	bool findSolution();
	double calcProbability(int i, int k);
public:
	Ant(Instance &inst, std::vector<std::vector<double>> &pheromoneList,
			double &alpha, double &beta);
	virtual ~Ant();

	void iterate();
	long getValue();
	Solution getSolution();
	void setPheromoneList(std::vector<std::vector<double>> &phL);
};

#endif /* ANT_H_ */
