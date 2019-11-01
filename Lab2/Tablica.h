#pragma once
#include "Punkt.h"
#include <iostream>
#include <fstream>
#include <string>
class Tablica
{
	Punkt *w;
	int dl;
public:
	Tablica(int dl = 0);// tworzy Tablice o zadanej d³ugoœci i wype³nia punktami (0,0)
	Tablica(const Tablica &w_);
	Tablica(float *x, float *y, int dl);//inicjalizacja listami x* i y*
	Tablica(std::ifstream& file);

	~Tablica() { delete[] w; }

	void dodaj(const Tablica &w_);
	bool porownaj(Tablica &w_);
	Tablica operator=(const Tablica &w_);
	bool operator==(const Tablica &w_);
	friend std::ostream& operator<<(std::ostream& os, const Tablica& w_);
	Tablica operator+=(const Tablica &w_);
	Punkt & operator[](const int poz);
};

Tablica::Tablica(int dl)
{
	this->dl = dl;
	w = new Punkt[dl];
	for (int i = 0; i < dl; i++)
	{
		w[i] = new Punkt{ 0.0 };
	}
}

inline Tablica::Tablica(const Tablica & w_)
{
	this->dl = w_.dl;
	w = new Punkt[dl];
	for (int i = 0; i < dl; i++)
	{
		w[i] = new Punkt{ w_.w[i] };
	}

}

inline Tablica::Tablica(float * x, float * y, int dl)
{
	this->dl = dl;
	w = new Punkt[dl];
	for (int i = 0; i < dl; i++)
	{
		w[i] = new Punkt{ x[i],y[i] };
	}
}

inline Tablica::Tablica(std::ifstream & file)
{
	if (file) {
		try {
			file >> dl;
			w = new Punkt[dl];
			for (int i = 0; i < dl; i++) {
				float x;
				float y;
				file >> x >> y;
				w[i] = Punkt{ x,y };
			}
		}
		catch(const std::exception& e) {
			std::cout << "Error reading from file" << e.what() <<"\n\n\n";
		}
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
		w[i] = new Punkt{ temp[i] };
	}
	for (int i = 0; i < w_.dl; i++) //dopisanie zawartosci drugiej tablicy
	{
		w[i + w_.dl] = new Punkt{ w_.w[i] };
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
		w[i] = new Punkt{ w_.w[i] };
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

std::ostream& operator<<(std::ostream& os, const Tablica &w_) {
	for (int i = 0; i < w_.dl; i++) {
		os << "Numer punktu: "<<i<<" "<<w_.w[i];
	}
	return os;
}

