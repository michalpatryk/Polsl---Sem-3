#pragma once
#include "Punkt.h"
class Tablica
{
	Punkt *w;
	int dl;
public:
	Tablica(int dl = 0);
	Tablica(const Tablica &w_);
	Tablica(float *x, float *y, int dl);

	~Tablica() {
		/*for (int i = 0; i < dl; i++) {
			delete w[i];
		}*/
		delete[] w;
		//for (int i = 0; i < dl; i++) {
		//	delete w[i];
		//}
	};
};

