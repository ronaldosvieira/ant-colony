/*
 * InstanceTest.h
 *
 *  Created on: Nov 20, 2015
 *      Author: Ronaldo
 */

#ifndef SRC_INSTANCETEST_H_
#define SRC_INSTANCETEST_H_

#include "cute.h"

#include "../model/Instance.h"

class InstanceTest {
public:
   InstanceTest();
   virtual ~InstanceTest();

    void operator()();

private:
    void testWrongNumItems();
    void testWrongNumKnapsacks();

    void initialize(int &nI, int &nK, std::vector<int> &wL,
			std::vector<int> &pL, std::vector<int> &cL);
};

#endif /* SRC_INSTANCETEST_H_ */
