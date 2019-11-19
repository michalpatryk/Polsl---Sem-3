#include "szach.h"

class Wieza : public Figura
{
public:
	Wieza() :Figura() {};
	bool set(Szachownica *s_, int x_, int y_)
	{
		s = s_;
		Figura::set(x_, y_, 'W');
		// wywo³aæ set(int x,int y,Figura *f) z odpowiednim parametrem
		return true;
	}
	void range();//zdefiniowaæ zasiêg bicia dla Wie¿y
};
class Goniec : public Figura
{
	Goniec() :Figura() {};
	bool set(Szachownica *s_, int x_, int y_)
	{
		s = s_;
		Figura::set(x_, y_, 'G');
		// wywo³aæ set(int x,int y,Figura *f) z odpowiednim parametrem
		return true;
	}
	void range() {

	};

};



void Szachownica::clear()
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			wiz[i][j] = '.';
			sz[i][j] = NULL;
		};
};
void Szachownica::display()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			cout << wiz[i][j];
		cout << endl;
	}
}
