#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "Board.h"
#include "microVector.h"

void sfmlINIT(sf::RenderWindow & window);
void sfmlMAIN(Board board);
void sfmlEND(sf::RenderWindow & window);

std::string firstCoord(PieceType p, int x, int y);
void secondCoordAndVectorHandle(int x, int y, std::vector<std::string> & v, std::string & s);
void secondCoordAndVectorHandleMV(int x, int y, MicroVector<std::string> & v, std::string & s);
void colorDisplay(bool isWhite, sf::RenderWindow & window);