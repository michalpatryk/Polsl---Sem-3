#pragma once
#include "Piece.h"
class Rook :
	public Piece
{
public:
	Rook(Color color_, int x_, int y_, PieceType piece_) : Piece (color_, x_, y_, piece_){};
	~Rook();
};

