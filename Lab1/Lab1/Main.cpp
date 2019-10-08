#include <iostream>
//123
class Punkt {
	float x;
	float y;
public:
	Punkt(Punkt &p);
	Punkt(float x_ = 0, float y_ = 0);
	void dodaj(Punkt &p);
	void dodaj(Punkt *p);
	void drukuj();
};

class Tablica
{
	Punkt *w;
	int dl;
public:
	Tablica(int dl = 0);
	Tablica(Tablica &w_);
	Tablica(float *x, float *y, int dl);

	~Tablica();
	void dodaj(Tablica &w_);
	bool porownaj(Tablica &w);

};

int main(void) {
	std::cout << "test\n";
	Punkt p1(5, 10);
	p1.drukuj();
	Punkt p2(10, 10);
	p2.drukuj();

	p1.dodaj(p2);
	p1.drukuj();



	Punkt * p3 = new Punkt(100, 100);
	Punkt * p4 = new Punkt(200, 200);
	p3->drukuj();
	p4->drukuj();
	p3->dodaj(p4);
	p3->drukuj();

	delete p3;
	delete p4;
	return 0;
}

Punkt::Punkt(Punkt & p)
{
	x = p.x;
	y = p.y;
}

Punkt::Punkt(float x_, float y_)
{
	x = x_;
	y = y_;
}

void Punkt::dodaj(Punkt & p)
{
	x += p.x;
	y += p.y;
}

void Punkt::dodaj(Punkt * p)
{
	x += p->x;
	y += p->y;
}

void Punkt::drukuj()
{
	std::cout << "Dane punktu:" << x << ", " << y << std::endl;
}

Tablica::Tablica(int dl)
{
	w = new Punkt(0);
}
