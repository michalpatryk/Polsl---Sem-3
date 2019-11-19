#pragma once

#include "Figura.h"

class Szachownica
{
	friend class Figura;

	Figura *sz[8][8];// tablica kontrolna zawieraj�ca wska�niki do ustawionych figur
	// NULL w przypadku gdy pole jest puste;
	char wiz[8][8];// tablica do wizualizacji : 'O' pole puste 'X' pole bite , 'G'- polo�enie go�ca,
	// 'W' - po�o�enie wie�y; zapisywane przez metod� range klasy Figura
public:
	Szachownica()// tworzy pust� szachownic�: pola w tablicy sz ustawione na NULL , w tablicy wiz na 'O' 
	{
		clear();
	}
	void showRange() {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (sz[i][j] != nullptr) {
					//					sz[i][j]->range();
				}
			}
		}
	}; // metoda wywo�uje na wszystkich polach tablicy sz (r�nych od NULL)
	//metod� wirtualn� range 
	void display(); // wy�wietla szachownnice (tablica wiz)
	void clear();// tworzy pust� szachownice, wywo�uje metode remove na wszystkich polach tablicy sz (r�nych od NULL)
  // UWAGA usuni�cie figury nie oznacza usuni�cie z pami�ci - nie wywo�ujemy delete

};
