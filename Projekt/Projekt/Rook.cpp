#include "Rook.h"
#include <iostream>




Rook::~Rook()
{
}

void Rook::debug()
{
	Piece::debug();
	std::cout <<"Rook coord: "<< this->coord.x <<this->coord.y <<std::endl;
}
