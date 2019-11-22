#include <SFML/Graphics.hpp>
#include "graphicHandle.h"
#include "Board.h"
#include <iostream>
#include <vector>

#define HEIGHT 1000
#define WIDTH 1000
void sfmlINIT()
{

}

void sfmlMAIN(Board board)
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Chess", sf::Style::Close);	//we create a window here
	float dx = 0, dy = 0;
	bool isMove = 0;
	int indexX = 0, indexY = 0;
	std::vector<std::string> moveList;
	std::string currentMove;	//get current move

	while (window.isOpen())
	{
		sf::Vector2i position = sf::Mouse::getPosition(window);
		sf::Event event;
		
		while (window.pollEvent(event))
		{
			
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonPressed) {	//Any mouse button pressed
				if (event.key.code == sf::Mouse::Left) {		//Left mouse button
					for (int i = 0; i < 8; i++) {				//Now we lapse through every sprite we can find
						for (int j = 0; j < 8; j++) {
							if(board.pieces[i][j]!=nullptr &&	//Check if its in right position
								board.pieces[i][j]->sprite.getGlobalBounds().contains(position.x, position.y)) {
								board.pieces[i][j]->isHeld = 1;	//will allow us to display possible moves
								isMove = true;					//changing isMove flag so that the piece floats to where our mouse is
								indexX = i;						//tells the X coord of currently moving piece
								indexY = j;
								currentMove += firstCoord(board.pieces[i][j]->returnType(), board.pieces[i][j]->coord.x, board.pieces[i][j]->coord.y);
								//if (board.pieces[i][j]->returnType() == PieceType::Pawn) { currentMove += "P"; }
								//currentMove += board.pieces[i][j]->returnType();
								//currentMove += std::to_string(board.pieces[i][j]->coord.x);
								//currentMove += std::to_string(board.pieces[i][j]->coord.y);
								//currentMove += "-";
							}
						}
					}
				}
			}
			if (event.type == sf::Event::MouseButtonReleased) {
				if (event.key.code == sf::Mouse::Left) {	//releases piece
					board.pieces[indexX][indexY]->isHeld = 0;
					isMove = false;
					currentMove += std::to_string(board.pieces[indexX][indexY]->coord.x);
					currentMove += std::to_string(board.pieces[indexX][indexY]->coord.y);
					std::cout << currentMove << std::endl;
					moveList.push_back(currentMove);
					currentMove.clear();
				}
			}
		}
		if (isMove) {	//moves a piece arround the board
			board.pieces[indexX][indexY]->coord.x = position.x/100;
			board.pieces[indexX][indexY]->coord.y = position.y/100;
		}
		
		window.clear();
		board.draw(window);
		board.drawPieces(window);
		window.display();
	}
}

std::string firstCoord(PieceType p, int x, int y)
{
	std::string r;

	switch (p) {
	case PieceType::Bishop: r += "B"; break;
	case PieceType::King: r += "K"; break;
	case PieceType::Knight: r += "N"; break;
	case PieceType::Pawn: r += "P"; break;
	case PieceType::Queen: r += "Q"; break;
	case PieceType::Rook: r += "R"; break;
	}

	x += 96;			//convert int coord x into char
	r += (char)x;		//^
	r += std::to_string(y);
	r += "-";
	return r;
}

