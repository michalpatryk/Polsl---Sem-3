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

void King::createPossibleMoveTable()
{
	std::vector<std::vector<bool>> varr(8, std::vector<bool>(8, false));
	possibleMoveTable = varr;
	int x = this->coord.x - 1;
	int y = this->coord.y - 1;
	int checksum = 0;

	if (y + 1 < 8 && x - 1 >= 0 && costTable[y + 1][x - 1] < 2) { possibleMoveTable[y + 1][x - 1] = true; }
	if (y + 1 < 8 && costTable[y + 1][x] < 2) { possibleMoveTable[y + 1][x] = true; }
	if (y + 1 < 8 && x + 1 < 8 && costTable[y + 1][x + 1] < 2) { possibleMoveTable[y + 1][x + 1] = true; }
	if (x + 1 < 8 && costTable[y][x + 1] < 2) { possibleMoveTable[y][x + 1] = true; }
	if (x - 1 >= 0 && costTable[y][x - 1] < 2) { possibleMoveTable[y][x - 1] = true; }
	if (y - 1 >= 0 && x + 1 < 8 && costTable[y - 1][x + 1] < 2) { possibleMoveTable[y - 1][x + 1] = true; }
	if (y - 1 >= 0 && costTable[y - 1][x] < 2) { possibleMoveTable[y - 1][x] = true; }
	if (y - 1 >= 0 && x - 1 >= 0 && costTable[y - 1][x - 1] < 2) { possibleMoveTable[y - 1][x - 1] = true; }
}
