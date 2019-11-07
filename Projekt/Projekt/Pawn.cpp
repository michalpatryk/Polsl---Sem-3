#include "Pawn.h"
#include <iostream>




Pawn::~Pawn()
{
}
void Pawn::debug()
{
	Piece::debug();
	std::cout << "Pawn coord: " << this->coord.x << this->coord.y << std::endl;
}
