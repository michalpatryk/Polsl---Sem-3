#include "TablicaWektorow.h"
#include <fstream>
#include <iomanip>


TablicaWektorow::TablicaWektorow(int dl) :dl(dl)
{
	w = new Wektor[dl];
	for (int i = 0; i < dl; i++) {
		w[i] = Wektor{ 0, 0 };
	}
}

TablicaWektorow::TablicaWektorow(const TablicaWektorow & w_) :dl(w_.dl)
{
	w = new Wektor[dl];
	for (int i = 0; i < dl; i++) {
		w[i] = Wektor{ w_.w[i] };
	}
}

TablicaWektorow::TablicaWektorow(float * x, float * y, int dl) :dl(dl)
{
	w = new Wektor[dl];
	for (int i = 0; i < dl; i++) {
		w[i] = Wektor{ x[i],y[i] };
	}
}

TablicaWektorow::TablicaWektorow(std::ifstream & file)
{
	if (file) {
		try {
			file >> dl;
			w = new Wektor[dl];
			for (int i = 0; i < dl; i++) {
				float x;
				float y;
				file >> x >> y;
				w[i] = Wektor{ x,y };
			}
		}
		catch (const std::exception& e) {
			std::cout << "Error reading from file" << e.what() << "\n\n\n";
		}
	}
}

int TablicaWektorow::size()
{
	return dl;
}

void TablicaWektorow::drukuj()
{
	std::cout << "Tablica: \n";
	for (int i = 0; i < dl; i++) {
		std::cout << std::setw((int)ceil(log10(dl))) << i << ". ";	//wyrownanie
		w[i].drukuj();
	}
}

void TablicaWektorow::dodaj(Wektor & w_)
{
	dl++;
	Wektor *temp = w;
	w = new Wektor[dl];
	for (int i = 0; i < dl; i++) {
		w[i] = Wektor{ temp[i] };
	}
	w[dl - 1] = Wektor{ w_ };
}



TablicaWektorow & TablicaWektorow::operator=(const TablicaWektorow & w_)
{
	dl = w_.dl;
	delete[] w;
	w = new Wektor[dl];
	for (int i = 0; i < dl; i++) {
		w[i] = Wektor{ w_.w[i] };
	}
	return *this;
}