﻿#pragma once
#include "Figura.h"
#include "Szachownica.h"
class Wieza :
	public Figura
{
public:
	Wieza() :Figura() {};
	bool set(Szachownica *s_, int x_, int y_);
	
	void range();//zdefiniować zasięg bicia dla Wieży

};

