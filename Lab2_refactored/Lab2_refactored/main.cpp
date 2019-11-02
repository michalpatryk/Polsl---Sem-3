#include <iostream>
#include "Punkt.h"

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
	return 0;
}
