#include "Piece.h"
#include <string>



Piece::Piece()
{
	color = Color::zero;
	piece = PieceType::none;
	coord.x = 0;
	coord.y = 0;
}


Piece::~Piece()
{
}

void Piece::draw(sf::RenderWindow & window, PieceType piece_)
{

	sf::Vector2u wsize = window.getSize();
	float scale = wsize.x / 10;
	float coordX = (this->coord.x * scale) + scale;
	float coordY = (this->coord.y * scale) + scale;
	float size = wsize.x / 15;
	sf::Texture texture;
	std::string filename = "";

}
