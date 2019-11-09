#pragma once
#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Board
{
	Piece *pieces[8][8];
	std::vector<Piece> lost;
public:

	Board();
	
	~Board();
	void draw(sf::RenderWindow & window);
	void drawPieces(sf::RenderWindow &window);

	friend Piece;
	friend void sfmlMAIN(Board board);	//needed for sprite acces
};

