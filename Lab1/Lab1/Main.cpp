#include <iostream>
#include <string>
#include "Punkt.h"
#include "Tablica.h"

int main(void) {
	Punkt p1{ 5, 10 };
	p1.drukuj();
	Punkt p2{ 10, 10 };
	p2.drukuj();

	p1.dodaj(p2);
	p1.drukuj();



	Punkt * p3 = new Punkt{ 100, 100 };
	Punkt * p4 = new Punkt{ 200, 200 };
	p3->drukuj();
	p4->drukuj();
	p3->dodaj(p4);
	p3->drukuj();

	delete p3;
	delete p4;

	Tablica tab{ 2 };

	float x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	float y[10] = { 10,9,8,7,6,5,4,3,2,1 };

	Tablica tab2{ x,y,10 };
	std::string end;
	std::cin >> end;
	return 0;
}

