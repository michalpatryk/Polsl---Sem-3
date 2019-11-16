#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include "Wektor.h"
#include "Punkt.h"
#include "TablicaWektorowSort.h"
int main()
{
    std::cout << "Hello World!\n"; 

	Wektor w1{}, w2{ 10,20 };
	w1.drukuj();
	w2.drukuj();
	w1 += w2;
	w1 += w2;
	w1.drukuj();
	w2 = w1;
	w2.drukuj();
	Wektor w3{ 1,0 };
	//--------------------------------------------------------//
	{
		TablicaWektorowSort tws1{ 5 };
		tws1.drukuj();

		float x[10] = { 10,2,3,4,5,50,7,8,9,1 };
		float y[10] = { 10,9,8,7,6,50,4,3,2,1 };
		TablicaWektorowSort tws2{ x,y,10 };
		tws2.drukuj();

		TablicaWektorowSort tws3{ tws2 };
		TablicaWektorow tw1{ x, y, 10 };
		int dl = tw1.size();

		TablicaWektorowSort tws4{ tw1 };
		tws4.drukuj();
		tws4.wstaw(w3);
		tws4.drukuj();
		tws4 = w2;
		tws4.drukuj();

	}
	_CrtDumpMemoryLeaks();	//sprawdzanie wycieków pamięci
	return 0;
}

