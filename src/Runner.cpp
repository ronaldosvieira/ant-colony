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
#include "model/util/ColonyTuner.h"

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
	std::cout << "Mean: " << mean << "\n\n";
}

void generateInstances() {
	std::vector<int> items { 25, 50, 100, 200 };
	std::vector<int> knaps { 2, 3, 4 };
	std::stringstream path;
	for (int k = 0; k < knaps.size(); ++k) {
		for (int it = 0; it < items.size(); ++it) {
			for (int in = 0; in < 20; ++in) {
				path.clear();
				path.str(std::string());
				path << "./src/instances/weakly_correlated/" << knaps.at(k)
						<< "k" << items.at(it) << "i_" << (in + 1) << ".dat";
				InstanceGenerator::generate(path.str(), items.at(it), knaps.at(k), 1, 1);
			}
		}
	}
}

void getStats(Colony &col, int amount, long optimal) {
	int foundOptimal = 0;

	for (int i = 0; i < amount; ++i) {
		Solution best = col.run();

		if (best.getValue() == optimal) foundOptimal++;

		std::cout << "Run " << i << ": " << best.getValue() << std::endl;
	}

	std::cout << "Found optimal " << 100.0 * foundOptimal / amount
			<< "% of the " << amount << " runs. (" << foundOptimal
			<< "/" << amount << ")" << std::endl;
}

void run() {
	//Instance inst1 = InstanceGenerator::generate("./src/instances/test", 25, 3, 0, 0);

	//generateInstances();

	int numAnts = 100;

	std::string path = "./src/instances/weakly_correlated/10k25i.dat";
	//Instance inst = InstanceGenerator::generate(path, 25, 10, 1, 1);

	Instance inst(path);
	Colony col(inst, numAnts, 0.95, 2.0, 1.0);
	getStats(col, 10, inst.getOptimal());

	//ColonyTuner cT(inst1, numAnts);
	//Colony col = cT.test();

	//Solution best = col.run();

	//printResults(col.getSolutionValues());

	//std::cout << "Best solution found: " << best.getValue() << "\n";
	//std::cout << "Optimal value: " << inst.getOptimal() << "\n";
	//std::cout << best.toString() << "\n";
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
