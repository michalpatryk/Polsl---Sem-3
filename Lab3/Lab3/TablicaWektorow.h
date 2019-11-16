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


	Wektor operator[](int poz) { return this->w[poz]; };

	~TablicaWektorow() { delete[] w; };
};

