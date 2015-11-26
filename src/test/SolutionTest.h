/*
 * Solution.h
 *
 *  Created on: Nov 20, 2015
 *      Author: Ronaldo
 */

#ifndef SRC_TEST_SOLUTIONTEST_H_
#define SRC_TEST_SOLUTIONTEST_H_

#include "cute.h"

#include "../model/Solution.h"
#include "../model/Instance.h"

class SolutionTest {
public:
   SolutionTest();
   virtual ~SolutionTest();

    void operator()();

private:
    void testEmpty();
    void testUpdate();
    void testGetValue();
    void testGetRemainingCapacityList();
    void testIsValidUpdate();
    void testIsSelected();
    void testToString();

    Solution initialize();
};

#endif /* SRC_TEST_SOLUTIONTEST_H_ */
