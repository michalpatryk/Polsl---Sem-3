#pragma once
#include <iostream>
#include <string>
class Punkt {
	float x;
	float y;
public:
	Punkt(Punkt &p) {
		x = p.x; y = p.y;
	}
	Punkt(float x_ = 0, float y_ = 0) {
		x = x_; y = y_;
	}
	void dodaj(Punkt &p) {
		x += p.x; y += p.y;
	}
	void dodaj(Punkt *p) {
		x += p->x; y += p->y;
	}
	std::string drukuj();
	Punkt operator+=(Punkt &p) {
		x += p.x;
		y += p.y;
	};
	/*Punkt operator=(Punkt &p) {
		x = p.x;
		y = p.y;
	}*/
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
	//friend std::ostream& operator<<(std::ostream& os, const Punkt& p);
};
std::string Punkt::drukuj()
{
	std::string output = "Dane punktu:" + std::to_string(x) + "," + std::to_string(y) + "\n";
	return  output;
}

//std::ostream& operator<<(std::ostream& os, const Punkt& p) {
	//os << p.drukuj();
	//return os;
//}