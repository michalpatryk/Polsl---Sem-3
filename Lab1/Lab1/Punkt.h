#pragma once
#include <string>
class Punkt {
	float x;
	float y;
public:
	Punkt(Punkt &p);
	Punkt(float x_ = 0, float y_ = 0);
	void dodaj(Punkt &p);
	void dodaj(Punkt *p);
	std::string drukuj();
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

std::string Punkt::drukuj()
{
	std::string output;
	output = "Dane punktu:" + std::to_string(x) + "," + std::to_string(y) + "\n";
	return  output;
}

