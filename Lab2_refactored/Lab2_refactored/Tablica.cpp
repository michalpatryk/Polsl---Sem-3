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
	std::cout << "Tablica: \n " << std::endl;
	for (int i = 0; i < dl; i++){
		std::cout << std::setw((int)ceil(log10(dl))) << i << ". ";	//wyrownanie
		w[i].drukuj();
	}
}

