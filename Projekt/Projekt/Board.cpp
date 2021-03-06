#include "Board.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"
#include <iostream>
Board::Board()
{
	//Litery u g�rze - numery kolumn. Cyfry z boku - numery wierszy
	//[wiersz][kolumna]
	//[0][0] - lewy gorny rog

	pieces[0][0] = new Rook{ Color::black, 1, 1 };
	pieces[0][1] = new Knight{ Color::black, 2, 1 };
	pieces[0][2] = new Bishop{ Color::black, 3, 1 };
	pieces[0][3] = new Queen{ Color::black, 4, 1 };
	pieces[0][4] = new King{ Color::black, 5, 1 };
	pieces[0][5] = new Bishop{ Color::black, 6, 1 };
	pieces[0][6] = new Knight{ Color::black, 7, 1 };
	pieces[0][7] = new Rook{ Color::black, 8, 1 };
	for (int i = 0; i < 8; i++) {
		pieces[1][i] = new Pawn{ Color::black, (i + 1), 2 };
	}
	for (int i = 0; i < 8; i++) {
		pieces[6][i] = new Pawn{ Color::white, (i + 1), 7 };
	}
	pieces[7][0] = new Rook{ Color::white, 1, 8 };
	pieces[7][1] = new Knight{ Color::white, 2, 8 };
	pieces[7][2] = new Bishop{ Color::white, 3, 8 };
	pieces[7][3] = new King{ Color::white, 4, 8 };
	pieces[7][4] = new Queen{ Color::white, 5, 8 };
	pieces[7][5] = new Bishop{ Color::white, 6, 8 };
	pieces[7][6] = new Knight{ Color::white, 7, 8 };
	pieces[7][7] = new Rook{ Color::white, 8, 8 };
	//Might redo for some more profesional code, who knows
}


Board::~Board()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			delete pieces[i][j];
		}
	}
}

void Board::draw(sf::RenderWindow & window)
{
	sf::Color fields[8][8];
	bool green = true;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			green = ((i + j) % 2);
			if (green == true) {
				sf::Color colour{ 181, 136, 99, 255 };
				fields[i][j] = colour;
			}
			else {
				sf::Color colour{ 240, 217, 181, 255 };
				fields[i][j] = colour;
			}

		}
	}
	sf::Vector2u wsize = window.getSize();
	sf::Vector2u pos = wsize;
	wsize.x *= 0.8;
	wsize.y *= 0.8;
	int length = static_cast<int>(wsize.x / 8);
	int posx = static_cast<int>(pos.x*0.1);
	int posy = static_cast<int>(pos.y*0.1);
	int offset = static_cast<int>(posx);


	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			sf::RectangleShape field(sf::Vector2f(length, length));
			field.setFillColor(fields[i][j]);
			field.setPosition(posx, posy);
			window.draw(field);
			posx += length;
		}
		posx = offset;
		posy += length;
	}
}

void Board::drawPieces(sf::RenderWindow & window)
{
	bool priority = false;
	int priorityX = 0, prioriryY = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (pieces[i][j] != nullptr) {
				if (pieces[i][j]->isHeld == 1) {
					priority = true;
					priorityX = i; prioriryY = j;
				}
				else pieces[i][j]->drawMV(window);
			}
		}
	}
	if (priority == true) pieces[priorityX][prioriryY]->drawMV(window);
}

void Board::move(int initX, int initY)
{
	int tX = pieces[initY][initX]->coord.x - 1;	//coord is 1-8, changing to 0-7
	int tY = pieces[initY][initX]->coord.y - 1;
	if (pieces[tY][tX] != nullptr) {	//enter killing protocol
		Piece temp{ pieces[tY][tX] };
		lost.push_back(temp);
		if (pieces[tY][tX]->returnType() == PieceType::King) {
			this->gameOver = true;
		}
		delete pieces[tY][tX];
		pieces[tY][tX] = pieces[initY][initX];
		pieces[initY][initX] = nullptr;
	}
	else {
		pieces[tY][tX] = pieces[initY][initX];
		pieces[initY][initX] = nullptr;
	}


}

std::vector<std::vector<int>> Board::moveCost(Color c)
{
	std::vector<std::vector<int>> varr(8, std::vector<int>(8));	//create 2d vector of size [8][8]
					//at the beggining the function was done with new and delete, but using std::vector is much more intuitive and safer

	int whiteCost, blackCost;		//set the cost of a given color. Makes the function universal
	if (c == Color::white) { whiteCost = 2; blackCost = 1; }	//if color == same as my piece, cost is 2
	else if (c == Color::black) { whiteCost = 1; blackCost = 2; }

	for (int i = 0; i < 8; i++) {	//assign cost to each location
		for (int j = 0; j < 8; j++) {
			if (this->pieces[i][j] != nullptr) {
				if (this->pieces[i][j]->returnColor() == Color::white) { varr[i][j] = whiteCost; }
				else if (this->pieces[i][j]->returnColor() == Color::black) { varr[i][j] = blackCost; }
			}
			else varr[i][j] = 0;
		}
	}
	return varr;
}

MicroVector<MicroVector<int>> Board::moveCostMV(Color c)
{

	MicroVector<MicroVector<int>> varr(8);
	for (int i = 0; i < 8; i++) {
		varr[i].clearAndSetSize(8);
	}

	int whiteCost, blackCost;		//set the cost of a given color. Makes the function universal
	if (c == Color::white) { whiteCost = 2; blackCost = 1; }	//if color == same as my piece, cost is 2
	else if (c == Color::black) { whiteCost = 1; blackCost = 2; }

	for (int i = 0; i < 8; i++) {	//assign cost to each location
		for (int j = 0; j < 8; j++) {
			if (this->pieces[i][j] != nullptr) {
				if (this->pieces[i][j]->returnColor() == Color::white) { varr[i][j] = whiteCost; }
				else if (this->pieces[i][j]->returnColor() == Color::black) { varr[i][j] = blackCost; }
			}
			else varr[i][j] = 0;
		}
	}

	return varr;
}
