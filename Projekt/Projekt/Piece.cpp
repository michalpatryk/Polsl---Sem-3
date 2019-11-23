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

void Piece::loadCostTable(std::vector<std::vector<int>> cT)
{
	costTable = cT;
}

void Piece::draw(sf::RenderWindow & window)
{
	sprite.setPosition(coord.x * 100 + 10, coord.y * 100 + 10);
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
		this->texture.setSmooth(true);
		this->sprite.setTexture(this->texture);
	}
	this->sprite.setScale(0.1f, 0.1f);
	this->sprite.setPosition(coord.y*100+10, coord.x*100+10);
}

void Piece::debug()
{
	std::cout << "Testing" <<std::endl;
}
