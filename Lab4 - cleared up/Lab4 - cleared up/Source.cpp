#include <iostream>
#include "Szachownica.h"
#include "Wieza.h"
#include "Goniec.h"

int main() {
	std::cout << "Test" << std::endl;
	Szachownica szachownica{};
	szachownica.display();	//display() empty test
	//WIEZA tests
	std::cout << " ====== " << std::endl;
	Wieza w1{};
	w1.set(&szachownica, 2, 2);
	szachownica.display();
	std::cout << " ====== " << std::endl;
	w1.range();
	szachownica.display();
	std::cout << " ====== " << std::endl;
	//GONIEC tests
	Goniec g1{};
	g1.set(&szachownica, 3, 3);
	szachownica.display();
	std::cout << " ====== " << std::endl;
	g1.range();
	szachownica.display();
	std::cout << " ====== " << std::endl;
}