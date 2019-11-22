#pragma once
//#include "Figura.h"


//
//class Szachownica
//{
//protected:
//	friend class Figura;
//	Figura sz[8][8];
//	char wiz[8][8];
//public:
//	Szachownica() { clear(); };
//	void clear();
//};
//
//class Figura
//{
//protected:
//	Szachownica *s;
//public:
//	Figura() { s = nullptr; };
//};

class Szachownica
{
	friend class Figura;

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
class Figura
{
protected:
	Szachownica *s; //figura zna swoją szachownice - ustawiane przez set
	int x, y; // położenie na szachownicy ustawiane przez set 
	bool set(int x, int y, char z)//pomocnicza uzywana przez range i set w sekcji public 
								 //UWAGA:(friend nie jest dziedziczony)
	{
		s->wiz[x][y] = z;//sprawdzic czy pole nie jest zajęte (zwracamy wtedy false)
		return true;
	};
	bool set(int x, int y, Figura *f)// ustawia pole x,y tablicy sz na wskaźnik do klasy dziedziczącej z klasy Figura (Wieza , Goniec)
	{
		s->sz[x][y] = f;//sprawdzic czy pole nie jest zajęte (zwracamy wtedy false)
		return true;
	};
public:
	Figura() { s = nullptr; };
	virtual bool set(Szachownica *s, int x_, int y_) = 0; //metoda ustawia figure na szachownicy
	// zwraca false gdy pole jest zajęte
	// w tablicy wiz ustawia 'W' lub 'G' (dalsza część zadania)
	// za pomocą set(int x,int y,Figura *f) ustawia pole w tablicy sz.

	void remove()
	{

		s->sz[x][y] = nullptr;
		s->wiz[x][y] = '.';
		s = nullptr;// ustawia s na nullptr - figura zdjęta z szachownicy 
	};
	virtual void range() = 0;//pokazuje zasięg bicia na szachownicy - operuje na tablicy wiz 
// klasy Szachownica

};