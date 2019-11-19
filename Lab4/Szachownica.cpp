#include "Szachownica.h"
#include <iostream>


void Szachownica::clear()
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			wiz[i][j] = '.';
			sz[i][j] = nullptr;
		};
};
void Szachownica::display()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			std::cout << wiz[i][j];
		std::cout << std::endl;
	}
}
