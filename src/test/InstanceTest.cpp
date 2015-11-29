/*
 * InstanceTest.cpp
 *
 *  Created on: Nov 20, 2015
 *      Author: Ronaldo
 */

#include "InstanceTest.h"

InstanceTest::InstanceTest() {}

InstanceTest::~InstanceTest() {}

void InstanceTest::operator()() {
	testWrongNumItems();
	testWrongNumKnapsacks();
	testReadFromFile();
	testReadFromNonExistentFile();
	testReadFromWrongFile();
}

void InstanceTest::testWrongNumItems() {
    int nI = 0;
	int nK = 3;

	std::vector<int> wL;
	wL.push_back(5);
	wL.push_back(5);

	std::vector<int> pL;
	pL.push_back(5);
	pL.push_back(5);

	std::vector<int> cL;
	cL.push_back(5);
	cL.push_back(5);
	cL.push_back(5);

	ASSERT_THROWS(initialize(nI, nK, wL, pL, cL), std::invalid_argument);
}

void InstanceTest::testWrongNumKnapsacks() {
    int nI2 = 2;
	int nK2 = 0;

	std::vector<int> wL2;
	wL2.push_back(5);
	wL2.push_back(5);

	std::vector<int> pL2;
	pL2.push_back(5);
	pL2.push_back(5);

	std::vector<int> cL2;
	cL2.push_back(5);
	cL2.push_back(5);
	cL2.push_back(5);

	ASSERT_THROWS(initialize(nI2, nK2, wL2, pL2, cL2), std::invalid_argument);
}

void InstanceTest::testReadFromFile() {
	std::ofstream testFile;
	testFile.open("./src/test/instance01.txt");
	testFile << "30 60\n";
	testFile << "2 77 6 67 930 3 6 270 33 13 ";
	testFile << "110 21 56 974 47 734 238 75 200 51 ";
	testFile << "47 63 7 6 468 72 95 82 91 83 ";
	testFile << "27 13 6 76 55 72 300 6 65 39 ";
	testFile << "63 61 52 85 29 640 558 53 47 25 ";
	testFile << "3 6 568 6 2 780 69 31 774 22\n";
	testFile << "6000 6000 6000 6000 6000 6000 6000 6000 6000 4000 ";
	testFile << "6000 6000 6000 6000 6000 6000 6000 6000 6000 4000 ";
	testFile << "6000 6000 6000 6000 6000 6000 6000 6000 6000 4000\n";
	testFile << "47 774 76 56 59 22 42 1 21 760 ";
	testFile << "818 62 42 36 785 29 662 49 608 116 ";
	testFile << "834 57 42 39 994 690 27 524 23 96 ";
	testFile << "667 490 805 46 19 26 97 71 699 465 ";
	testFile << "53 26 123 20 25 450 22 979 75 96 ";
	testFile << "27 41 21 81 15 76 97 646 898 37\n";
	testFile.close();

	try {
		Instance inst("./src/test/instance01.txt");
		remove("./src/test/instance01.txt");
	} catch (std::invalid_argument &e) {
		FAIL();
	}
}

void InstanceTest::testReadFromNonExistentFile() {
	ASSERT_THROWS(Instance("non_existent.txt"), std::invalid_argument);
}

void InstanceTest::testReadFromWrongFile() {
	std::ofstream testFile;
	testFile.open("./src/test/instance02.txt");
	testFile << "30 60\n";
	testFile << "2 77 6 67 930 3 6 270 33 13 ";
	testFile << "110 21 56 974 47 734 238 75 200 51 ";
	testFile << "47 63 7 6 468 72 95 82 91 83 ";
	testFile << "27 13 6 76 55 72 300 6 65 39 ";
	testFile << "63 61 52 85 29 640 558 53 47 25 ";
	testFile << "3 6 568 6 2 780 69 31 774\n";
	testFile << "6000 6000 6000 6000 6000 6000 6000 6000 6000 4000 ";
	testFile << "6000 6000 6000 6000 6000 6000 6000 6000 6000 4000 ";
	testFile << "6000 6000 6000 6000 6000 6000 6000 6000 6000 4000\n";
	testFile << "47 774 76 56 59 22 42 1 21 760 ";
	testFile << "818 62 42 36 785 29 662 49 608 116 ";
	testFile << "834 57 42 39 994 690 27 524 23 96 ";
	testFile << "667 490 805 46 19 26 97 71 699 465 ";
	testFile << "53 26 123 20 25 450 22 979 75 96 ";
	testFile << "27 41 21 81 15 76 97 646 898 37\n";
	testFile.close();

	ASSERT_THROWS(Instance("./src/test/instance02.txt"), std::invalid_argument);

	remove("./src/test/instance02.txt");
}

Instance InstanceTest::initialize(int &nI, int &nK, std::vector<int> &wL,
			std::vector<int> &pL, std::vector<int> &cL) {
	try {
		return Instance(nI, nK, wL, pL, cL);
	} catch (std::invalid_argument &e) {
		throw;
	}
}
