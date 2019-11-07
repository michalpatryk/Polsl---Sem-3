#pragma once
class Piece
{
	enum color { black = 0, white = 1 };
public:
	int x, y;	//xy coord
	Piece();
	~Piece();
};

