#pragma once
#include "TablicaWektorow.h"
class TablicaWektorowSort :
	public TablicaWektorow
{
public:
	TablicaWektorowSort(int dl = 0);
	TablicaWektorowSort(const TablicaWektorowSort &w_);
	TablicaWektorowSort(float *x, float *y, int dl);
	TablicaWektorowSort(TablicaWektorow &w_);

	int size();
	void wstaw(Wektor & w_);

	~TablicaWektorowSort() {};
};

