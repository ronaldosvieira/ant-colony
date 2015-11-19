//============================================================================
// Name        : ant-colony.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Instance.h"
#include "Solution.h"
#include "Colony.h"
using namespace std;

int main() {
	Instance in;
	in.numItems = 2;
	in.numKnapsacks = 2;

	in.capacityList.push_back(10);
	in.capacityList.push_back(10);

	in.profitList.push_back(5);
	in.profitList.push_back(5);

	in.weightList.push_back(12);
	in.weightList.push_back(1);

	Colony col(1, 1.0, 1.0, 1.0);

	Solution sol(&in);
	cout << sol.toString() << endl;
	sol.update(1, 1);
	cout << sol.toString() << endl;
	cout << sol.isValid() << endl;

	cout << in.profitList.at(0) << endl;
	cout << in.profitList.at(1) << endl;

	col.run();

	return 0;
}
