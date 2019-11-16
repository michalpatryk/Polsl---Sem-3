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


	Wektor operator[](int poz) {
		Wektor w1{ this->w[poz] };
		return w1;
	};

	~TablicaWektorow() { delete[] w; };
};

