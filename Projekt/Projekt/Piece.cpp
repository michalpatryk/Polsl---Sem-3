#include "Piece.h"
#include <string>
#include <iostream>


std::string Piece::getColorFilename()
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

void Piece::getSprite()
{
	sf::Context context;	//required to work, ohterwise throws a lot of OpenGl errors. Windowless window.
	sf::Texture texture;
	std::string filename = Piece::getColorFilename();
	filename += getPieceFilename();
	if (!texture.loadFromFile(filename)){
		std::cout << "Error loading texture";
		this->texture.create(200, 200);
		this->sprite.setTexture(this->texture);
	}
	else {
		this->texture = texture;
		this->sprite.setTexture(this->texture);
	}
	//else std::cout << "Texture loaded :D";
	
}

void Piece::debug()
{
	std::cout << "Testing" <<std::endl;
}
