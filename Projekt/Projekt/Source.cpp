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
	
	sfmlMAIN(board);
	{
		MicroVector<int> tester{ 5 };
		int i = 0, j = 5, c = 2;
		tester.push_back(i);
		tester.push_back(j);
		tester.push_back(c);
		tester.push_back(c);
		tester.push_back(c);
		tester.push_back(c);
		std::cout << tester[3];
	}
	_CrtDumpMemoryLeaks();
	return 0;
}