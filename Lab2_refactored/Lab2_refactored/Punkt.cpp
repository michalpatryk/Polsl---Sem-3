#include "Punkt.h"
Punkt & Punkt::operator+=(Punkt const & p)
{
	x += p.x;
	y += p.y;
	return *this;
}
Punkt & Punkt::operator=(Punkt const & p)
{
	x = p.x;
	y = p.y;
	return *this;
}
Punkt & Punkt::operator=(Punkt const * p)
{
	x = p->x;
	y = p->y;
	return *this;
}
bool Punkt::operator==(Punkt const & p)
{
	if (x == p.x && y == p.y) return true;
	else return false;
}
Punkt Punkt::operator+(Punkt const & p)
{
	return Punkt{ x + p.x, y + p.y };
}
Punkt::~Punkt()
{
}

std::ostream & operator<<(std::ostream & os, Punkt & p)
{
	os << "X: "<< p.x << " Y: " << p.y << std::endl;
	return os;
}
