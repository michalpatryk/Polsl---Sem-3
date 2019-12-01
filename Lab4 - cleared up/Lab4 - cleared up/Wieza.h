#pragma once
#include "Figura.h"
#include "Szachownica.h"
class Wieza :
	public Figura
{
public:
	Wieza() :Figura() {};
	bool set(Szachownica *s_, int x_, int y_);
	
	void range();//zdefiniować zasięg bicia dla Wieży
	friend class Szachownica; //friend is not hereditary, so it must be declared again
};

