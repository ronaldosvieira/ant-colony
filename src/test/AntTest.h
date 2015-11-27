/*
 * AntTest.h
 *
 *  Created on: Nov 26, 2015
 *      Author: Ronaldo
 */

#ifndef SRC_TEST_ANTTEST_H_
#define SRC_TEST_ANTTEST_H_

#include "cute.h"

#include "../model/Ant.h"
#include "../model/Solution.h"

class AntTest {
private:
	Ant initialize();

	void testGetSolution();
	void testGetValue();
	void testIterate();
public:
	AntTest();
	virtual ~AntTest();

	void operator()();
};


#endif /* SRC_TEST_ANTTEST_H_ */
