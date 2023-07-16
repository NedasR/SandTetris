#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include "Sand.hpp"
#define GRID_OFFSET_X 200;
#define SAND_SIZE 10.f;


class Grid
{
private:

	std::vector<std::vector<int>> m_grid;
	sf::RectangleShape m_rectangle;
	sf::Vector2i m_gridSize;

public:

	Grid();

	void run();

	void gridSize(const int& sizeX, const int& sizeY);

	void gravity();

	void drawGrid(sf::RenderWindow& window);

	void spawnTetromino();

	void swap(int Y, int X,const int Xaxis,const int Yaxis);
 };