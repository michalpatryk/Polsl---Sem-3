#pragma once
#include "Figura.h"

class Goniec : public Figura
{
	Goniec() :Figura() {};
	bool set(Szachownica *s_, int x_, int y_)
	{
		s = s_;
		Figura::set(x_, y_, 'G');
		// wywo³aæ set(int x,int y,Figura *f) z odpowiednim parametrem
		return true;
	}
	void range() {

	};

};


