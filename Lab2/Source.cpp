#include <iostream>
#include "Punkt.h"
#include "Tablica.h"
int main() {

	//testowanie operatorow pkt
	Punkt p1 = { 33, 40 };
	Punkt p2 = { 10,20 };
	Punkt p3 = {};
	p3 = p1 + p2;	//operator == i +
	std::cout << p3;	//operator <<
	p3 += p1;		//operator +=
	std::cout << p3;
	if (p3 == p1)	//operator ==
	{
		std::cout << "p3 == p1" << std::endl;	
	}
	//testowanie tablicy
	Tablica tab{ 5 };
	float x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	float y[10] = { 10,9,8,7,6,5,4,3,2,1 };
	Tablica tab2{ x,y,10 };
	Tablica tab3{ x, y, 10 };

	if (tab == tab2) {	//testowanie operaotra ==
		std::cout << "tab1 == tab2" << std::endl;
	}
	else if (tab2 == tab3) {
		std::cout << "tab2 == tab3" <<std::endl;
	}
	tab = tab2;	//testowanie operatorwa =
	if (tab == tab2) {
		std::cout << "After tab = tab2, tab == tab2" << std::endl;
	}

	std::cout << tab <<std::endl;	//testowanie operatora <<

	std::cout << tab[2];	//testowanie operatora []

	tab += tab2;
	std::cout << tab;

	return 0;
}