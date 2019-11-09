#pragma once
#include <SFML/Graphics.hpp>
enum class Color { black = 0, white = 1, zero = 100};
enum class PieceType { none = 0, King=100, Queen=10, Rook=4, Bishop=3, Knight=2, Pawn=1 };
struct Coord { int x; int y; };

class Piece
{

protected:
	Color color;
	std::string getColorFilename();
	virtual std::string getPieceFilename() { return ""; };
public:
	Coord coord;
	sf::Sprite sprite;
	sf::Texture texture;
	bool isHeld = 0;	//makes sure the piece is rendered on top

	Piece();
	Piece(Color color_, int x_, int y_) : color(color_), 
		coord{ x_,y_ } { };
	~Piece();

	Piece operator=(const Piece & piece_);


	void draw(sf::RenderWindow & window);
	void getSprite();
	
	virtual void debug();
	
};

