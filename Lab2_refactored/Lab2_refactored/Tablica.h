#pragma once
#include "Punkt.h"
class Tablica
{
	Punkt *w;
	int dl;
public:
	Tablica(int dl = 0);
	Tablica(const Tablica &w_);
	~Tablica() { delete[] w; };
};

