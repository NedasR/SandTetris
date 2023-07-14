#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include "Sand.hpp"
#define GRID_OFFSET_X 200;
#define SAND_SIZE 10;

class Grid
{
private:

	std::vector<std::vector<Sand>> m_grid;
	sf::Vector2i m_gridSize;

public:

	Grid();

	void gridSize(const int& sizeX, const int& sizeY);

	void assignBlank(Sand& sand, const int& collum, const int& row);

	void drawGrid(sf::RenderWindow& window);
 };