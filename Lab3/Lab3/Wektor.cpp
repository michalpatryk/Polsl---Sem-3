#include "Wektor.h"
#include <math.h>
#include <iostream>


Wektor::Wektor(float x_, float y_)
{
	x = x_;
	y = y_;
	l = sqrt((x_*x_) + (y_ + y_));
	if (y == 0)  d = 0; 
	else  d = tan((x_ / y_)); 
}

Wektor & Wektor::dodaj(const Wektor & w_)
{
	x += w_.x;
	y += w_.y;
	l = sqrt((x*x) + (y*y));
	d = tan((x / y));
	return *this;
}

void Wektor::drukuj()
{
	std::cout << " X: " << x << " Y: " << y << " L " << l << " D: " << d << std::endl;;
}


Wektor::~Wektor()
{
}
