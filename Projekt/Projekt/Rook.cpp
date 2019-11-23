#include "Rook.h"
#include <iostream>




Rook::~Rook()
{
}

void Rook::debug()
{
	Piece::debug();
	std::cout << "Rook coord: " << this->coord.x << this->coord.y << std::endl;
}

void Rook::createPossibleMoveTable()
{
	std::vector<std::vector<bool>> varr(8, std::vector<bool>(8, false));
	possibleMoveTable = varr;
	int x = this->coord.x - 1;
	int y = this->coord.y - 1;
	int checksum = -2;
	for (int i = x; i < 8; i++) {//go through horizontal -->
		checksum += costTable[y][i];
		if (checksum < 2) possibleMoveTable[y][i] = true;
	}
	checksum = -2;
	for (int i = x; i >= 0; i--) {//go through horizontal <--
		checksum += costTable[y][i];
		if (checksum < 2) possibleMoveTable[y][i] = true;
	}
	checksum = -2;

	for (int i = y; i < 8; i++) {//go through horizontal down
		checksum += costTable[i][x];
		if (checksum < 2) possibleMoveTable[i][x] = true;
	}
	checksum = -2;
	for (int i = y; i >= 0; i--) {//go through horizontal up
		checksum += costTable[i][x];
		if (checksum < 2) possibleMoveTable[i][x] = true;
	}
	possibleMoveTable[y][x] = false;
}
