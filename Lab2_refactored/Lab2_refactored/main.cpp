#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include "Punkt.h"
#include "tablica.h"

int main()
{
	
	//Testowanie Punkt
	Punkt p1{ 10, 5 }, p2{ 10, 15 };
	std::cout << "p1: " << p1 << ", p2: " << p2 << std::endl;// <<

	p1 += p2;	//+=
	std::cout << "p1: " << p1 << std::endl;
	p1 = p1 + p2;	//+
	std::cout << "p1 :" << p1 << std::endl;
	p2 = p1;	//=
	std::cout << "p2: " << p2 << std::endl;
	if (p1 == p2) std::cout << "p1 == p2" << std::endl;	//==
	//Testowanie Tablica
	{	//Indentacja pozwala na automatyczne wywołanie destruktorów obiektu Tablica
		Tablica t1{ 5 };
		float x[10] = { 1,2,3,4,5,6,7,8,9,10 };
		float y[10] = { 10,9,8,7,6,5,4,3,2,1 };
		Tablica t2{ x, y, 10 };
		Tablica t3{ y, y, 10 };
	}
	_CrtDumpMemoryLeaks();	//sprawdzanie wycieków pamięci
	return 0;
}
