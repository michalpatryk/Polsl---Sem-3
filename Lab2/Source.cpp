#include "Punkt.h"
#include "Tablica.h"
int main() {
	Punkt p1 = { 33, 40 };
	Punkt p2 = { 10,20 };
	Punkt p3 = {};
	p3 = p1 + p2;
	return 0;
}