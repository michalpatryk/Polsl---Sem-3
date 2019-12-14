#pragma once
#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "microVector.h"

class Board
{
	Piece *pieces[8][8];
	std::vector<Piece> lost;
public:

	Board();
	
	~Board();
	void draw(sf::RenderWindow & window);
	void drawPieces(sf::RenderWindow &window);
	void move(int initX, int initY);

	std::vector<std::vector<int>> moveCost(Color c);

	//friend Piece;
	friend void sfmlMAIN(Board board);	//needed for sprite acces
};

