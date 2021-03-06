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

	std::vector<std::vector<double>> phL = col.getPheromoneList();

	for (int k = 0; k < phL.size(); ++k) {
		for (int i = 0; i < phL.at(k).size(); ++i) {
			ASSERT_EQUAL(INITIAL_PHEROMONE_VALUE, phL.at(k).at(i));
		}
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
	std::vector<int> wL{5, 6};
	std::vector<int> pL{5, 6};
	std::vector<int> cL{7, 7};

	Instance inst(nI, nK, wL, pL, cL);

	return Colony(inst, numAnts, evaporationRatio, alfa, beta);
}
