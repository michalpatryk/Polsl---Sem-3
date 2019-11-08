#pragma once
#include "Piece.h"
class Knight :
	public Piece
{
	const PieceType piece = PieceType::Knight;
public:
	Knight(Color color_, int x_, int y_) : Piece(color_, x_, y_) { getSprite(); };
	~Knight();
	void debug();
	std::string getPieceFilename() { return "/Knight.png"; };
};

