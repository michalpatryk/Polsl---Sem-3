#pragma once
#include "Szachownica.h"
class Szachownica;

class Figura
{
protected:
	Szachownica *s;
	int x, y;
	bool set(int x_, int y_, char z);
	bool set(int x_, int y_, Figura *f);
public:
	Figura();
};

