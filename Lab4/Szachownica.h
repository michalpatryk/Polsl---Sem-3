#pragma once

#include "Figura.h"

class Szachownica
{
	friend class Figura;

	Figura *sz[8][8];// tablica kontrolna zawieraj¹ca wska¿niki do ustawionych figur
	// NULL w przypadku gdy pole jest puste;
	char wiz[8][8];// tablica do wizualizacji : 'O' pole puste 'X' pole bite , 'G'- polo¿enie goñca,
	// 'W' - po³o¿enie wie¿y; zapisywane przez metodê range klasy Figura
public:
	Szachownica()// tworzy pust¹ szachownicê: pola w tablicy sz ustawione na NULL , w tablicy wiz na 'O' 
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
	}; // metoda wywo³uje na wszystkich polach tablicy sz (ró¿nych od NULL)
	//metodê wirtualn¹ range 
	void display(); // wyœwietla szachownnice (tablica wiz)
	void clear();// tworzy pust¹ szachownice, wywo³uje metode remove na wszystkich polach tablicy sz (ró¿nych od NULL)
  // UWAGA usuniêcie figury nie oznacza usuniêcie z pamiêci - nie wywo³ujemy delete

};
