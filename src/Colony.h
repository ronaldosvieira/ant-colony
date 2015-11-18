/*
 * Colony.h
 *
 *  Created on: Nov 7, 2015
 *      Author: Ronaldo
 */

#ifndef COLONY_H_
#define COLONY_H_

#include "Ant.h"

namespace std {

class Colony {
private:
	int numAnts;
	double evaporationRatio;
	double alfa;
	double beta;

	vector<Ant> ants;
	Instance inst;

	void populate();
public:
	Colony(int numAnts, double evaporationRatio, double alfa, double beta);
	virtual ~Colony();
};

} /* namespace std */

#endif /* COLONY_H_ */
