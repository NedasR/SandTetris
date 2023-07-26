#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#define GRID_OFFSET_X 200
#define SAND_SIZE 5.f
#define TEXTURE_SIZE 80
#define TETROMINO_MATRIX_SIZE 16

class Grid
{
private:
	sf::Texture m_tetrominoTex[5];
	std::vector<std::vector<int>> m_grid;
	sf::RectangleShape m_rectangle;
	sf::Sprite m_playerTetromino;
	sf::Texture m_texture;
	sf::Vector2i m_gridSize;
	int m_copyMatrix[TETROMINO_MATRIX_SIZE][TETROMINO_MATRIX_SIZE];
	int m_playerGravity;
	int m_currentTex;
	int TX;


public:

	Grid();

	void loadTetriminoTextures();

	void run();

	void gridSize(const int& sizeX, const int& sizeY);

	void gravity();

	void playerGravity();

	void drawGrid(sf::RenderWindow& window);

	void rotationUpdate();

	void tetriminoOrientationUpdate();

	void printTetrimino(const int& cellX, const int& cellY);

	void spawnTetromino();

	bool tetminoCollisionUpdate();

	void moveTetromnio(const int& axisX, const int& axisY);

	bool swap(int Y, int X,const int Xaxis,const int Yaxis);

	void softAndHardDrop();

	void rectangleBoundsFix();
	
 };