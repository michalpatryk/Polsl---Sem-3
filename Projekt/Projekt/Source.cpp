#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "graphicHandle.h"
#include "microVector.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main() 
{
	Board board;//dont comment
	
	//sfmlMAIN(board);
	{
		MicroVector<int> tester{};
		int i = 0, j = 5, c = 2;
		tester.push_back(i);
		tester.push_back(j);
		tester.push_back(c);
		tester.push_back(c);
		tester.push_back(c);
		tester.push_back(c);
		std::cout << tester[3];
		MicroVector<int> test2(8);
		//std::vector<std::vector<int>> varr(8, std::vector<int>(8));
	//	MicroVector<MicroVector<int>> test3(8, <int>(3));

	}
	_CrtDumpMemoryLeaks();
	return 0;
}