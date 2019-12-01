#include "Wieza.h"

bool Wieza::set(Szachownica * s_, int x_, int y_)
{
	s = s_;
	Figura::set(x_, y_, 'W');
	// wywołać set(int x,int y,Figura *f) z odpowiednim parametrem
	return true;
}
