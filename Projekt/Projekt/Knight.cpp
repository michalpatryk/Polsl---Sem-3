#include "Knight.h"
#include <iostream>




Knight::~Knight()
{
}

void Knight::debug()
{
	Piece::debug();
	std::cout << "Knight coord: " << this->coord.x << this->coord.y << std::endl;
}
