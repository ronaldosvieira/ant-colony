/*
 * Solution.cpp
 *
 *  Created on: Nov 20, 2015
 *      Author: Ronaldo
 */

#include "SolutionTest.h"

SolutionTest::SolutionTest() {}

SolutionTest::~SolutionTest() {}

void SolutionTest::operator() () {
	testEmpty();
	testUpdate();
	testGetValue();
}

void SolutionTest::testEmpty() {
	Solution sol = initialize();

	std::vector<int> rawSolution = sol.getRawSolution();

	ASSERT_EQUAL(2, rawSolution.size());
	ASSERT_EQUAL(-1, rawSolution.at(0));
	ASSERT_EQUAL(-1, rawSolution.at(1));
}

void SolutionTest::testUpdate() {
	Solution sol = initialize();

	sol.update(0, 0);

	ASSERT_EQUAL(0, sol.getRawSolution().at(0));
	ASSERT_EQUAL(-1, sol.getRawSolution().at(1));

	sol.update(1, 1);

	ASSERT_EQUAL(0, sol.getRawSolution().at(0));
	ASSERT_EQUAL(1, sol.getRawSolution().at(1));
}

void SolutionTest::testGetValue() {
	Solution sol = initialize();

	ASSERT_EQUAL(0, sol.getValue());

	sol.update(0, 1);
	ASSERT_EQUAL(5, sol.getValue());

	sol.update(1, 0);
	ASSERT_EQUAL(11, sol.getValue());
}

void SolutionTest::testGetRemainingCapacityList() {
	Solution sol = initialize();
	std::vector<int> rcl = sol.getRemainingCapacityList();

	ASSERT_EQUAL(7, rcl.at(0));
	ASSERT_EQUAL(7, rcl.at(1));
	ASSERT_EQUAL(7, rcl.at(2));

	sol.update(0, 0);
	ASSERT_EQUAL(2, rcl.at(0));
	ASSERT_EQUAL(7, rcl.at(1));
	ASSERT_EQUAL(7, rcl.at(2));

	sol.update(1, 1);
	ASSERT_EQUAL(2, rcl.at(0));
	ASSERT_EQUAL(1, rcl.at(1));
	ASSERT_EQUAL(7, rcl.at(2));
}

void SolutionTest::testIsValidUpdate() {
	Solution sol = initialize();

	ASSERT(sol.isValidUpdate(0, 0));
	sol.update(0, 0);

	ASSERT(!sol.isValidUpdate(1, 0));

	ASSERT(sol.isValidUpdate(1, 1));
	sol.update(1, 1);

	ASSERT(!sol.isValidUpdate(1, 2));

	ASSERT(!sol.isValidUpdate(0, 0));
}

void SolutionTest::testIsSelected() {
	Solution sol = initialize();

	ASSERT(!sol.isSelected(0));
	ASSERT(!sol.isSelected(1));

	sol.update(0, 0);
	sol.update(1, 2);

	ASSERT(sol.isSelected(0));
	ASSERT(sol.isSelected(1));
}

void SolutionTest::testToString() {
	Solution sol = initialize();

	ASSERT_EQUAL("--", sol.toString());

	sol.update(0, 2);

	ASSERT_EQUAL("2-", sol.toString());

	sol.update(1, 0);

	ASSERT_EQUAL("20", sol.toString());
}

Solution SolutionTest::initialize() {
	int nI = 2;
	int nK = 3;

	std::vector<int> wL1{5, 6};
	std::vector<int> wL2{5, 6};
	std::vector<int> wL3{5, 6};
	std::vector<std::vector<int>> wL{wL1, wL2, wL3};

	std::vector<int> pL;
	pL.push_back(5);
	pL.push_back(6);

	std::vector<int> cL;
	cL.push_back(7);
	cL.push_back(7);
	cL.push_back(7);

	Instance inst(nI, nK, wL, pL, cL);

	try {
		return Solution(inst);
	} catch (std::invalid_argument &e) {
		throw;
	}
}
