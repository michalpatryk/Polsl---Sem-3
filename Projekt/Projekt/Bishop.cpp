#include "Bishop.h"
#include <iostream>




Bishop::~Bishop()
{
}

sf::Sprite& Bishop::getSprite()
{
	sf::Texture texture;
	std::string filename = Piece::getFilename();
	filename += "/Bishop.png";
	if (!texture.loadFromFile(filename))
	{
		std::cout << "Error loading texture";
	}
	else std::cout << "Texture loaded :D";
	this->texture = texture;
	sf::Sprite sprite;
	sprite.setTexture(this->texture);
	this->sprite = sprite;
	
	return sprite;
}

void Bishop::debug()
{
	Piece::debug();
	std::cout << "Bishop coord: " << this->coord.x << this->coord.y << std::endl;
}
