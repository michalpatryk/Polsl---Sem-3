#pragma once
#include "Punkt.h"
class Tablica
{
	Punkt *w;
	int dl;
public:
	Tablica(int dl = 0);// tworzy Tablice o zadanej d�ugo�ci i wype�nia punktami (0,0)
	Tablica(Tablica &w_);
	Tablica(float *x, float *y, int dl);//inicjalizacja listami x* i y*

	~Tablica() { delete[] w; }

	void dodaj(Tablica &w_);
	bool porownaj(Tablica &w_);

};

Tablica::Tablica(int dl)
{
	this->dl = dl;
	w = new Punkt[dl];
	for (int i = 0; i < dl; i++)
	{
		Punkt *temp = new Punkt{ 0.0 };
		w[i] = *temp;
	}
}

inline Tablica::Tablica(Tablica & w_)
{
	this->dl = w_.dl;
	w = new Punkt[dl];
	for (int i = 0; i < dl; i++)
	{
		Punkt *temp = new Punkt{ w_.w[i] };
		w[i] = *temp;
	}

}

inline Tablica::Tablica(float * x, float * y, int dl)
{
	this->dl = dl;
	w = new Punkt[dl];
	for (int i = 0; i < dl; i++)
	{
		Punkt *temp = new Punkt{ x[i],y[i] };
		w[i] = *temp;
	}
}

void Tablica::dodaj(Tablica & w_)
{
	Punkt* temp = new Punkt[dl];	//zapisanie zawartosci starej
	for (int i = 0; i < dl; i++) { temp[i] = w[i]; }
	delete[] w;	//usuniecie
	dl += w_.dl;	//zmiana dl
	w = new Punkt[dl];
	for (int i = 0; i < dl - w_.dl; i++) //zapisanie poprzedniej wartosci tablicy
	{
		Punkt *tempPkt = new Punkt{ temp[i] };
		w[i] = *tempPkt;
	}
	for (int i = 0; i < w_.dl; i++) //dopisanie zawartosci drugiej tablicy
	{
		Punkt *tempPkt = new Punkt{ w_.w[i] };
		w[i + w_.dl] = *tempPkt;
	}
}

bool Tablica::porownaj(Tablica & w_)
{
	if (dl == w_.dl)
	{
		for (int i = 0; i < dl; i++)
		{
			if (this->w[i].drukuj() != w_.w[i].drukuj()) return false;
		}
		return true;
	}
	else return false;
}

