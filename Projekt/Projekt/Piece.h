#pragma once
#include <SFML/Graphics.hpp>
enum class Color { black = 0, white = 1, zero = 100};
enum class PieceType { none = 0, King, Queen, Rook, Bishop, Knight, Pawn };
struct Coord { unsigned int x; unsigned int y; };

class Piece
{
protected:
	Color color;
	PieceType piece;
public:
	Coord coord;
	Piece();
	Piece(Color color_, int x_, int y_, PieceType piece_) : color(color_), 
		coord{ static_cast<unsigned int>(x_),static_cast<unsigned int>(y_) }, piece(piece_) {};
	~Piece();

	void draw(sf::RenderWindow & window, PieceType piece_);
};

