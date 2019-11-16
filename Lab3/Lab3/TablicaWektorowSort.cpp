#include "TablicaWektorowSort.h"

#include <vector>



TablicaWektorowSort::TablicaWektorowSort(int dl)
{
	w = new Wektor[dl];
	for (int i = 0; i < dl; i++) {
		w[i] = Wektor{ 0.0 };
	}
}

TablicaWektorowSort::TablicaWektorowSort(const TablicaWektorowSort & w_)
{
	w = new Wektor[dl];
	for (int i = 0; i < dl; i++) {
		w[i] = Wektor{ w_.w[i] };
	}
}

TablicaWektorowSort::TablicaWektorowSort(float * x, float * y, int dl)
{
	w = new Wektor[dl];
	if (dl > 0) {
		
	}
	
}

TablicaWektorowSort::~TablicaWektorowSort()
{
}
