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

	pieces[0][0] = new Rook{ Color::black, 1, 1, PieceType::Rook };
	pieces[0][1] = new Knight{ Color::black, 1, 2, PieceType::Knight };
	pieces[0][2] = new Bishop{ Color::black, 1, 3, PieceType::Bishop };
	pieces[0][3] = new Queen{ Color::black, 1, 4, PieceType::Queen };
	pieces[0][4] = new King{ Color::black, 1, 5, PieceType::King };
	pieces[0][5] = new Bishop{ Color::black, 1, 6, PieceType::Bishop };
	pieces[0][6] = new Knight{ Color::black, 1, 7, PieceType::Knight };
	pieces[0][7] = new Rook{ Color::black, 1, 8, PieceType::Rook };
	for (int i = 0; i < 7; i++) {
		pieces[1][i] = new Pawn{ Color::black, 1, (i+1), PieceType::Pawn };
	}
	pieces[0][1]->debug();
	if (pieces[4][4] == nullptr) {
		std::cout << "its a nullptr";
	}
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
