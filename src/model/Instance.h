/*
 * Instance.h
 *
 *  Created on: Nov 5, 2015
 *      Author: Ronaldo
 */

#ifndef INSTANCE_H_
#define INSTANCE_H_

#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <fstream>

class Instance {
public:
	int numItems;
	int numKnapsacks;
	std::vector<int> weightList;
	std::vector<int> profitList;
	std::vector<int> capacityList;

	Instance(int &numItems, int &numKnapsacks, std::vector<int> &weightList,
			std::vector<int> &profitList, std::vector<int> &capacityList);
	Instance(std::string fileName);
	virtual ~Instance();
private:
	void split(const std::string& s, char delim, std::vector<std::string>& v);
};

#endif /* INSTANCE_H_ */
