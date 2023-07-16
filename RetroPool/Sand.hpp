#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class Sand
{
private:

	sf::RectangleShape sandShape;

public:
	Sand();
	
	void drawSand(sf::RenderWindow& window);

	void assingPosRect(const int& collum, const int& row,const int gridOffsetX,const float sandSize);
};