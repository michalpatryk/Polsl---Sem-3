#pragma once
#include <string>
class Punkt {
	float x;
	float y;
public:
	Punkt(Punkt &p) { 
		x = p.x; y = p.y; 
	}
	Punkt(float x_ = 0, float y_ = 0){
		x = x_; y = y_;
	}
	void dodaj(Punkt &p){
		x += p.x; y += p.y;
	}
	void dodaj(Punkt *p){
		x += p->x; y += p->y;
	}
	std::string drukuj();
};

std::string Punkt::drukuj()
{
	std::string output = "Dane punktu:" + std::to_string(x) + "," + std::to_string(y) + "\n";
	return  output;
}

