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

//Tablica::Tablica(int dl)
//{
//	w = new Punkt(0);
//}
//
//inline Tablica::Tablica(Tablica & w_)
//{
//	w = w_.w;
//	dl = w_.dl;
//}
//
//inline Tablica::Tablica(float * x, float * y, int dl)
//{
//	int i = 0;
//	while ((x + 1) != nullptr && (y + 1) != nullptr)
//	{
//		//Punkt *temp = new Punkt(*x, *y);
//
//	}
//}
