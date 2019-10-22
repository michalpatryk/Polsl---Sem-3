#pragma once
#include <iostream>
class Punkt {
	float x;
	float y;
public:
	Punkt(Punkt &p);
	Punkt(float x_ = 0, float y_ = 0);
	void dodaj(Punkt &p);
	void dodaj(Punkt *p);
	void drukuj();
	Punkt operator+=(Punkt &p) {
		x += p.x;
		y += p.y;
	};
	Punkt operator=(Punkt &p) {
		x = p.x;
		y = p.y;
	}
	bool operator==(Punkt &p) {
		if (x == p.x && y == p.y) return true;
		else return false;
	}
	Punkt operator+ (Punkt &p) {
		Punkt returner;
		returner.x = x + p.x;
		returner.y = y + p.y;
		return returner;
	}
};

Punkt::Punkt(Punkt & p)
{
	x = p.x;
	y = p.y;
}

Punkt::Punkt(float x_, float y_)
{
	x = x_;
	y = y_;
}

void Punkt::dodaj(Punkt & p)
{
	x += p.x;
	y += p.y;
}

void Punkt::dodaj(Punkt * p)
{
	x += p->x;
	y += p->y;
}

void Punkt::drukuj()
{
	std::cout << "Dane punktu:" << x << ", " << y << std::endl;
}

