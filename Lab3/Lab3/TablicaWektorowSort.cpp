#include "TablicaWektorowSort.h"
#include <algorithm>




TablicaWektorowSort::TablicaWektorowSort(int dl) //: TablicaWektorow (dl)
{
	this->dl = dl;
	w = new Wektor[dl];
	for (int i = 0; i < dl; i++) {
		w[i] = Wektor{ 0, 0 };
	}
}

TablicaWektorowSort::TablicaWektorowSort(const TablicaWektorowSort & w_) 
{
	this->dl = w_.dl;
	w = new Wektor[dl];
	for (int i = 0; i < dl; i++) {
		w[i] = Wektor{ w_.w[i] };
	}
}

TablicaWektorowSort::TablicaWektorowSort(float * x, float * y, int dl) 
//Alternative:	
//TablicaWektorowSort::TablicaWektorowSort(float * x, float * y, int dl) :TablicaWektorow(x, y, dl)
//{
//std::sort(w, w+dl);
//}
{
	this->dl = dl;
	w = new Wektor[dl];
	for (int i = 0; i < dl; i++) {
		w[i] = Wektor{ x[i],y[i] };
	}
	//now sort
	std::sort(w, w + dl);

}

TablicaWektorowSort::TablicaWektorowSort(TablicaWektorow & w_)	//Same as above
{
	dl = w_.size();
	w = new Wektor[dl];
	for (int i = 0; i < dl; i++) {
		w[i] = Wektor{ w_[i] };
	}
	//now sort
	std::sort(w, w + dl);
}

int TablicaWektorowSort::size()
{
	return dl;
}

void TablicaWektorowSort::wstaw(Wektor & w_)
{
	Wektor* temp = w;
	dl++;
	w = new Wektor[dl];
	int max = dl-1;
	bool isInsert = 0;
	for (int i = 0; i < dl; i++) {
		if (w_ < temp[i] && !isInsert) {
			w[i] = Wektor{ w_ };
			isInsert = true;
		}
		else if (i == max && !isInsert) w[i] = Wektor{ w_ };
		else w[i] = temp[i-isInsert];
	}
	delete[] temp;
}

TablicaWektorowSort & TablicaWektorowSort::operator=(Wektor & w_)
{
	TablicaWektorowSort::wstaw(w_);
	return *this;
}
