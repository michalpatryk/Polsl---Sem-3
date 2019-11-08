#pragma once
#include "Piece.h"
class Queen :
	public Piece
{
	const PieceType piece = PieceType::Queen;
public:
	Queen(Color color_, int x_, int y_) : Piece(color_, x_, y_) { getSprite(); };
	~Queen();
	void debug();
	std::string getPieceFilename() { return "/Queen.png"; };
};

