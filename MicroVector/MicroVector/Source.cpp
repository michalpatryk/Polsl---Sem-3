#include "MicroVector.h"
#include <vector>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
int main() {
	{
		// ? Why is destructor called
		MicroVector<int> tester{};
		MicroVector<int> tester2();	// It doesnt show up in locals???
		//MicroVector<int> tester3;		//AND THIS CRASHES ALL
		int i = 0, j = 5, c = 2;
	//	tester.push_back(i);
	//	tester.push_back(j);
	//	tester.push_back(c);
	//	tester.push_back(c);
	//	tester.push_back(c);
	//	tester.push_back(c);
	//	std::cout << tester[3];
	//	MicroVector<int> test2(8);
		//std::vector<std::vector<int>> varr(8, std::vector<int>(8));
	//	MicroVector<MicroVector<int>> test3(8, MicroVector<int>(3));
		//MicroVector<MicroVector<int>> test3(8, i);
		MicroVector<MicroVector<int>> test3(5, (3));		//calls destructor upon initializaion ???

	}
	_CrtDumpMemoryLeaks();
	return 0;
}