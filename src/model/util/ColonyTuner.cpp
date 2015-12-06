/*
 * ColonyTuner.cpp
 *
 *  Created on: Dec 5, 2015
 *      Author: Ronaldo
 */

#include "ColonyTuner.h"

#define DEBUG_BUILD
//#undef DEBUG_BUILD

#ifdef DEBUG_BUILD
#  define DEBUG(x) std::cout << x
#else
#  define DEBUG(x) do {} while (0)
#endif

ColonyTuner::ColonyTuner(Instance &inst, int numAnts) : inst(inst),
numAnts(numAnts), col(inst, numAnts), bestAlpha(0.1), bestBeta(0.1),
bestEvaporationRatio(0.1) {}

ColonyTuner::~ColonyTuner() {}

Colony ColonyTuner::test() {
	double best = 0.0;
	double current;

	DEBUG("Initializing tests...\n");

	for (double e = 0.1; e < 1.0; e += 0.1) {
		DEBUG("EvaporationRatio = " << e << "\n");
		for (double diff = 2.0; diff >= 0; diff -= 0.2) {
			DEBUG("Alpha = " << diff << "\n");
			DEBUG("Beta = " << 2.0 - diff << "\n");

			current = run(e, abs(diff), abs(2.0 - diff));

			if (current > best) {
				DEBUG("---> Found new best! <---\n");

				best = current;
				bestEvaporationRatio = e;
				bestAlpha = diff;
				bestBeta = 2.0 - diff;
			}
		}
	}

	DEBUG("Tuning is done!\n");
	DEBUG("EvaporationRatio = " << bestEvaporationRatio << "\n");
	DEBUG("Alpha = " << bestAlpha << "\n");
	DEBUG("Beta = " << bestBeta << "\n");

	return Colony(inst, numAnts, bestEvaporationRatio, bestAlpha, bestBeta);
}

double ColonyTuner::run(double evaporationRatio, double alpha, double beta) {
	std::vector<long> values;

	//this->col.setEvaporationRatio(evaporationRatio);
	//this->col.setAlpha(alpha);
	//this->col.setBeta(beta);

	this->col.~Colony();
	new (&this->col) Colony(inst, numAnts, evaporationRatio, alpha, beta);

	for (int i = 0; i < NUM_RUNS; ++i) {
		this->col.run();
		values.push_back(getBest(this->col.getSolutionValues()));
	}
	std::cout << getMean(values) << "\n";
	return getMean(values);
}

long ColonyTuner::getBest(std::vector<long> values) {
	long best = 0;

	for (int i = 0; i < values.size(); ++i) {
		if (values.at(i) > best) best = values.at(i);
	}

	return best;
}

double ColonyTuner::getMean(std::vector<long> values) {
	double sum = 0;

	for (int i = 0; i < values.size(); ++i) {
		sum += values.at(i);
	}

	return sum / values.size();
}
