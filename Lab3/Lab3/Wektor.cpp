#include "Wektor.h"
#include <math.h>






Wektor::Wektor(float x_, float y_, float l_, float d_)
{
	x = x_;
	y = y_;
	l = sqrt((x_*x_) + (y_+y_));
	d = tan((x_/y_));
}

Wektor::Wektor(float x_, float y_)
{
	x = x_;
	y = y_;
	l = sqrt((x_*x_) + (y_ + y_));
	d = tan((x_ / y_));
}



Wektor::~Wektor()
{
}
