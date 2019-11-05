#pragma once
#include "Punkt.h"
class Wektor :
	public Punkt
{
	float l, d;	//length, direction
public:
	Wektor(float x_ = 0, float y_ = 0, float l_ = 0, float d_ = 0);
	Wektor(float x_, float y_);
	//Wektor(Punkt &p {}, float l_ = 0, float d_ = 0) : l(l_), d(d_) {
	//	x = p.x; y = p.y;
	//};
	~Wektor();
};

