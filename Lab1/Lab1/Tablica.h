#pragma once
#include "Punkt.h"
class Tablica
{
	Punkt *w;
	int dl;
public:
	Tablica(int dl = 0);// tworzy Tablice o zadanej długości i wypełnia punktami (0,0)
	Tablica(Tablica &w_);
	Tablica(float *x, float *y, int dl);//inicjalizacja listami x* i y*

	//~Tablica();
	//void dodaj(Tablica &w_);
	//bool porownaj(Tablica &w);

};

Tablica::Tablica(int dl)
{
	this->dl = dl;
	w = new Punkt[dl];
	for (int i = 0; i < dl; i++)
	{
		w[i] = Punkt{ 0,0 };
	}
}

inline Tablica::Tablica(Tablica & w_)
{
	w = w_.w;
	dl = w_.dl;
}

inline Tablica::Tablica(float * x, float * y, int dl)
{
	this->dl = dl;
	w = new Punkt[dl];
	for (int i = 0; i < dl; i++)
	{
		w[i] = Punkt{ x[i],y[i] };
	}
}
