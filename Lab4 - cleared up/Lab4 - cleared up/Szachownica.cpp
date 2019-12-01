#include "Szachownica.h"
#include "Figura.h"

#include <iostream>

void Szachownica::clear()
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			wiz[i][j] = '.';
			sz[i][j] = nullptr;
		}
}

void Szachownica::showRange()
{
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if (sz[j][i])	sz[j][i]->range();
		}
	}
	this->display();
}

void Szachownica::display()
{
	for (int i = 0; i < 8; i++)	{
		for (int j = 0; j < 8; j++) {
			std::cout << wiz[j][i];
		}
		std::cout << std::endl;
	}
}