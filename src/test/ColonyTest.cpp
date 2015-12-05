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
	testRun();
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

void ColonyTest::testRun() {
	Colony col = initialize(5, 0.5, 1.0, 1.0);

	col.run();

	std::vector<long> values = col.getSolutionValues();

	for (int i = 0; i < 5; ++i) {
		std::cout << "Ant " << i << ": " << values.at(i) << "\n";
		ASSERT_NOT_EQUAL_TO(0, values.at(i));
	}
}

Colony ColonyTest::initialize(int numAnts,
		double evaporationRatio, double alfa, double beta) {
	int nI{2};
	int nK{2};
	std::vector<int> wL1{5, 6};
	std::vector<int> wL2{5, 6};
	std::vector<std::vector<int>> wL{wL1, wL2};
	std::vector<int> pL{5, 6};
	std::vector<int> cL{7, 7};

	return Colony(Instance(nI, nK, wL, pL, cL),
			numAnts, evaporationRatio, alfa, beta);
}
