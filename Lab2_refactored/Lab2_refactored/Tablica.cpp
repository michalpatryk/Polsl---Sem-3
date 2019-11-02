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
	Punkt *temp = w;
	int old_dl = dl;
	dl += w_.dl;
	w = new Punkt[dl];
	for (int i = 0; i < old_dl; i++) {
		w[i] = temp[i];
	}
	delete[] temp;
	for (int i = 0; i < w_.dl; i++) {
		w[old_dl + i] = w_.w[i];
	}
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



std::ostream & operator<<(std::ostream & os, const Tablica & w_)
{
	os << "Tablica: \n";
	for (int i = 0; i < w_.dl; i++) {
		os << std::setw((int)ceil(log10(w_.dl))) << i << ". " << w_.w[i] <<std::endl;	//wyrownanie
	}
	return os;
}
