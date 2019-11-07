#include "King.h"
#include <iostream>





King::~King()
{
}

void King::debug()
{
	Piece::debug();
	std::cout << "King coord: " << this->coord.x << this->coord.y << std::endl;
}
