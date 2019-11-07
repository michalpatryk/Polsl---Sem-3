﻿#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include "Wektor.h"
#include "Tablica.h"
#include "Punkt.h"
int main()
{
    std::cout << "Hello World!\n"; 

	Wektor w1{}, w2{ 10,20 };
	w1.drukuj();
	w2.drukuj();

	Tablica<Punkt>{ 5 };
	_CrtDumpMemoryLeaks();	//sprawdzanie wycieków pamięci
	return 0;
}
