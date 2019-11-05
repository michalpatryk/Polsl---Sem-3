#include "Wektor.h"
#include <math.h>






Wektor::Wektor(float x_, float y_, float l_, float d_)
{
	x = x_;
	y = y_;
	l = sqrt((l_*l_) + (d_+d_));
	d = tan((x_/y_));
}

Wektor::Wektor(Punkt & p)
{
	//x = p.x;
	//y = p.y;
	//l = sqrt((l_*l_) + (d_ + d_));
	//d = tan((x_ / y_));
}

Wektor::~Wektor()
{
}
