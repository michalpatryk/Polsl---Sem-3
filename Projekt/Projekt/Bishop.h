#pragma once
#include "Piece.h"
class Bishop :
	public Piece
{
public:
	Bishop(Color color_, int x_, int y_, PieceType piece_) : Piece(color_, x_, y_, piece_) { };
	~Bishop();
	void debug();
};

