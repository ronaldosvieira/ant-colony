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

#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"

#include "test/InstanceTest.h"
#include "test/SolutionTest.h"
#include "test/AntTest.h"
#include "test/ColonyTest.h"

#include <iostream>

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

void run() {
	Instance sento1 = openInstance("sento1.dat");
	int numAnts = 100;

	Colony col(sento1, numAnts, 0.5, 1.0, 2.0);
	col.run();
	std::vector<long> values = col.getSolutionValues();

	int best = 0;
	long sum = 0;
	for (int i = 0; i < numAnts; ++i) {
		//std::cout << "Ant " << i << ": " << values.at(i) << "\n";
		if (values.at(i) > best) best = values.at(i);
		sum += values.at(i);
		std::cout << values.at(i) << " ";
		if ((i + 1) % 20 == 0) std::cout << "\n";
	}

	std::cout << "\nBest: " << best << "\n";
	std::cout << "Mean: " << sum / numAnts << "\n";

}

int main(int argc, char **argv) {
	if (TEST) runSuite();
	else {
		try {run();}
		catch (std::exception &e) {
			std::cout << "deu merda: " << e.what() << "\n";
		}
	}
}
