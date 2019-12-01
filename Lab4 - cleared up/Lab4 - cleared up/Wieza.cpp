#include "Wieza.h"

bool Wieza::set(Szachownica * s_, int x_, int y_)
{
	s = s_;
	if (Figura::set(x_, y_, this)) {
		Figura::set(x_, y_, 'W');
		return true;
	}
	return false;
}
