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


	for (int i = x, j = y; i < 8 && j < 8; i++, j++) {

		checksum += costTable[j][i];
		if (checksum < 2) possibleMoveTable[j][i] = true;
	}
	checksum = -2;
	for (int i = x, j = y; i >= 0 && j < 8; i--, j++) {
		checksum += costTable[j][i];
		if (checksum < 2) possibleMoveTable[j][i] = true;
	}

	checksum = -2;
	for (int i = x, j = y; i < 8 && j >= 0; i++, j--) {
		checksum += costTable[j][i];
		if (checksum < 2) possibleMoveTable[j][i] = true;
	}
	checksum = -2;
	for (int i = x, j = y; i >= 0 && j >= 0; i--, j--) {
		checksum += costTable[j][i];
		if (checksum < 2) possibleMoveTable[j][i] = true;
	}
	possibleMoveTable[y][x] = false;
}

void Bishop::createPossibleMoveTableMV()
{
	MicroVector<MicroVector<bool>> varr(8);
	for (int i = 0; i < 8; i++) {
		varr[i].clearAndSetSize(8);
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			varr[i][j] = false;
		}
	}
	//bool init val is true
	possibleMoveTableMV = varr;
	int x = this->coord.x - 1;
	int y = this->coord.y - 1;
	int checksum = -2;

	for (int i = x, j = y; i < 8 && j < 8; i++, j++) {

		checksum += costTableMV[j][i];
		if (checksum < 2) possibleMoveTableMV[j][i] = true;
	}
	checksum = -2;
	for (int i = x, j = y; i >= 0 && j < 8; i--, j++) {
		checksum += costTableMV[j][i];
		if (checksum < 2) possibleMoveTableMV[j][i] = true;
	}

	checksum = -2;
	for (int i = x, j = y; i < 8 && j >= 0; i++, j--) {
		checksum += costTableMV[j][i];
		if (checksum < 2) possibleMoveTableMV[j][i] = true;
	}
	checksum = -2;
	for (int i = x, j = y; i >= 0 && j >= 0; i--, j--) {
		checksum += costTableMV[j][i];
		if (checksum < 2) possibleMoveTableMV[j][i] = true;
	}
	possibleMoveTableMV[y][x] = false;

}
