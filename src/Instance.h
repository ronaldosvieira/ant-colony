/*
 * Instance.h
 *
 *  Created on: Nov 5, 2015
 *      Author: Ronaldo
 */

#ifndef INSTANCE_H_
#define INSTANCE_H_

#include <vector>

using namespace std;

class Instance {
public:
	int numItems;
	int numKnapsacks;
	vector<int> weightList;
	vector<int> profitList;
	vector<int> capacityList;

	Instance();
	virtual ~Instance();
};

#endif /* INSTANCE_H_ */
