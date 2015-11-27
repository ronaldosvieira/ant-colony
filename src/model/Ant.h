/*
 * Ant.h
 *
 *  Created on: Nov 4, 2015
 *      Author: Ronaldo
 */

#ifndef ANT_H_
#define ANT_H_

#include <cstdlib>
#include <ctime>

#include "Solution.h"

class Ant {
private:
	Solution solution;

	Instance inst;
	std::vector<double> *pheromoneList;

	bool findSolution();
public:
	Ant(Instance inst, std::vector<double> *pheromoneList);
	virtual ~Ant();

	void iterate();
	long getValue();
	Solution getSolution();
};

#endif /* ANT_H_ */
