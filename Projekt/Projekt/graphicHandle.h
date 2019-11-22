#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Board.h"

void sfmlINIT();
void sfmlMAIN(Board board);

std::string firstCoord(PieceType p, int x, int y);