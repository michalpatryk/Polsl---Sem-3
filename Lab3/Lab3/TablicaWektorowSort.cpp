#include "TablicaWektorowSort.h"
#include <algorithm>




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
	for (int i = 0; i < dl; i++) {
		w[i] = Wektor{ x[i],y[i] };
	}
	//now sort
	std::sort(w, w + dl);

}

TablicaWektorowSort::~TablicaWektorowSort()
{
}
