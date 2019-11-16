#include "TablicaWektorowSort.h"





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
	std::qsort(w, dl, sizeof (Wektor), [](const void* a, const void* b)
	{
		int arg1 = *static_cast<const int*>(a);
		int arg2 = *static_cast<const int*>(b);

		if (arg1 < arg2) return -1;
		if (arg1 > arg2) return 1;
		return 0;

		//  return (arg1 > arg2) - (arg1 < arg2); // possible shortcut
		//  return arg1 - arg2; // erroneous shortcut (fails if INT_MIN is present)
	});
}

TablicaWektorowSort::~TablicaWektorowSort()
{
}
