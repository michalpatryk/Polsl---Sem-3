#include "Bishop.h"
#include <iostream>




Bishop::~Bishop()
{

}


void Bishop::debug()
{
	Piece::debug();
	std::cout << "Bishop coord: " << this->coord.x << this->coord.y << std::endl;
}
