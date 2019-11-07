#pragma once
#include "Piece.h"
class Queen :
	public Piece
{
public:
	Queen(Color color_, int x_, int y_, PieceType piece_) : Piece(color_, x_, y_, piece_) { };
	~Queen();
	void debug();
};

