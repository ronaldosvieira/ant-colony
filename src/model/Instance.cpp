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

	calcNormalizedProfitList();

	if (profitList.size() != numItems) throw std::invalid_argument("Size of profit list not equal to numItems");
	if (weightList.size() != numItems) throw std::invalid_argument("Size of weight list not equal to numItems");
	if (capacityList.size() != numKnapsacks) throw std::invalid_argument("Size of capacity list not equal to numKnapsacks");
}

Instance::Instance(const std::string fileName) {
	std::ifstream file;
	std::string line;
	std::vector<std::string> tokens;

	std::vector<int> all;
	int index = 0;

	DEBUG("\n");
	DEBUG("Opening file " << fileName << "...\n");

	file.open(fileName.c_str());
	if (!file.is_open()) throw std::invalid_argument("Couldn't open file" + fileName);

	DEBUG("File opened!\n");

	int temp;

	while (file >> temp) {
		all.push_back(temp);
	}

	DEBUG("Closing file...\n");

	file.close();

	DEBUG("Reading numItems and numKnapsacks...\n");

	// read numItems and numKnapsacks
	this->numKnapsacks	= all.at(index++);
	this->numItems	 	= all.at(index++);

	DEBUG("numItems     = " << this->numItems << "\n");
	DEBUG("numKnapsacks = " << this->numKnapsacks << "\n");

	DEBUG("Reading profitList...\n");

	// read profitList
	for (int i = 0; i < this->numItems; ++i) {
		this->profitList.push_back(all.at(index++));
	}

	DEBUG("profitList.size() = " << this->profitList.size() << "\n");

	if (this->profitList.size() != numItems) {
		throw std::invalid_argument("Size of profit list not equal to numItems");
	}

	DEBUG("Reading capacityList...\n");

	// read capacityList
	for (int i = 0; i < this->numKnapsacks; ++i) {
		capacityList.push_back(all.at(index++));
	}

	DEBUG("capacityList.size() = " << this->capacityList.size() << "\n");

	if (this->capacityList.size() != numKnapsacks) {
		throw std::invalid_argument("Size of capacity list not equal to numKnapsacks");
	}

	DEBUG("Reading weightList...\n");

	// read weightList
	for (int i = 0; i < this->numItems; ++i) {
		this->weightList.push_back(all.at(index++));
	}

	DEBUG("weightList.size() = " << this->weightList.size() << "\n");

	if (this->weightList.size() != numItems) {
		throw std::invalid_argument("Size of weight list not equal to numItems");
	}

	DEBUG("Done!\n\n");
}

Instance::~Instance() {
	// TODO Auto-generated destructor stub
}

void Instance::split(const std::string& s, char delim, std::vector<std::string>& v) {
    auto i = 0;
    auto pos = s.find(delim);
    while (pos != std::string::npos) {
      v.push_back(s.substr(i, pos-i));
      i = ++pos;
      pos = s.find(delim, pos);

      if (pos == std::string::npos)
         v.push_back(s.substr(i, s.length()));
    }
}

std::vector<double> Instance::getNormalizedProfitList() {
	if (this->normalizedProfitList.size() <= 0) calcNormalizedProfitList();
	return this->normalizedProfitList;
}

std::vector<double> Instance::calcNormalizedProfitList() {
	int min = this->profitList.at(0);
	int max = 0;

	for (int i = 0; i < this->profitList.size(); i++) {
		if (this->profitList.at(i) < min) min = this->profitList.at(i);
		if (this->profitList.at(i) > max) max = this->profitList.at(i);
	}

	max -= min;

	for (int i = 0; i < this->profitList.size(); i++) {
		this->normalizedProfitList.push_back(1.0 * (this->profitList.at(i) - min) / max);
	}
}
