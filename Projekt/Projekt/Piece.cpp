#include "Piece.h"



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
