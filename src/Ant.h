/*
 * Ant.h
 *
 *  Created on: Nov 4, 2015
 *      Author: Ronaldo
 */

#ifndef ANT_H_
#define ANT_H_

#include "Solution.h"

class Ant {
private:
	Solution solution;
public:
	Ant(Instance *inst);
	virtual ~Ant();
	Solution get_solution();
};

#endif /* ANT_H_ */
