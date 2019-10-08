#include <iostream>
#include "Punkt.h"
//123




int main(void) {
	std::cout << "test\n";
	Punkt p1(5, 10);
	p1.drukuj();
	Punkt p2(10, 10);
	p2.drukuj();

	p1.dodaj(p2);
	p1.drukuj();



	Punkt * p3 = new Punkt(100, 100);
	Punkt * p4 = new Punkt(200, 200);
	p3->drukuj();
	p4->drukuj();
	p3->dodaj(p4);
	p3->drukuj();

	delete p3;
	delete p4;
	return 0;
}

