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

void Pawn::createPossibleMoveTable()
{
	std::vector<std::vector<bool>> varr(8, std::vector<bool>(8, false));
	possibleMoveTable = varr;

	int dy;		//which direction to go
	if (this->color == Color::white) { dy = -1; }	//sets the direction of the move
	else if (this->color == Color::black) { dy = 1; }

	if (coord.y + dy < 9 && coord.y + dy > 0 && costTable[coord.y - 1 + dy][coord.x - 1] < 1) 				//--moving forward	
		possibleMoveTable[coord.y - 1 + dy][coord.x - 1] = true;

	if (coord.y + 2 * dy < 9 && coord.y + 2 * dy > 0 && costTable[coord.y - 1 + 2 * dy][coord.x - 1] < 1	//--moving forward *2
		&& costTable[coord.y - 1 +  dy][coord.x - 1] < 1)	
		if ((coord.y == 2 && color == Color::black) || (coord.y == 7 && color == Color::white))
			possibleMoveTable[coord.y - 1 + 2 * dy][coord.x - 1] = true;

																											//killing left or right
	if (coord.y + dy < 9 && coord.y + dy > 0) {//only one forward
		if (coord.x - 1 > 0 && coord.y + 1 < 9) {//one left or right
			if (costTable[coord.y - 1 + dy][coord.x - 1 - 1] == 1)		possibleMoveTable[coord.y - 1 + dy][coord.x - 1 - 1 ] = true;
			if (costTable[coord.y - 1 + dy][coord.x - 1 + 1] == 1)		possibleMoveTable[coord.y - 1 + dy][coord.x - 1 + 1 ] = true;
		}
	}
}
