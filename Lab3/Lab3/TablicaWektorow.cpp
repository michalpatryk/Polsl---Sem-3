#include "TablicaWektorow.h"
#include <fstream>



TablicaWektorow::TablicaWektorow(int dl) :dl(dl)
{
	w = new Wektor[dl];
	for (int i = 0; i < dl; i++) {
		w[i] = Wektor{ 0.0 };
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

