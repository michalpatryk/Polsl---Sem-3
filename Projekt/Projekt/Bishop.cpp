#include "Bishop.h"
#include <iostream>




Bishop::~Bishop()
{

}

void Bishop::getSprite()
{
	sf::Context context;	//required to work, ohterwise throws a lot of OpenGl errors. Windowless window.
	sf::Texture texture;
	std::string filename = Piece::getFilename();
	filename += "/Bishop.png";
	if (!texture.loadFromFile(filename))
	{
		std::cout << "Error loading texture";
	}
	else std::cout << "Texture loaded :D";
	this->texture = texture;
	this->sprite.setTexture(this->texture);
	//sf::Sprite sprite;
	//sprite.setTexture(this->texture);
	//this->sprite = sprite;

}

void Bishop::debug()
{
	Piece::debug();
	std::cout << "Bishop coord: " << this->coord.x << this->coord.y << std::endl;
}
