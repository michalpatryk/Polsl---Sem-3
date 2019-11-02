#include "Tablica.h"
#include <iomanip>


Tablica::Tablica(int dl) :dl(dl)
{
	w = new Punkt[dl];
	for (int i = 0; i < dl; i++){
		w[i] = Punkt{ 0.0 };
	}
}

Tablica::Tablica(const Tablica & w_) :dl(w_.dl)
{
	w = new Punkt[dl];
	for (int i = 0; i < dl; i++){
		w[i] = Punkt{ w_.w[i] };
	}
}

Tablica::Tablica(float * x, float * y, int dl) :dl(dl)
{
	w = new Punkt[dl];
	for (int i = 0; i < dl; i++){
		w[i] = Punkt{ x[i],y[i] };
	}
}

Tablica::Tablica(std::ifstream & file)
{
	if (file) {
		try {
			file >> dl;
			w = new Punkt[dl];
			for (int i = 0; i < dl; i++) {
				float x;
				float y;
				file >> x >> y;
				w[i] = Punkt{ x,y };
			}
		}
		catch (const std::exception& e) {
			std::cout << "Error reading from file" << e.what() << "\n\n\n";
		}
	}
}

void Tablica::dodaj(const Tablica & w_)
{
	Punkt* temp = new Punkt[dl];
	for (int i = 0; i < dl; i++) { temp[i] = w[i]; }
	delete[] w;
	dl += w_.dl;
	w = new Punkt[dl];
	for (int i = 0; i < dl - w_.dl; i++) { //zapisanie poprzedniej wartosci tablicy
		w[i] = Punkt{ temp[i] };
	}
	for (int i = 0; i < w_.dl; i++) { //dopisanie zawartosci drugiej tablicy
		w[i + w_.dl] = Punkt{ w_.w[i] };
	}
	delete[] temp;
}

void Tablica::drukuj()
{
	std::cout << "Tablica: \n";
	for (int i = 0; i < dl; i++){
		std::cout << std::setw((int)ceil(log10(dl))) << i << ". ";	//wyrownanie
		w[i].drukuj();
	}
}

bool Tablica::porownaj(const Tablica & w_)
{
	if (dl == w_.dl){
		for (int i = 0; i < dl; i++){
			if (!(this->w[i] == w_.w[i])) return false;
		}
		return true;
	}
	else return false;
}

Tablica & Tablica::operator=(const Tablica & w_)
{
	dl = w_.dl;
	delete[] w;
	w = new Punkt[dl];
	for (int i = 0; i < dl; i++) {
		w[i] = Punkt{ w_.w[i] };
	}
	return *this;
}

Tablica Tablica::operator+=(const Tablica & w_)
{
	Tablica temp{ *this };
	temp.dodaj(w_);
	return temp;
}

std::ostream & operator<<(std::ostream & os, const Tablica & w_)
{
	os << "Tablica: \n";
	for (int i = 0; i < w_.dl; i++) {
		os << std::setw((int)ceil(log10(w_.dl))) << i << ". " << w_.w[i] <<std::endl;	//wyrownanie
	}
	return os;
}
