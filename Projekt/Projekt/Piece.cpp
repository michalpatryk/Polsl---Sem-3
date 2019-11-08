#include "Piece.h"
#include <string>
#include <iostream>


std::string Piece::getFilename()
{
	std::string filename = "../Pieces_Images";
	if (color == Color::white) {
		filename += "/White";
	}
	else if (color == Color::black) {
		filename += "/Black";
	}
	return filename;
}

Piece::Piece()
{
	color = Color::zero;
	coord.x = 0;
	coord.y = 0;
}


Piece::~Piece()
{
}

Piece Piece::operator=(const Piece & piece_)
{
	Piece returner{ piece_.color, piece_.coord.x, piece_.coord.y};
	return returner;
}

void Piece::draw(sf::RenderWindow & window)
{

	/*sf::Vector2u wsize = window.getSize();
	float scale = wsize.x / 10;
	float coordX = (this->coord.x * scale) + scale;
	float coordY = (this->coord.y * scale) + scale;
	float size = wsize.x / 15;
*/
	/*sf::Vector2f targetSize(10.0f, 10.0f);
	sprite.setScale(targetSize);*/
	window.draw(sprite);

}

void Piece::debug()
{
	std::cout << "Testing" <<std::endl;
}
