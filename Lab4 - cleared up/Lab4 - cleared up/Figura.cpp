#include "Figura.h"
#include "Szachownica.h"
#include <iostream>
bool Figura::set(int x_, int y_, char z)
{
	if (x_ < 8 && x_>0 && y_ < 8 && y_>0 && s->sz[x_][y_] == nullptr) {
		s->wiz[x_][y_] = z;
		return true;
	}
	else return false;
}

bool Figura::set(int x_, int y_, Figura * f)
{
	if (x_ < 8 && x_>0 && y_ < 8 && y_>0 && s->sz[x_][y_] == nullptr) {
		s->sz[x_][y_] = f;
		f->x = x_;
		f->y = y_;
		return true;
	}
	else return false;
}

void Figura::remove()
{
	s->sz[x][y] = nullptr;
	s->wiz[x][y] = '.';
	s = nullptr;
}
