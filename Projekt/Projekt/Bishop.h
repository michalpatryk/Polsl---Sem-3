#pragma once
#include "Piece.h"
class Bishop :
	public Piece
{
	const PieceType piece = PieceType::Bishop;
public:
	Bishop(Color color_, int x_, int y_) : Piece(color_, x_, y_) { getSprite(); };
	~Bishop();
	void debug();
	PieceType returnType() { return piece; };
	std::string getPieceFilename() { return "/Bishop.png"; };
};

