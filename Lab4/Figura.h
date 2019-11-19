#pragma once
#include "Szachownica.h"

class Figura
{
protected:

	Szachownica* s; //figura zna swoj¹ szachownice - ustawiane przez set
	int x, y; // po³o¿enie na szachownicy ustawiane przez set 
	bool set(int x, int y, char z)//pomocnicza uzywana przez range i set w sekcji public 
								 //UWAGA:(friend nie jest dziedziczony)
	{
		s->wiz[x][y] = z;//sprawdzic czy pole nie jest zajête (zwracamy wtedy false)
		return true;
	};
	bool set(int x, int y, Figura *f)// ustawia pole x,y tablicy sz na wskaŸnik do klasy dziedzicz¹cej z klasy Figura (Wieza , Goniec)
	{
		s->sz[x][y] = f;//sprawdzic czy pole nie jest zajête (zwracamy wtedy false)
		return true;
	};
public:
	Figura() { s = nullptr; };
	virtual bool set(Szachownica *s, int x_, int y_) = 0; //metoda ustawia figure na szachownicy
	// zwraca false gdy pole jest zajête
	// w tablicy wiz ustawia 'W' lub 'G' (dalsza czêœæ zadania)
	// za pomoc¹ set(int x,int y,Figura *f) ustawia pole w tablicy sz.

	void remove()
	{

		s->sz[x][y] = nullptr;
		s->wiz[x][y] = '.';
		s = nullptr;// ustawia s na NULL - figura zdjêta z szachownicy 
	};
	virtual void range() = 0;//pokazuje zasiêg bicia na szachownicy - operuje na tablicy wiz 
// klasy Szachownica

};