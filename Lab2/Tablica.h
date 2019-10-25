#pragma once
#include "Punkt.h"
class Tablica
{
	Punkt *w;
	int dl;
public:
	Tablica(int dl = 0);// tworzy Tablice o zadanej d³ugoœci i wype³nia punktami (0,0)
	Tablica(Tablica &w_);
	Tablica(float *x, float *y, int dl);//inicjalizacja listami x* i y*

	~Tablica() { delete[] w; }

	void dodaj(const Tablica &w_);
	bool porownaj(Tablica &w_);
	Tablica operator=(const Tablica &w_);
	bool operator==(const Tablica &w_);
	friend std::ostream& operator<<(std::ostream& os, Tablica& w_);
	Tablica operator+=(const Tablica &w_);
	Punkt & operator[](const int poz);
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

void Tablica::dodaj(const Tablica & w_)
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
//---------------------------------------Lab2---------------------------------------//
inline Tablica Tablica::operator=(const Tablica & w_)
{
	this->dl = w_.dl;
	w = new Punkt[dl];
	for (int i = 0; i < dl; i++)
	{
		Punkt *temp = new Punkt{ w_.w[i] };
		w[i] = *temp;
	}
	return *this;
}

inline bool Tablica::operator==(const Tablica & w_)
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

inline Tablica Tablica::operator+=(const Tablica & w_)
{
	this->dodaj(w_);
	return *this;
}

Punkt & Tablica::operator[](const int poz)
{
	Punkt *temp = new Punkt {};
	*temp = this->w[poz];
	return *temp;
}

std::ostream& operator<<(std::ostream& os, Tablica &w_) {
	for (int i = 0; i < w_.dl; i++) {
		os << "Numer punktu: "<<i<<" "<<w_.w[i];
	}
	return os;
}

