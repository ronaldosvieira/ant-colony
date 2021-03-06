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

#define DEBUG_BUILD
#undef DEBUG_BUILD

#ifdef DEBUG_BUILD
#define DEBUG(x) std::cout << x
#else
#  define DEBUG(x) do {} while (0)
#endif

class Instance {
public:
	int numItems;
	int numKnapsacks;
	std::vector<int> weightList;
	std::vector<int> profitList;
	std::vector<int> capacityList;

	long optimal;

	std::vector<double> normalizedProfitList;

	Instance(int &numItems, int &numKnapsacks, std::vector<int> &weightList,
			std::vector<int> &profitList, std::vector<int> &capacityList);
	Instance(std::string fileName);
	virtual ~Instance();
	std::vector<double> getNormalizedProfitList();

	const std::vector<int>& getCapacityList() const;
	int getNumItems() const;
	int getNumKnapsacks() const;
	long getOptimal() const;
	const std::vector<int>& getProfitList() const;
	const std::vector<int>& getWeightList() const;

private:
	void split(const std::string& s, char delim, std::vector<std::string>& v);
	std::vector<double> calcNormalizedProfitList();
};

#endif /* INSTANCE_H_ */
