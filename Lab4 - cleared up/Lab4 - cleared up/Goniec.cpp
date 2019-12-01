#include "Goniec.h"
#include "Szachownica.h"
#include <cmath>
bool Goniec::set(Szachownica * s_, int x_, int y_)
{
	s = s_;
	if (Figura::set(x_, y_, this)) {
		Figura::set(x_, y_, 'W');
		return true;
	}
	return false;
}

void Goniec::range()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((abs(this->x - i) - abs(this->y - j)) == 0) {
				s->wiz[j][i] = 'G';
			}
		}
	}
	
	//if()
}

