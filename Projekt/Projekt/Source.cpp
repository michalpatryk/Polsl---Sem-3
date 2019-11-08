#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "graphicHandle.h"
#define HEIGHT 800
#define WIDTH 800
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main() 
{
	Board board;
	
	sfmlMAIN(board);
	

	std::cout << "Test";
	_CrtDumpMemoryLeaks();
	return 0;
}