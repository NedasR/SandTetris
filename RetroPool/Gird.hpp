#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include <queue>
#include <fstream>
#define GRID_OFFSET_X 200
#define SAND_SIZE 5.f
#define TEXTURE_SIZE 80
#define TETROMINO_MATRIX_SIZE 16

class Grid
{
private:
	std::fstream m_gameBestScoreFile;
	sf::Texture m_tetrominoTex[6];
	sf::Color m_tetrominoColor[7];
	sf::Texture m_buttonTex;
	sf::Texture m_quitbButtonTex;
	std::vector<std::vector<int>> m_grid;
	sf::Text m_pausedText;
	sf::Font m_fontForAllTexs;
	bool m_gridVisited[161][80];
	std::vector<sf::Vector2i> m_savedcells;
	std::vector<sf::Vector2i> m_cellsReadyTodie;
	sf::RectangleShape m_rectangle;
	sf::RectangleShape m_pauseButtonRect;
	sf::RectangleShape m_quitButtonRect;
	sf::Sprite m_playerTetromino;
	sf::Texture m_texture;
	sf::Vector2i m_gridSize;
	int m_copyMatrix[TETROMINO_MATRIX_SIZE][TETROMINO_MATRIX_SIZE];
	int m_playerGravity;
	int m_currentTex;
	int TX;
	bool m_erase;
	bool m_eraseOn;
	bool m_pause;
	int m_eliminationIterator;
	sf::Vector2i current;
	sf::Vector2i left;
	sf::Vector2i down;
	sf::Vector2i right;
	sf::Vector2i up;
	std::queue<sf::Vector2i> m_queue;
	int lastColor;
	int currentColor;
	sf::Font PixelLikeFont;
	sf::Text m_scoreText;
	sf::Text m_scoreLetters;
	sf::Text m_bestScoreText;
	int m_scoreCounter;
	int m_currentScore;
	int m_gamesBestScore;
	bool m_updateBestScoreFile;
	
public:
	Grid();

	void loadTetriminoTextures();

	void loadTetriminoColors();

	void gridSize(const int& sizeX, const int& sizeY);

	void gravity();

	void playerGravity();

	void drawGrid(sf::RenderWindow& window);

	void rotationUpdate();

	void tetriminoOrientationUpdate();

	void printTetrimino(const int& cellX, const int& cellY);

	void spawnTetromino(const int& tetrminoType, const int& tetrmnioColor);

	bool tetminoCollisionUpdate();

	void moveTetromnio(const int& axisX, const int& axisY, sf::RectangleShape& collider);

	bool swap(int Y, int X,const int Xaxis,const int Yaxis);

	void softAndHardDrop();

	void rectangleBoundsFix();

	void randomTetromino();

	void wipeCopyMatrix();

	void resetVistedMap();

	void connectionDetection();

	void eraseConnectedCell(bool& eraseOn);
	
	void eliminateConnectedCells();

	void pauseGame();

	void unpauseGame();

	void pauseButton();

	void makeClickablePauseButton(const sf::Vector2f& size, sf::Vector2f pos);

	void makeClickableQuitButton(const sf::Vector2f& size, sf::Vector2f pos);

	void clickButton(const sf::Vector2f& mousePos);

	void clickQuitButton(const sf::Vector2f& mousePos, sf::RenderWindow& window);

	void scoreUpdate();

	void bestScoreUpdate();

	void loadBestScore();
 };