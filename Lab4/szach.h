#pragma once
#include<iostream>
using namespace std;
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


class Figura
{
protected:
	Szachownica *s; //figura zna swoj� szachownice - ustawiane przez set
	int x, y; // po�o�enie na szachownicy ustawiane przez set 
	bool set(int x, int y, char z)//pomocnicza uzywana przez range i set w sekcji public 
								 //UWAGA:(friend nie jest dziedziczony)
	{
		s->wiz[x][y] = z;//sprawdzic czy pole nie jest zaj�te (zwracamy wtedy false)
		return true;
	};
	bool set(int x, int y, Figura *f)// ustawia pole x,y tablicy sz na wska�nik do klasy dziedzicz�cej z klasy Figura (Wieza , Goniec)
	{
		s->sz[x][y] = f;//sprawdzic czy pole nie jest zaj�te (zwracamy wtedy false)
		return true;
	};
public:
	Figura() { s = NULL; };
	virtual bool set(Szachownica *s, int x_, int y_) = 0; //metoda ustawia figure na szachownicy
	// zwraca false gdy pole jest zaj�te
	// w tablicy wiz ustawia 'W' lub 'G' (dalsza cz�� zadania)
	// za pomoc� set(int x,int y,Figura *f) ustawia pole w tablicy sz.

	void remove()
	{

		s->sz[x][y] = NULL;
		s->wiz[x][y] = '.';
		s = NULL;// ustawia s na NULL - figura zdj�ta z szachownicy 
	};
	virtual void range() = 0;//pokazuje zasi�g bicia na szachownicy - operuje na tablicy wiz 
// klasy Szachownica

};