#include <iostream>
#include "Punkt.h"
#include "Tablica.h"
int main() {

	//testowanie operatorow pkt
	Punkt p1 = { 33, 40 };
	Punkt p2 = { 10,20 };
	Punkt p3 = {};
	p3 = p1 + p2;	//operator == i +
	std::cout << p3;
	p3 += p1;		//operator +=
	std::cout << p3;
	if (p3 == p1)	//operator ==
	{
		std::cout << "p3 == p1" << std::endl;
	}


	return 0;
}