#include "Tablica.h"
#include <iomanip>

template <class T>
Tablica<T>::Tablica(int dl) :dl(dl)
{
	w = new T[dl];
	for (int i = 0; i < dl; i++){
		w[i] = T{ 0.0 };
	}
}
template <class T>
Tablica<T>::Tablica(const Tablica & w_) :dl(w_.dl)
{
	w = new Punkt[dl];
	for (int i = 0; i < dl; i++){
		w[i] = Punkt{ w_.w[i] };
	}
}
template <class T>
Tablica<T>::Tablica(float * x, float * y, int dl) :dl(dl)
{
	w = new Punkt[dl];
	for (int i = 0; i < dl; i++){
		w[i] = Punkt{ x[i],y[i] };
	}
}
template <class T>
Tablica<T>::Tablica(std::ifstream & file)
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

template <class T>
void Tablica<T>::dodaj(const Tablica & w_)
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
template <class T>
void Tablica<T>::drukuj()
{
	std::cout << "Tablica: \n";
	for (int i = 0; i < dl; i++){
		std::cout << std::setw((int)ceil(log10(dl))) << i << ". ";	//wyrownanie
		w[i].drukuj();
	}
}
template <class T>
bool Tablica<T>::porownaj(const Tablica & w_)
{
	if (dl == w_.dl){
		for (int i = 0; i < dl; i++){
			if (!(this->w[i] == w_.w[i])) return false;
		}
		return true;
	}
	else return false;
}
template <class T>
Tablica<T> & Tablica<T>::operator=(const Tablica & w_)
{
	dl = w_.dl;
	delete[] w;
	w = new Punkt[dl];
	for (int i = 0; i < dl; i++) {
		w[i] = Punkt{ w_.w[i] };
	}
	return *this;
}
template <class T>
Tablica<T> & Tablica<T>::operator+=(const Tablica & w_)
{
	this->dodaj(w_);
	return *this;
}


template <class T>
std::ostream & operator<<(std::ostream & os, const Tablica<T> & w_)
{
	os << "Tablica: \n";
	for (int i = 0; i < w_.dl; i++) {
		os << std::setw((int)ceil(log10(w_.dl))) << i << ". " << w_.w[i] <<std::endl;	//wyrownanie
	}
	return os;
}
