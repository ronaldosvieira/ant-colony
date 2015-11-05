/*
 * Solution.h
 *
 *  Created on: Nov 4, 2015
 *      Author: Ronaldo
 */

#ifndef SOLUTION_H_
#define SOLUTION_H_

#include <string>

using namespace std;

class Solution {
private:
	string solution;
	int num_items;
public:
	Solution(Instance instance);
	virtual ~Solution();
	void emptySolution();
};

#endif /* SOLUTION_H_ */
