/*
 * Solution.cpp
 *
 *  Created on: Nov 4, 2015
 *      Author: Ronaldo
 */

#include "Solution.h"

Solution::Solution(Instance instance) {
	this->num_items = num_items;
}

Solution::~Solution() {
	// TODO Auto-generated destructor stub
}

void Solution::emptySolution() {
	solution = "";

	for (int i = 0; i < num_items; ++i) {
		solution += '0';
	}
}
