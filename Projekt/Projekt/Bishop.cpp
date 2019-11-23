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

void Bishop::createPossibleMoveTable()
{
	std::vector<std::vector<bool>> varr(8, std::vector<bool>(8, false));
	possibleMoveTable = varr;
	int x = this->coord.x - 1;
	int y = this->coord.y - 1;
	int checksum = -2;

	int dx = 1, dy = 1;
	for (int i = x, j = y; i < 8 && j < 8; i++, j++) {

		checksum += costTable[j][i];
		if (checksum < 2) possibleMoveTable[j][i] = true;
	}
	checksum = -2;
	dx = -1; dy = 1;
	for (int i = x, j = y; i >= 0 && j < 8; i--, j++) {
		checksum += costTable[j][i];
		if (checksum < 2) possibleMoveTable[j][i] = true;
	}

	checksum = -2;
	dx = 1; dy = -1;
	for (int i = x, j = y; i < 8 && j >= 0; i++, j--) {
		checksum += costTable[j][i];
		if (checksum < 2) possibleMoveTable[j][i] = true;
	}
	checksum = -2;
	dx = -1; dy = -1;
	for (int i = x, j = y; i >= 0 && j >= 0; i--, j--) {
		checksum += costTable[j][i];
		if (checksum < 2) possibleMoveTable[j][i] = true;
	}
	possibleMoveTable[y][x] = false;
}
