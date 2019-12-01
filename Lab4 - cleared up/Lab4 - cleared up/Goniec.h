#pragma once
#include "Figura.h"
class Goniec :
	public Figura
{
public:
	Goniec() :Figura() {};
	bool set(Szachownica *s_, int x_, int y_);

	void range();//zdefiniować zasięg bicia dla Wieży
	friend class Szachownica;
};

