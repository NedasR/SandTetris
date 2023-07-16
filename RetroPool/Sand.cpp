#include "Sand.hpp"

Sand::Sand()
{

}

void Sand::drawSand(sf::RenderWindow& window)
{
	window.draw(sandShape);
	sf::Color a;
}

void Sand::assingPosRect(const int& collum, const int& row,const int gridOffsetX,const float sandSize)
{
	this->sandShape.setPosition((row * sandSize) + gridOffsetX, collum * sandSize);
	this->sandShape.setSize(sf::Vector2f(sandSize, sandSize));
}