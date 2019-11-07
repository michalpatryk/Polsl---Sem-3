#pragma once
#include "Piece.h"
class Knight :
	public Piece
{
public:
	Knight(Color color_, int x_, int y_, PieceType piece_) : Piece(color_, x_, y_, piece_) { };
	~Knight();
	void debug();
};

