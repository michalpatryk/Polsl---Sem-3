#pragma once
#include "Piece.h"
class Pawn :
	public Piece
{
public:
	Pawn(Color color_, int x_, int y_, PieceType piece_) : Piece(color_, x_, y_, piece_) { };
	~Pawn();
	void debug();
};

