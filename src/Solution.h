/*
 * Solution.h
 *
 *  Created on: Nov 4, 2015
 *      Author: Ronaldo
 */

#ifndef SOLUTION_H_
#define SOLUTION_H_

#include <string>
#include "Instance.h"

using namespace std;

class Solution {
private:
	vector<int> solution;
	Instance *inst;
public:
	Solution(Instance *inst);
	virtual ~Solution();
	void emptySolution();
	void update(int item, int knapsack);
	long getHeuristicValue();
	bool isValid();
	string toString();
};

#endif /* SOLUTION_H_ */
