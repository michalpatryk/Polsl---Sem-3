#pragma once
#include "Figura.h"



class Szachownica
{
	friend class Figura;
public:	//https://developercommunity.visualstudio.com/content/problem/77850/accessing-a-private-member-variable-from-a-friend.html
		//due to some bug. even though Wieza uses friend class Szachownica, it cant acces sz and wiz
	Figura *sz[8][8];// tablica kontrolna zawierająca wskażniki do ustawionych figur
	// nullptr w przypadku gdy pole jest puste;
	char wiz[8][8];// tablica do wizualizacji : 'O' pole puste 'X' pole bite , 'G'- polożenie gońca,
	// 'W' - położenie wieży; zapisywane przez metodę range klasy Figura
public:
	Szachownica()// tworzy pustą szachownicę: pola w tablicy sz ustawione na nullptr , w tablicy wiz na 'O' 
	{
		clear();
	}
	void showRange(); // metoda wywołuje na wszystkich polach tablicy sz (różnych od nullptr)
	//metodę wirtualną range 
	void display(); // wyświetla szachownnice (tablica wiz)
	void clear();// tworzy pustą szachownice, wywołuje metode remove na wszystkich polach tablicy sz (różnych od nullptr)
  // UWAGA usunięcie figury nie oznacza usunięcie z pamięci - nie wywołujemy delete

};
