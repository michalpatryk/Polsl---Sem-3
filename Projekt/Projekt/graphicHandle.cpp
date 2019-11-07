#include <SFML/Graphics.hpp>
#include "graphicHandle.h"
#define HEIGHT 1000
#define WIDTH 1000
void sfmlINIT()
{

}

void sfmlMAIN()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Chess");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	sf::RectangleShape rectangle(sf::Vector2f(100.f, 100.f));
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.draw(rectangle);
		window.display();
	}
}

void boardDraw()
{
	sf::RectangleShape rectangle(sf::Vector2f(100.f, 100.f));
}
