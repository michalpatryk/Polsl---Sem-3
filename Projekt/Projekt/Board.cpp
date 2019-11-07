#include "Board.h"
#include "Rook.h"


Board::Board()
{
	
	//pieces[0][0] = new Piece{ Color::black, 100, 100, PieceType::Rook };
	pieces[0][0] = new Rook{ Color::black, 1, 1, PieceType::Rook };
}


Board::~Board()
{
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
