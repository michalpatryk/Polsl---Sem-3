#pragma once
#include "Punkt.h"
#include <fstream>
class Tablica
{
	Punkt *w;
	int dl;
public:
	//Constructors
	Tablica(int dl = 0);
	Tablica(const Tablica &w_);
	Tablica(float *x, float *y, int dl);
	Tablica(std::ifstream& file);
	//Destruktor
	~Tablica() { delete[] w; };
	//Functions
	void dodaj(const Tablica &w_);
	void drukuj();

};

