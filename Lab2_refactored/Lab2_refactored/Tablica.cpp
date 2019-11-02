#include "Tablica.h"



Tablica::Tablica(int dl)
{
	this->dl = dl;
	w = new Punkt[dl];
	for (int i = 0; i < dl; i++){
		w[i] = new Punkt{ 0.0 };
	}
}

Tablica::~Tablica()
{
}
