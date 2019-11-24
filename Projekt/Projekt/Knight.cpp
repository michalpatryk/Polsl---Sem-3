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

void Knight::createPossibleMoveTable()
{
	std::vector<std::vector<bool>> varr(8, std::vector<bool>(8, false));
	possibleMoveTable = varr;
	int x = this->coord.x - 1;
	int y = this->coord.y - 1;
	int checksum = 0;

	if (y + 2 < 8 && x + 1 < 8 && costTable[y + 2][x + 1] < 2) { possibleMoveTable[y + 2][x + 1] = true; }
	if (y + 1 < 8 && x + 2 < 8 && costTable[y + 1][x + 2] < 2) { possibleMoveTable[y + 1][x + 2] = true; }
	if (y - 1 >= 0 && x + 2 < 8 && costTable[y - 1][x + 2] < 2) { possibleMoveTable[y - 1][x + 2] = true; }
	if (y - 2 >= 0 && x + 1 < 8 && costTable[y - 2][x + 1] < 2) { possibleMoveTable[y - 2][x + 1] = true; }
	if (y - 2 >= 0 && x - 1 >= 0 && costTable[y - 2][x - 1] < 2) { possibleMoveTable[y - 2][x - 1] = true; }
	if (y - 1 >= 0 && x - 2 >= 0 && costTable[y - 1][x - 2] < 2) { possibleMoveTable[y - 1][x - 2] = true; }
	if (y + 1 < 8 && x - 2 >= 0 && costTable[y + 1][x - 2] < 2) { possibleMoveTable[y + 1][x - 2] = true; }
	if (y + 2 < 8 && x - 1 >= 0 && costTable[y + 2][x - 1] < 2) { possibleMoveTable[y + 2][x - 1] = true; }
}
