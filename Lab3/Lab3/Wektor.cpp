#include "Wektor.h"
#include <math.h>
#include <iostream>


Wektor::Wektor(float x_, float y_)
{
	x = x_;
	y = y_;
	dlugosc = sqrt((x_*x_) + (y_ * y_));
	if (y == 0 || x == 0)  kierunek = 0; 
	else  kierunek = tan((x_ / y_)); 
}



Wektor & Wektor::dodaj(const Wektor & w_)
{
	x += w_.x;
	y += w_.y;
	dlugosc = sqrt((x*x) + (y*y));
	kierunek = tan((x / y));
	return *this;
}

void Wektor::drukuj()
{
	std::cout << " X: " << x << " Y: " << y << " L " << dlugosc << " D: " << kierunek << std::endl;;
}


Wektor & Wektor::operator+=(const Wektor & w)
{
	this->dodaj(w);
	return *this;
}

Wektor & Wektor::operator=(const Wektor & w)
{
	x = w.x;
	y = w.y;
	dlugosc = sqrt((w.x*w.x) + (w.y*w.y));
	if (y == 0 || x == 0)  kierunek = 0;
	else  kierunek = tan((w.x / w.y));
	return *this;
}

bool Wektor::operator<(const Wektor & w)
{
	return (dlugosc < w.dlugosc);
}

bool Wektor::operator>(const Wektor & w)
{
	return (dlugosc > w.dlugosc);
}

Wektor::~Wektor()
{
}
