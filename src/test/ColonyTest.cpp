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
	testNumAnts();
}

void ColonyTest::testGetSolutionValues() {}
void ColonyTest::testResetPheromoneList() {}
void ColonyTest::testNumAnts() {}

Colony ColonyTest::initialize(Instance inst, int numAnts = 1.0,
		double evaporationRatio = 0.5, double alfa = 1.0, double beta = 1.0) {
	return Colony(inst, numAnts, evaporationRatio, alfa, beta);
}
