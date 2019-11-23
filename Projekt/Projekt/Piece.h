#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
enum class Color { black = 0, white = 1, zero = 100};
enum class PieceType { none = 0, King=100, Queen=10, Rook=4, Bishop=3, Knight=2, Pawn=1 };
struct Coord { int x; int y; };

class Piece
{

protected:
	std::vector<std::vector<int>> costTable;	//general move costTable
	std::vector<std::vector<bool>> possibleMoveTable; //strict table for each kind of piece
	Color color = Color::zero;
	std::string getColorFilename();
	virtual std::string getPieceFilename() { return ""; };
	
public:

	Coord coord;
	sf::Sprite sprite;
	sf::Texture texture;
	bool isHeld = 0;	//makes sure the piece is rendered on top
	//Constructors
	Piece();
	Piece(Color color_, int x_, int y_) : color(color_), 
		coord{ x_,y_ } { };
	~Piece();
	//operators
	Piece operator=(const Piece & piece_);
	//innerworkings
	void loadCostTable(std::vector<std::vector<int>> cT);
	virtual void createPossibleMoveTable() {};	//Explaination here for all child classes:
												//We create a 2d array that contains either 1 if move is possible to this position
												// or 0 if the move is impossible
	void draw(sf::RenderWindow & window);
	void getSprite();
	
	virtual PieceType returnType() { return PieceType::none; };
	Color returnColor() { return this->color; };
	virtual void debug();
	
};

