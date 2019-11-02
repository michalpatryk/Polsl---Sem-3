#pragma once
#include "Punkt.h"
#include <fstream>
class Tablica
{
	Punkt *w;
	int dl;
public:
	//Constructors
	Tablica(int dl = 0);
	Tablica(const Tablica &w_);
	Tablica(float *x, float *y, int dl);
	Tablica(std::ifstream& file);
	//Destruktor
	~Tablica() { delete[dl] w; };
	//Functions
	void dodaj(const Tablica &w_);
	void drukuj();
	bool porownaj(const Tablica &w_);
	//Operators
	Tablica &operator=(const Tablica &w_);
	bool operator==(const Tablica &w_) { return (this->porownaj(w_)); }
	Tablica & operator+=(const Tablica &w_);
	Punkt & operator[](const int poz) { return this->w[poz]; }

	friend std::ostream& operator<<(std::ostream& os, const Tablica& w_);

};

