#pragma once
#include "Wektor.h"
class TablicaWektorow
{
protected:
	Wektor *w;
	int dl;
public:
	//Constructors
	TablicaWektorow(int dl = 0);
	TablicaWektorow(const TablicaWektorow &w_);
	TablicaWektorow(float *x, float *y, int dl);
	TablicaWektorow(std::ifstream& file);

	int size();

	Wektor & operator[](const int poz) { return w[poz]; };
	Wektor operator[](const int poz) const { return Wektor{ w[poz] }; }

	~TablicaWektorow() { delete[] w; };
};

