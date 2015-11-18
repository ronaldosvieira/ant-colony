/*
 * Colony.cpp
 *
 *  Created on: Nov 7, 2015
 *      Author: Ronaldo
 */

#include "Colony.h"

namespace std {

Colony::Colony(int numAnts, double evaporationRatio, double alfa , double beta) :
	numAnts(numAnts), evaporationRatio(evaporationRatio), alfa(alfa), beta(beta) {
	populate();
}

Colony::~Colony() {

}

void Colony::populate() {
	for (int i = 0; i < numAnts; ++i) {
		//ants.push_back(Ant(&inst));
	}
}

} /* namespace std */
