#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>

int main()
{
    std::cout << "Hello World!\n"; 
	_CrtDumpMemoryLeaks();	//sprawdzanie wycieków pamięci
	return 0;
}

