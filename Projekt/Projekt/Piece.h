#pragma once
#include <SFML/Graphics.hpp>
enum class Color { black = 0, white = 1, zero = 100};
enum class PieceType { none = 0, King, Queen, Rook, Bishop, Knight, Pawn };
struct Coord { int x; int y; };

class Piece
{
protected:
	Color color;
	PieceType piece;
public:
	Coord coord;
	Piece();
	Piece(Color color_, int x_, int y_, PieceType piece_) : color(color_), 
		coord{x_,y_ }, piece(piece_) {};
	~Piece();

	Piece operator=(const Piece & piece_);

	void draw(sf::RenderWindow & window, PieceType piece_);
	virtual void debug();
};

