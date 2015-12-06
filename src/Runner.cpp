/*
 * Runner.cpp
 *
 *  Created on: Dec 5, 2015
 *      Author: Ronaldo
 */

#include "model/Instance.h"
#include "model/Solution.h"
#include "model/Ant.h"
#include "model/Colony.h"
#include "model/util/InstanceGenerator.h"

#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"

#include "test/InstanceTest.h"
#include "test/SolutionTest.h"
#include "test/AntTest.h"
#include "test/ColonyTest.h"

#include <iostream>
#include <ctime>

constexpr auto TEST = 0;

void runSuite(){
    cute::suite s;

    s.push_back(InstanceTest());
    s.push_back(SolutionTest());
    s.push_back(AntTest());
    s.push_back(ColonyTest());

    cute::ide_listener<> lis;
    cute::makeRunner(lis)(s, "Instance class tests");
}

Instance openInstance(std::string fileName) {
	try {
		return Instance("./src/instances/" + fileName);
	} catch (std::invalid_argument &e) {
		std::cout << "Problem in instance " << fileName << ":\n";
		std::cout << e.what() << "\n";
	}
}

void printResults(std::vector<long> values) {
	int best = 0;
	long mean = 0;

	for (int i = 0; i < values.size(); ++i) {
		if (values.at(i) > best) best = values.at(i);

		mean += values.at(i);

		std::cout << values.at(i) << " ";
		if ((i + 1) % 20 == 0) std::cout << "\n";
	}

	mean /= values.size();

	std::cout << "\nBest: " << best << "\n";
	std::cout << "Mean: " << mean << "\n";
}

void run() {
	//Instance inst1 = InstanceGenerator::generate(30, 10);
	Instance p01("./src/instances/p01.dat");

	//system("pause");

	int numAnts = 50;

	Colony col(p01, numAnts, 0.05, 2.0, 1.0);
	Solution best = col.run();

	//printResults(col.getSolutionValues());

	std::cout << "Really best solution: " << best.getValue() << "\n";
	std::cout << best.toString() << "\n";
}

int main(int argc, char **argv) {
	srand(time(NULL));

	if (TEST) runSuite();
	else {
		try {run();}
		catch (std::exception &e) {
			std::cout << "Error: " << e.what() << "\n";
		}
	}
}
