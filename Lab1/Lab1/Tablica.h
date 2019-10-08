#pragma once
#include "Punkt.h"
class Tablica
{
	Punkt *w;
	int dl;
public:
	Tablica(int dl = 0);
	Tablica(Tablica &w_);
	Tablica(float *x, float *y, int dl);

	~Tablica();
	void dodaj(Tablica &w_);
	bool porownaj(Tablica &w);

};

Tablica::Tablica(int dl)
{
	w = new Punkt(0);
}

inline Tablica::Tablica(Tablica & w_)
{
	w = w_.w;
	dl = w_.dl;
}

inline Tablica::Tablica(float * x, float * y, int dl)
{

}
