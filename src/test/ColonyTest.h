/*
 * ColonyTest.h
 *
 *  Created on: Nov 29, 2015
 *      Author: Ronaldo
 */

#ifndef SRC_TEST_COLONYTEST_H_
#define SRC_TEST_COLONYTEST_H_

#include "cute.h"

#include "../model/Colony.h"

class ColonyTest {
public:
	ColonyTest();
	virtual ~ColonyTest();

	void operator()();
private:
	void testGetSolutionValues();
	void testResetPheromoneList();
	void testNumAnts();

	Colony initialize(Instance inst, int numAnts,
			double evaporationRatio, double alfa, double beta);
};

#endif /* SRC_TEST_COLONYTEST_H_ */
