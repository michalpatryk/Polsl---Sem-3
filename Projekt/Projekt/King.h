#pragma once
#include "Piece.h"
class King :
	public Piece
{
public:
	King(Color color_, int x_, int y_, PieceType piece_) : Piece(color_, x_, y_, piece_) { };
	~King();
	void debug();
};

