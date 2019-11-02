#include "Tablica.h"



Tablica::Tablica(int dl) :dl(dl)
{
	w = new Punkt[dl];
	for (int i = 0; i < dl; i++){
		w[i] = Punkt{ 0.0 };
	}
}

Tablica::Tablica(const Tablica & w_) :dl(w_.dl)
{
	w = new Punkt[dl];
	for (int i = 0; i < dl; i++){
		w[i] = Punkt{ w_.w[i] };
	}
}

Tablica::Tablica(float * x, float * y, int dl) :dl(dl)
{
	w = new Punkt[dl];
	for (int i = 0; i < dl; i++){
		w[i] = Punkt{ x[i],y[i] };
	}
}

