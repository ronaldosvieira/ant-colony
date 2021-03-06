/*
 * AntTest.cpp
 *
 *  Created on: Nov 26, 2015
 *      Author: Ronaldo
 */

#include "AntTest.h"
#include <iostream>

AntTest::AntTest() {
	// TODO Auto-generated constructor stub

}

AntTest::~AntTest() {
	// TODO Auto-generated destructor stub
}

void AntTest::operator()() {
	testGetSolution();
	testGetValue();
	testIterate();
}

void AntTest::testGetSolution() {
	Ant ant = initialize();
	Solution sol = ant.getSolution();

	ASSERT(dynamic_cast<Solution*>(&sol));
	ASSERT_EQUAL(0, sol.getValue());
}

void AntTest::testGetValue() {
	Ant ant = initialize();

	ASSERT_EQUAL(0, ant.getValue());
}

void AntTest::testIterate() {
	srand(time(NULL));
	int nI = 2;
	int nK = 3;

	std::vector<int> wL{5, 6};

	std::vector<int> pL;
	pL.push_back(5);
	pL.push_back(6);

	std::vector<int> cL;
	cL.push_back(7);
	cL.push_back(8);
	cL.push_back(9);

	Instance inst(nI, nK, wL, pL, cL);

	std::vector<std::vector<double>> pheromoneList;
	pheromoneList.at(0).push_back(0.5);
	pheromoneList.at(0).push_back(0.5);
	pheromoneList.at(1).push_back(0.5);
	pheromoneList.at(1).push_back(0.5);
	pheromoneList.at(2).push_back(0.5);
	pheromoneList.at(2).push_back(0.5);

	double alpha = 1.0;
	double beta = 1.0;

	Ant ant(inst, pheromoneList, alpha, beta);

	ant.iterate();
	ASSERT_NOT_EQUAL_TO(0, ant.getValue());
}

Ant AntTest::initialize() {
	int nI = 2;
	int nK = 3;

	std::vector<int> wL{5, 6};

	std::vector<int> pL;
	pL.push_back(5);
	pL.push_back(6);

	std::vector<int> cL;
	cL.push_back(7);
	cL.push_back(8);
	cL.push_back(9);

	Instance inst(nI, nK, wL, pL, cL);

	std::vector<std::vector<double>> pheromoneList;
	pheromoneList.at(0).push_back(0.5);
	pheromoneList.at(0).push_back(0.5);
	pheromoneList.at(1).push_back(0.5);
	pheromoneList.at(1).push_back(0.5);
	pheromoneList.at(2).push_back(0.5);
	pheromoneList.at(2).push_back(0.5);

	double alpha = 1.0;
	double beta = 1.0;

	return Ant(inst, pheromoneList, alpha, beta);
}
