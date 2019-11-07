#pragma once
#include "Piece.h"
#include <SFML/Graphics.hpp>

class Board
{
	Piece list[8][8];
public:
	Board();
	
	~Board();
	void draw(sf::RenderWindow & window);
};

