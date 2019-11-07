#include <SFML/Graphics.hpp>
#include "graphicHandle.h"
#include "Board.h"

#define HEIGHT 800
#define WIDTH 800
void sfmlINIT()
{

}

void sfmlMAIN(Board board)
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Chess");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		board.draw(window);
		window.display();
	}
}

void boardDraw()
{
	sf::RectangleShape rectangle(sf::Vector2f(100.f, 100.f));
}
