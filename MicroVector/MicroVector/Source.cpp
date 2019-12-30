#include "MicroVector.h"
#include <vector>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
int main() {
	{
		// ? Why is destructor called
		MicroVector<int> tester{};
	//	MicroVector<int> tester2();	// It doesnt show up in locals???
		//MicroVector<int> tester3;		//AND THIS CRASHES ALL
		int i = 3, j = 5, c = 2;
		tester.push_back(i);
		tester.push_back(j);
		tester.push_back(c);
		tester.push_back(c);
		tester.push_back(c);
		tester.push_back(c);
		std::cout << tester[3];
	//	MicroVector<int> test2(8);
		//std::vector<std::vector<int>> varr(8, std::vector<int>(8));
	//	MicroVector<MicroVector<int>> test3(8, MicroVector<int>(3));
		//MicroVector<MicroVector<int>> test3(8, i);
		//MicroVector<MicroVector<int>> test3(5, (3));		//calls destructor upon initializaion ???
		MicroVector<MicroVector<int>> test4{ 5 };
		test4[1].push_back(c);
		test4[1].push_back(c);
		test4[1].push_back(c);
		test4[3].push_back(i);
		test4[2].push_back(j);
		test4[1].push_back(j);
		test4[1].push_back(j);
		test4[1].push_back(i);
		test4[1].push_back(i);
		test4[1].push_back(i);
		test4[1].push_back(i);
		test4[1].push_back(i);
		test4[1].push_back(i);
		test4[1].push_back(i);
		test4[1].push_back(i);
		int out1 = test4[0][0];
		int out2 = test4[1][1];
		int out3 = test4[1][2];
		int out4 = test4[1][3];
		int out5 = test4[1][4];
		std::cout << out1 << std::endl;
	}
	_CrtDumpMemoryLeaks();
	return 0;
}