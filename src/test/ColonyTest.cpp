/*
 * ColonyTest.cpp
 *
 *  Created on: Nov 29, 2015
 *      Author: Ronaldo
 */

#include "ColonyTest.h"

ColonyTest::ColonyTest() {}

ColonyTest::~ColonyTest() {}

void ColonyTest::operator()() {
	testGetSolutionValues();
	testResetPheromoneList();
}

void ColonyTest::testGetSolutionValues() {
	Colony col = initialize();

	std::vector<long> values = col.getSolutionValues();

	for (int i = 0; i < values.size(); ++i) {
		ASSERT_EQUAL(0, values.at(i));
	}
}

void ColonyTest::testResetPheromoneList() {
	Colony col = initialize();

	std::vector<double> phL = col.getPheromoneList();

	for (int i = 0; i < phL.size(); ++i) {
		ASSERT_EQUAL(INITIAL_PHEROMONE_VALUE, phL.at(i));
	}
}

Colony ColonyTest::initialize(int numAnts,
		double evaporationRatio, double alfa, double beta) {
	int nI{2};
	int nK{2};
	std::vector<int> wL{5, 6};
	std::vector<int> pL{5, 6};
	std::vector<int> cL{7, 7};

	return Colony(Instance(nI, nK, wL, pL, cL),
			numAnts, evaporationRatio, alfa, beta);
}
