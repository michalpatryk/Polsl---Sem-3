#pragma once
enum class Color { black = 0, white = 1 };
class Piece
{
	Color color;
public:
	int x, y;	//xy coord
	Piece();
	~Piece();
};

