/*
 * Test.cpp
 *
 *  Created on: Nov 20, 2015
 *      Author: Ronaldo
 */

#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"

#include "InstanceTest.h"
#include "SolutionTest.h"

void runSuite(){
    cute::suite s;

    s.push_back(InstanceTest());
    s.push_back(SolutionTest());

    cute::ide_listener<> lis;
    cute::makeRunner(lis)(s, "Instance class tests");
}

int main(){
    runSuite();
}
