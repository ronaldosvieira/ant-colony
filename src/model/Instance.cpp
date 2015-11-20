/*
 * Instance.cpp
 *
 *  Created on: Nov 5, 2015
 *      Author: Ronaldo
 */

#include "Instance.h"

Instance::Instance(int &numItems, int &numKnapsacks, std::vector<int> &weightList,
		std::vector<int> &profitList, std::vector<int> &capacityList) :
		numItems(numItems), numKnapsacks(numKnapsacks), weightList(weightList),
		profitList(profitList), capacityList(capacityList) {

	if (profitList.size() != numItems) throw std::invalid_argument("Size of profit list not equal to numItems");
	if (weightList.size() != numItems) throw std::invalid_argument("Size of weight list not equal to numItems");
	if (capacityList.size() != numKnapsacks) throw std::invalid_argument("Size of capacity list not equal to numKnapsacks");

}

Instance::~Instance() {
	// TODO Auto-generated destructor stub
}

