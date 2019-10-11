#include <iostream>
#include <string>
#include "Punkt.h"
#include "Tablica.h"

int main(void) {
	//----------//	Test konstruktora oraz Punkt::drukuj()
	Punkt p1{ 5, 10 };
	std::cout << p1.drukuj();
	Punkt p2{ 10, 10 };
	std::cout << p2.drukuj();
	//----------//	Test Punkt::dodaj(Punkt &p)
	p1.dodaj(p2);
	std::cout << p1.drukuj();
	//----------//	Test kontsruktora oraz Punkt::dodaj(Punkt *p)
	Punkt * p3 = new Punkt{ 100, 100 };
	Punkt * p4 = new Punkt{ 200, 200 };
	p3->drukuj();
	std::cout << p4->drukuj();
	p3->dodaj(p4);
	std::cout << p3->drukuj();
	//----------//	Destrukcja punktów
	delete p3;
	delete p4;
	//----------//	Test konstruktora Tablica(dl)
	Tablica tab{ 5 }; 
	//----------//	Test konstruktora Tablica(*x, *y, dl)
	float x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	float y[10] = { 10,9,8,7,6,5,4,3,2,1 };
	Tablica tab2{ x,y,10 };
	//----------//	Test konstruktora Tablica(Tablica &tab)
	Tablica tab3{ tab2 };
	//----------//	Test funkcji Tablica::dodaj(Tablica tab)
	tab2.dodaj(tab3);
	//----------//	Test funkcji Tablica::porownaj(Tablica& w_), powinna zwrocic 0
	std::cout << tab2.porownaj(tab3) << std::endl;
	//----------//	Test funkcji Tablica::porownaj(Tablica& w_), powinna zwrocic 1
	Tablica tab4{ tab3 };
	std::cout << tab3.porownaj(tab4) << std::endl;
	std::string end;	//Blokada natychmiastowego wyłączenia okna.
	std::cin >> end;
	return 0;
}

