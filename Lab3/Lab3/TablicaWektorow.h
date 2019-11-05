#pragma once
#include "Wektor.h"
class TablicaWektorow
{
public:
	Wektor *w;
	int dl;
public:
	//Constructors
	TablicaWektorow(int dl = 0);
	TablicaWektorow(const TablicaWektorow &w_);
	TablicaWektorow(float *x, float *y, int dl);
	TablicaWektorow(std::ifstream& file);

	~TablicaWektorow();
};

