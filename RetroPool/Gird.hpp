#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#define GRID_OFFSET_X 200;
#define SAND_SIZE 10.f;

class Grid
{
private:
	std::vector<std::vector<int>> m_grid;
	sf::RectangleShape m_rectangle;
	sf::Sprite m_playerTetromino;
	sf::Texture m_texture;
	sf::Vector2i m_gridSize;
	int m_playerGravity;
	int TX;

public:

	Grid();

	void run();

	void gridSize(const int& sizeX, const int& sizeY);

	void gravity();

	void playerGravity();

	void drawGrid(sf::RenderWindow& window);

	void rotationUpdate() 
	{
		
		TX++;
	    m_playerTetromino.setRotation(90 * TX);
		if (TX == 4)
		{
			TX = 0;
		}
	}

	void spawnTetromino();

	bool swap(int Y, int X,const int Xaxis,const int Yaxis);
 };