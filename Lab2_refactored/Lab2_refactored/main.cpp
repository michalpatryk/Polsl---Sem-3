#include <iostream>
#include "Punkt.h"
int main()
{
	std::cout << "Hello World!\n";
	Punkt p1{ 10, 5 }, p2{ 10, 15 };
	p1.drukuj();
	p2.drukuj();
	p1 += p2;
	p1.drukuj();
	return 0;
}
