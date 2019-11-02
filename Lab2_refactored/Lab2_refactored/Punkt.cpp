#include "Punkt.h"
Punkt & Punkt::operator+=(const Punkt & p)
{
	x += p.x;
	y += p.y;
	return *this;
}
Punkt & Punkt::operator=(const Punkt & p)
{
	x = p.x;
	y = p.y;
	return *this;
}
Punkt & Punkt::operator=(const Punkt * p)
{
	x = p->x;
	y = p->y;
	return *this;
}
bool Punkt::operator==(const Punkt & p)
{
	if (x == p.x && y == p.y) return true;
	else return false;
}
Punkt Punkt::operator+(const Punkt & p)
{
	return Punkt{ x + p.x, y + p.y };
}
Punkt::~Punkt()
{
}

std::ostream & operator<<(std::ostream & os, Punkt & p)
{
	os << "X: "<< p.x << " Y: " << p.y;
	return os;
}
