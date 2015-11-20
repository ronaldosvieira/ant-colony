/*
 * Instance.h
 *
 *  Created on: Nov 5, 2015
 *      Author: Ronaldo
 */

#ifndef INSTANCE_H_
#define INSTANCE_H_

#include <vector>
#include <stdexcept>

class Instance {
public:
	int numItems;
	int numKnapsacks;
	std::vector<int> weightList;
	std::vector<int> profitList;
	std::vector<int> capacityList;

	Instance(int &numItems, int &numKnapsacks, std::vector<int> &weightList,
			std::vector<int> &profitList, std::vector<int> &capacityList);
	virtual ~Instance();
};

#endif /* INSTANCE_H_ */
