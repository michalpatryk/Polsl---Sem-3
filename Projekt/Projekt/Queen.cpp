#include "Queen.h"
#include <iostream>




Queen::~Queen()
{
}
void Queen::debug()
{
	Piece::debug();
	std::cout << "Queen coord: " << this->coord.x << this->coord.y << std::endl;
}
