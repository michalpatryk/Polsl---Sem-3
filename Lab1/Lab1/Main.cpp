#include <iostream>
#include <string>
#include "Punkt.h"
#include "Tablica.h"

int main(void) {
	//----------//
	Punkt p1{ 5, 10 };
	std::cout << p1.drukuj();
	Punkt p2{ 10, 10 };
	std::cout << p2.drukuj();
	//----------//
	p1.dodaj(p2);
	std::cout << p1.drukuj();
	//----------//
	Punkt * p3 = new Punkt{ 100, 100 };
	Punkt * p4 = new Punkt{ 200, 200 };
	p3->drukuj();
	std::cout << p4->drukuj();
	p3->dodaj(p4);
	std::cout << p3->drukuj();
	//----------//
	delete p3;
	delete p4;
	//----------//
	Tablica tab{ 5 }; 
	//----------//
	float x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	float y[10] = { 10,9,8,7,6,5,4,3,2,1 };
	Tablica tab2{ x,y,10 };
	//----------//
	Tablica tab3{ tab2 };
	//----------//
	tab2.dodaj(tab3);
	std::string end;
	std::cin >> end;
	return 0;
}

