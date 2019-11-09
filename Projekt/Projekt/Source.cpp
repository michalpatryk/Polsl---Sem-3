#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "graphicHandle.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main() 
{
	Board board;
	
	sfmlMAIN(board);
	

	_CrtDumpMemoryLeaks();
	return 0;
}