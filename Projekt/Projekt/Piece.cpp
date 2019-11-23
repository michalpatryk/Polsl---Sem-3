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
	
	//sf::CircleShape circle(40.f);		//costTable debug
	//circle.setFillColor(sf::Color::Green);
	//if (!costTable.empty() && isHeld == true) {
	//	for (int i = 0; i < 8; i++) {
	//		for (int j = 0; j < 8; j++) {
	//			if (costTable[j][i] == 0 || costTable[j][i] == 1) {
	//				circle.setPosition(100 + i * 100, 100 + j * 100);
	//				window.draw(circle);
	//			}
	//		}
	//	}
	//}
	

	//
	//do some possible move table drawing
	sf::CircleShape circle(40.f);		//costTable debug
	circle.setFillColor(sf::Color::Green);
	if (!possibleMoveTable.empty() && isHeld == true) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (possibleMoveTable[j][i] == true) {
					circle.setPosition(100 + i * 100, 100 + j * 100);
					window.draw(circle);
				}
			}
		}
	}
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
