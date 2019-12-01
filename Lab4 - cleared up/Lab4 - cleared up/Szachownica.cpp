#include "Szachownica.h"
#include "Figura.h"



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
	//this->display();
}