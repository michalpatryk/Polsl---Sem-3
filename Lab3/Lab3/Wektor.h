#pragma once
#include "Punkt.h"
class Wektor :
	public Punkt
{
	float l, d;	//length, direction
public:

	Wektor(float x_=0, float y_=0);
	
	Wektor &dodaj(const Wektor &w_);
	void drukuj();

	bool operator==(const Wektor &w_) {
		if (x == w_.x && y == w_.y) return true;
		else return false;
	};
	~Wektor();
};

