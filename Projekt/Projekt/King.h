#pragma once
#include "Piece.h"
class King :
	public Piece
{
	const PieceType piece = PieceType::King;
public:
	King(Color color_, int x_, int y_) : Piece(color_, x_, y_) { };
	~King();
	void debug();
};

