#pragma once
#include "Punkt.h"
class Wektor :
	public Punkt
{
	float dlugosc, kierunek;	//length, direction
public:

	Wektor(float x_=0, float y_=0);
	//metody
	Wektor &dodaj(const Wektor &w_);
	void drukuj();
	//operatory
	bool operator==(const Wektor &w_) {
		if (x == w_.x && y == w_.y) return true;
		else return false;
	};
	Wektor & operator+=(const Wektor &w);
	Wektor & operator=(const Wektor &w);
	bool operator<(const Wektor &w);
	bool operator>(const Wektor &w);
	~Wektor();
};

