#pragma once
#include "Piece.h"
class Pawn :
	public Piece
{
	PieceType piece = PieceType::Pawn;	//PAWN IS NOT CONSTANT - intentional, u can upgrade it
public:
	Pawn(Color color_, int x_, int y_) : Piece(color_, x_, y_) { };
	~Pawn();
	void debug();
};

