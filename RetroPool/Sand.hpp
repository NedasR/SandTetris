#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


enum class Type
{
	blank,
	red,
	green,
};



struct Cords
{
	int m_column, m_row;
};

class Sand
{
private:

	sf::RectangleShape sandShape;

public:

	Cords coordinates;
	 
	Type type;
	Sand();
	
	void drawSand(sf::RenderWindow& window);

	void assingPosRect(const int& collum, const int& row,const int gridOffsetX,const float sandSize);
};