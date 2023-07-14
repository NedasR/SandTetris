#include "Gird.hpp"

Grid::Grid()
{
	int gridOffsetX = GRID_OFFSET_X;
	int sandSize = SAND_SIZE;

	gridSize(40, 80);
	for (int Y = 0; Y < m_gridSize.y; Y++)
	{
		for (int X = 0; X < m_gridSize.x; X++)
		{
			assignBlank(m_grid[Y][X], Y, X);
			m_grid[Y][X].assingPosRect(Y, X, gridOffsetX, sandSize);
		}
	}
}

void Grid::gridSize(const int& sizeX,const int& sizeY)
{
	m_gridSize.y = sizeY - 1;
	m_gridSize.x = sizeX - 1;
	m_grid.resize(sizeY);
	for (int height = 0; height < sizeY; height++)
	{
		m_grid[height].resize(sizeX);
	}
}

void Grid::assignBlank(Sand& sand, const int& collum, const int& row)
{
	// collum and row not only assignes which sand but it's cord
	sand.coordinates.m_column = collum;
	sand.coordinates.m_row = row;
	sand.type = Type::blank;
}

void Grid::drawGrid(sf::RenderWindow& window)
{
	for (int Y = 0; Y < m_gridSize.y; Y++)
	{
		for (int X = 0; X < m_gridSize.x; X++)
		{
			if (m_grid[Y][X].type == Type::blank)
			{
				continue;
			}
			m_grid[Y][X].drawSand(window);
		}
	}
}