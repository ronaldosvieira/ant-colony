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

class Solution {
private:
	std::vector<int> solution;
	Instance inst;

	std::vector<int> remainingCapacityList;
public:
	Solution(Instance inst);
	virtual ~Solution();
	void empty();
	void update(int item, int knapsack);

	long getValue();
	std::vector<int> getRawSolution();
	std::vector<int> getRemainingCapacityList();

	bool isValid();
	bool isValidUpdate(int item, int knapsack);
	bool isSelected(int item);

	std::string toString();
};

#endif /* SOLUTION_H_ */