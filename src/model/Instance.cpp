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

Instance::Instance(const std::string fileName) {
	std::ifstream file;
	std::string line;
	std::vector<std::string> tokens;

	DEBUG("\n");
	DEBUG("Opening file " << fileName << "...\n");

	file.open(fileName.c_str());
	if (!file.is_open()) throw std::invalid_argument("Couldn't open file" + fileName);

	DEBUG("File opened!\n");
	DEBUG("Reading numItems and numKnapsacks...\n");

	// read numItems and numKnapsacks
	getline(file, line);
	split(line, ' ', tokens);

	this->numItems 		= atoi(tokens.at(1).c_str());
	this->numKnapsacks 	= atoi(tokens.at(0).c_str());

	DEBUG("numItems     = " << this->numItems << "\n");
	DEBUG("numKnapsacks = " << this->numKnapsacks << "\n");

	line.clear();
	tokens.clear();

	DEBUG("Reading profitList...\n");

	// read profitList
	getline(file, line);
	split(line, ' ', tokens);

	for (int i = 0; i < tokens.size(); ++i) {
		this->profitList.push_back(atoi(tokens.at(i).c_str()));
	}

	DEBUG("profitList = " << line << "\n");

	if (this->profitList.size() != numItems) {
		throw std::invalid_argument("Size of profit list not equal to numItems");
	}

	line.clear();
	tokens.clear();

	DEBUG("Reading capacityList...\n");

	// read capacityList
	getline(file, line);
	split(line, ' ', tokens);

	for (int i = 0; i < tokens.size(); ++i) {
		capacityList.push_back(atoi(tokens.at(i).c_str()));
	}

	DEBUG("capacityList = " << line << "\n");

	if (this->capacityList.size() != numKnapsacks) {
		throw std::invalid_argument("Size of capacity list not equal to numKnapsacks");
	}

	line.clear();
	tokens.clear();

	DEBUG("Reading weightList...\n");

	// read weightList
	getline(file, line);
	split(line, ' ', tokens);

	for (int i = 0; i < tokens.size(); ++i) {
		weightList.push_back(atoi(tokens.at(i).c_str()));
	}

	DEBUG("weightList = " << line << "\n");

	if (this->weightList.size() != numItems) {
		throw std::invalid_argument("Size of weight list not equal to numItems");
	}

	DEBUG("Closing file...\n");

	file.close();

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
