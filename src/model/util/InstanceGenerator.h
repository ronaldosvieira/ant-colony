/*
 * InstanceGenerator.h
 *
 *  Created on: Dec 6, 2015
 *      Author: Ronaldo
 */

#ifndef SRC_INSTANCES_INSTANCEGENERATOR_H_
#define SRC_INSTANCES_INSTANCEGENERATOR_H_

#define DEBUG_BUILD
//#undef DEBUG_BUILD

#ifdef DEBUG_BUILD
#define DEBUG(x) std::cout << x
#else
#  define DEBUG(x) do {} while (0)
#endif

#include "../Instance.h"

#include <cmath>

constexpr auto UNIFORM_MIN = 10;
constexpr auto UNIFORM_MAX = 100;

class InstanceGenerator {
public:
	InstanceGenerator();
	virtual ~InstanceGenerator();

	static Instance generate(int numItems, int numKnapsacks) {
		rand(); rand();

		std::vector<int> wL;
		std::vector<int> pL;
		std::vector<int> cL;

		DEBUG("Generating instance\n");
		DEBUG("with i = " << numItems << " and k = " << numKnapsacks << "\n\n");

		for (int i = 0; i < numItems; ++i) {
			wL.push_back((rand() % (UNIFORM_MAX - UNIFORM_MIN)) + UNIFORM_MIN);
			pL.push_back((rand() % (UNIFORM_MAX - UNIFORM_MIN)) + UNIFORM_MIN);
		}

		DEBUG("wL: ");

		for (int i = 0; i < numItems; ++i) {
			DEBUG(wL.at(i) << " ");
		}

		DEBUG("\n");

		DEBUG("pL: ");

		for (int i = 0; i < numItems; ++i) {
			DEBUG(pL.at(i) << " ");
		}

		DEBUG("\n");

		double capacityMinBound = UNIFORM_MIN;
		double capacityMaxBound[numKnapsacks];
		double weightListSum = 0.0;

		for (int i = 0; i < numItems; ++i) {
			weightListSum += wL.at(i);
		}

		DEBUG("cL: ");

		for (int k = 0; k < numKnapsacks; ++k) {
			capacityMaxBound[k] = 0.5 * weightListSum;

			for (int k2 = 0; k2 < k; ++k2) {
				capacityMaxBound[k] -= cL.at(k2);
			}

			cL.push_back(rand() % ((int) (capacityMaxBound[k] - capacityMinBound)) + capacityMinBound);

			DEBUG(cL.at(k) << " ");
		}
		DEBUG("\n\n");

		return Instance(numItems, numKnapsacks, wL, pL, cL);
	}
};

#endif /* SRC_INSTANCES_INSTANCEGENERATOR_H_ */
