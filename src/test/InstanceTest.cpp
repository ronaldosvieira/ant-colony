/*
 * InstanceTest.cpp
 *
 *  Created on: Nov 20, 2015
 *      Author: Ronaldo
 */

#include "InstanceTest.h"

InstanceTest::InstanceTest() {}

InstanceTest::~InstanceTest() {}

void InstanceTest::operator()() {
	testWrongNumItems();
}

void InstanceTest::testWrongNumItems() {
    int nI = 2;
	int nK = 3;

	std::vector<int> wL;
	wL.push_back(5);
	wL.push_back(5);

	std::vector<int> pL;
	pL.push_back(5);
	pL.push_back(5);

	std::vector<int> cL;
	cL.push_back(5);
	cL.push_back(5);
	cL.push_back(5);

	ASSERT_THROWS(initialize(nI, nK, wL, pL, cL), std::invalid_argument);
}

void InstanceTest::initialize(int &nI, int &nK, std::vector<int> &wL,
			std::vector<int> &pL, std::vector<int> &cL) {
	try {
		Instance inst(nI, nK, wL, pL, cL);
	} catch (std::invalid_argument &e) {
		throw;
	}
}
