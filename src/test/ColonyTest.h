/*
 * ColonyTest.h
 *
 *  Created on: Nov 29, 2015
 *      Author: Ronaldo
 */

#ifndef SRC_TEST_COLONYTEST_H_
#define SRC_TEST_COLONYTEST_H_

#include "cute.h"

#include <iostream>
#include "../model/Colony.h"

class ColonyTest {
public:
	ColonyTest();
	virtual ~ColonyTest();

	void operator()();
private:
	void testGetSolutionValues();
	void testResetPheromoneList();
	void testRun();

	Colony initialize(int numAnts = 1,
			double evaporationRatio = 0.5, double alfa = 1.0,
			double beta = 1.0);
};

#endif /* SRC_TEST_COLONYTEST_H_ */
