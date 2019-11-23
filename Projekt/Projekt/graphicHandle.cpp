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
								currentMove += firstCoord(board.pieces[i][j]->returnType(), board.pieces[i][j]->coord.x, board.pieces[i][j]->coord.y);	//move register
								board.pieces[i][j]->loadCostTable(board.moveCost(board.pieces[i][j]->returnColor()));
								//createPossibleMoveTable()
							}
						}
					}
				}
			}
			if (event.type == sf::Event::MouseButtonReleased) {
				if (event.key.code == sf::Mouse::Left) {	//releases piece
					board.pieces[indexX][indexY]->isHeld = 0;
					isMove = false;
					secondCoordAndVectorHandle(board.pieces[indexX][indexY]->coord.x, board.pieces[indexX][indexY]->coord.y, moveList, currentMove);	//move register
					if(!moveList.empty()) std::cout << moveList.back() << std::endl;	//print last move
					// if (Piece.canMove(indexX, indexY, /coord.x/, /coord.y/) board.move(indexX, indexY, /coord.x/, /coord.y/)	//check and approve changes
					// else {								//and by doing so, we change the board.pieces[][] table, so changes are final
					//board.pieces[indexX][indexY]->coord.x = indexX;	//we revert the changes
					//board.pieces[indexX][indexY]->coord.y = indexY;
					//}
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
	y -= 9;				//flip coordinates eq 1 to 8, 2 to 7 etc
	y *= -1;
	r += std::to_string(y);		
	r += "-";
	return r;
}

void secondCoordAndVectorHandle(int x, int y, std::vector<std::string>& v, std::string & s)
{
	if (!s.empty()) {
		x += 96;
		s += (char)x;
		y -= 9;
		y *= -1;
		s += std::to_string(y);
		v.push_back(s);
	}
	s.clear();
	
}

