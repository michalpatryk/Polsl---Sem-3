#pragma once
#include "Punkt.h"
class Tablica
{
	Punkt *w;
	int dl;
public:
	Tablica(int dl = 0);
	Tablica(Tablica &w_);
	Tablica(float *x, float *y, int dl);//inicjalizacja listami x* i y*

	~Tablica();
	void dodaj(Tablica &w_);
	bool porownaj(Tablica &w);

};