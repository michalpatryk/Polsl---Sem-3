#pragma once
#include "Figura.h"

class Wieza : public Figura
{
public:
	Wieza() :Figura() {};
	bool set(Szachownica *s_, int x_, int y_)
	{
		s = s_;
		Figura::set(x_, y_, 'W');
		// wywo�a� set(int x,int y,Figura *f) z odpowiednim parametrem
		return true;
	}
	void range() {};//zdefiniowa� zasi�g bicia dla Wie�y
};
