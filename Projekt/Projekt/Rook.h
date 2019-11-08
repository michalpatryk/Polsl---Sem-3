#pragma once
#include "Piece.h"
class Rook :
	public Piece
{
	const PieceType piece = PieceType::Rook;
public:
	Rook(Color color_, int x_, int y_) : Piece(color_, x_, y_) { };
	~Rook();
	void debug();
};

