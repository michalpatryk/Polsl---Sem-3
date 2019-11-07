#pragma once
#include "Piece.h"
#include <SFML/Graphics.hpp>

class Board
{
	Piece *pieces;
public:
	Board();
	
	~Board();
	void draw(sf::RenderWindow & window);
};

