#pragma once
#include <string>
#include <iostream>
class Punkt
{
	float x, y;
public:
	//Constructors
	Punkt(Punkt const &p) :x(p.x), y(p.y) { }
	Punkt(float x_ = 0, float y_ = 0) :x(x_), y(y_) { }
	//Functions
	void dodaj(const Punkt &p)	{ x += p.x; y += p.y; }
	void dodaj(const Punkt *p)	{ x += p->x; y += p->y; }
	void drukuj() { std::cout << "X: " << x << " " << "Y: " << y <<std::endl; }
	//Operators
	Punkt & operator+=(const Punkt &p);
	Punkt & operator=(const Punkt &p);
	Punkt & operator=(const Punkt *p);
	bool operator==(const Punkt &p);
	Punkt operator+ (const Punkt &p);
	friend std::ostream& operator<<(std::ostream& os, Punkt& p);
};

