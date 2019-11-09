#include <SFML/Graphics.hpp>
#include "graphicHandle.h"
#include "Board.h"
#include <iostream>

#define HEIGHT 1000
#define WIDTH 1000
void sfmlINIT()
{

}

void sfmlMAIN(Board board)
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Chess", sf::Style::Close);
	float dx = 0, dy = 0;
	bool isMove = 0;
	int indexX = 0, indexY = 0;
	while (window.isOpen())
	{
		sf::Vector2i position = sf::Mouse::getPosition(window);
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.key.code == sf::Mouse::Left) {
					for (int i = 0; i < 8; i++) {
						for (int j = 0; j < 8; j++) {
							if(board.pieces[i][j]!=nullptr && 
								board.pieces[i][j]->sprite.getGlobalBounds().contains(position.x, position.y)) {
								isMove = true;
								indexX = i;
								indexY = j;
							}
						}
					}
				}
			}
			if (event.type == sf::Event::MouseButtonReleased) {
				if (event.key.code == sf::Mouse::Left) {
					isMove = false;
				}
			}
		}
		if (isMove) {
			board.pieces[indexX][indexY]->coord.x = position.x/100;
			board.pieces[indexX][indexY]->coord.y = position.y/100;
		}
		
		window.clear();
		board.draw(window);
		board.drawPieces(window);
		window.display();
	}
}

