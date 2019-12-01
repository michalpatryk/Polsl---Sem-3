#include <iostream>
#include "Szachownica.h"
#include "Wieza.h"
#include "Goniec.h"

int main() {
	std::cout << "Test" << std::endl;
	Szachownica szachownica{};
	Szachownica szachownica2{};
	szachownica.display();	//display() empty test
	std::cout << " ====== " << std::endl;
	//GONIEC tests
	Goniec g1{};
	g1.set(&szachownica, 3, 3);
	szachownica.display();
	std::cout << " ====== " << std::endl;
	//WIEZA + GONIEC tests
	std::cout << " ====== " << std::endl;
	Wieza w1{};
	Goniec g2{};
	w1.set(&szachownica2, 2, 2);
	g2.set(&szachownica2, 3, 3);
	szachownica2.display();
	std::cout << " ====== " << std::endl;
	std::cout << " ====== " << std::endl;
	//SHOWRANGE tests
	g1.range();
	w1.range();
	g2.range();
	szachownica.display();
	std::cout << " ====== " << std::endl;
	szachownica2.display();
	std::cout << " ====== " << std::endl;
	return 0;
}