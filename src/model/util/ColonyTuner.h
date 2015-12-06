/*
 * ColonyTuner.h
 *
 *  Created on: Dec 5, 2015
 *      Author: Ronaldo
 */

#ifndef SRC_MODEL_COLONYTUNER_H_
#define SRC_MODEL_COLONYTUNER_H_

#include "../Instance.h"
#include "../Solution.h"
#include "../Ant.h"
#include "../Colony.h"

#include <iostream>
#include <vector>
#include <cmath>

constexpr auto NUM_RUNS = 10;

class ColonyTuner {
public:
	ColonyTuner(Instance &inst, int numAnts);
	virtual ~ColonyTuner();

	Colony test();
private:
	Instance &inst;
	Colony col;
	int numAnts;

	double bestEvaporationRatio;
	double bestAlpha;
	double bestBeta;

	long getBest(std::vector<long> values);
	double getMean(std::vector<long> values);
	double run(double evaporationRatio, double alpha, double beta);
};

#endif /* SRC_MODEL_COLONYTUNER_H_ */
