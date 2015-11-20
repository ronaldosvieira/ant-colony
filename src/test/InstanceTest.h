/*
 * InstanceTest.h
 *
 *  Created on: Nov 20, 2015
 *      Author: Ronaldo
 */

#ifndef SRC_INSTANCETEST_H_
#define SRC_INSTANCETEST_H_

#include <iostream>

#include "cute.h"

#include "../model/Instance.h"

class InstanceTest {
public:
   InstanceTest();
   virtual ~InstanceTest();
    // Must define void operator() with no arguments.
    // In implementation: add calls to cute-assert functions and methods like someFunction1
    void operator()();

private:
    // Whatever methods you need
    void testWrongNumItems();
    void initialize(int &nI, int &nK, std::vector<int> &wL,
			std::vector<int> &pL, std::vector<int> &cL);
};

#endif /* SRC_INSTANCETEST_H_ */
