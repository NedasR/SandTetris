#include "Gird.hpp"

Grid::Grid()
{
	m_playerTetromino.setOrigin(40, 40);
	m_playerTetromino.setScale(0.065 * TETROMINO_MATRIX_SIZE, 0.065 * TETROMINO_MATRIX_SIZE);
	m_playerTetromino.setTextureRect(sf::IntRect(0, 0, 80, 80));
	loadTetriminoTextures();
	loadTetriminoColors();
	int gridOffsetX = GRID_OFFSET_X;
	int sandSize = SAND_SIZE;
	m_playerGravity = 0;
	m_rectangle.setSize(sf::Vector2f(sandSize, sandSize));
	gridSize(80, 161);
	for (int Y = 0; Y < m_gridSize.y; Y++)
	{
		for (int X = 0; X < m_gridSize.x; X++)
		{
			m_grid[Y][X] = 0;
			if (X == 20 && Y >= 20)
			{
					m_grid[Y][X] = 1;
			}
		}
	}
}

void Grid::loadTetriminoTextures()
{
	
	if (!(m_tetrominoTex[1].loadFromFile("assets/Ltetromino.png")     &&
		  m_tetrominoTex[2].loadFromFile("assets/Skewtetromino.png")  &&
		  m_tetrominoTex[3].loadFromFile("assets/Squaretetromin.png") &&
		  m_tetrominoTex[4].loadFromFile("assets/Stetromino.png")     &&
		  m_tetrominoTex[5].loadFromFile("assets/Ttetromino.png")))
		{
		std::cout << "TetriminoTextures failed to load one or all";
		}
}

void Grid::loadTetriminoColors()
{
	m_tetrominoColor[1] = sf::Color(245, 17, 55);
	m_tetrominoColor[2] = sf::Color(62, 123, 222);
	m_tetrominoColor[3] = sf::Color(212, 30, 163);
	m_tetrominoColor[4] = sf::Color(20, 168, 25);
	m_tetrominoColor[5] = sf::Color(226, 245, 61);
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

void Grid::gravity()
{
	for (int Y = m_gridSize.y; Y > 0; Y--)
	{

		for (int X = 0; X < m_gridSize.x; X++)
		{
			if (!(swap(Y, X, 1, 0)))
			{
				switch (std::rand() % 2)
				{
					//movment to the left
				case (0):
					{
					// if it cannot move to the left it will check the right
					if (swap(Y, X, 1, -1))
					{
						swap(Y, X, 1, 1);
					}

					break;
					}
					//movment to the right
				case (1):
					{
					// if it cannot move to the right it will check the left
					if (swap(Y, X, 1, 1))
					{
						swap(Y, X, 1, -1);
					}
					break;
					}
					
				}
			}
		}
	}
}

void Grid::playerGravity()
{
	if (m_playerGravity == 0)
	{
		m_playerGravity = m_playerTetromino.getPosition().y / SAND_SIZE;
	}
	m_playerTetromino.setPosition(m_playerTetromino.getPosition().x, m_playerGravity * SAND_SIZE);
	m_playerGravity++;
	if (m_playerGravity >= m_gridSize.y)
	{
		m_playerGravity = 1;
		randomTetromino();
		std::cout << "random runs";
	}

}

void Grid::drawGrid(sf::RenderWindow& window)
{
	for (float Y = 0; Y < m_gridSize.y; Y++)
	{
		for (float X = 0; X < m_gridSize.x; X++)
		{
			if (m_grid[Y][X] != 0)
			{
				if (m_grid[Y][X] == 1)
				{
					m_rectangle.setFillColor(m_tetrominoColor[1]);
					m_rectangle.setPosition(sf::Vector2f((X * SAND_SIZE)+200,Y * SAND_SIZE));
				}
				if (m_grid[Y][X] == 2)
				{
					m_rectangle.setFillColor(m_tetrominoColor[2]);
					m_rectangle.setPosition(sf::Vector2f((X * SAND_SIZE) + 200, Y * SAND_SIZE));
				}
				if (m_grid[Y][X] == 3)
				{
					m_rectangle.setFillColor(m_tetrominoColor[3]);
					m_rectangle.setPosition(sf::Vector2f((X * SAND_SIZE) + 200, Y * SAND_SIZE));
				}
				if (m_grid[Y][X] == 4)
				{
					m_rectangle.setFillColor(m_tetrominoColor[4]);
					m_rectangle.setPosition(sf::Vector2f((X * SAND_SIZE) + 200, Y * SAND_SIZE));
				}
				if (m_grid[Y][X] == 5)
				{
					m_rectangle.setFillColor(m_tetrominoColor[5]);
					m_rectangle.setPosition(sf::Vector2f((X * SAND_SIZE) + 200, Y * SAND_SIZE));
				}

				window.draw(m_rectangle);
			}
		}
	}
	window.draw(m_playerTetromino);
}

void Grid::spawnTetromino(const int& tetrminoType, const int& tetrmnioColor)
{
	TX = 0;
	m_playerTetromino.setRotation(0);
	m_playerTetromino.setTexture(m_tetrominoTex[tetrminoType]);
	m_currentTex = tetrminoType;
	m_playerTetromino.setColor(m_tetrominoColor[tetrmnioColor]);
	m_playerTetromino.setPosition(sf::Vector2f(400, 30));
	sf::Image shapeMatrix = m_tetrominoTex[m_currentTex].copyToImage();
	wipeCopyMatrix();
	for (int Y = 0; Y < TETROMINO_MATRIX_SIZE; Y++)
	{
		for (int X = 0; X < TETROMINO_MATRIX_SIZE; X++)
		{
			sf::Color pixcolor = shapeMatrix.getPixel(80 / TETROMINO_MATRIX_SIZE * X, 80 / TETROMINO_MATRIX_SIZE * Y);
			if (static_cast<int>(pixcolor.b) > 0)
			{
				m_copyMatrix[Y][X] = tetrmnioColor;
				continue;
			}
			m_copyMatrix[Y][X] = 0;
		}
		std::cout << std::endl;
	}

	/*
	for (int Y = 0; Y < 16; Y++)
	{
		for (int X = 0; X < 16; X++)
		{
			std::cout << m_copyMatrix[Y][X] << " ";
		}
		std::cout << std::endl;
	}
	*/
}

void Grid::rotationUpdate()
{
	TX++;
	m_playerTetromino.setRotation(90 * TX);
	tetriminoOrientationUpdate();
	rectangleBoundsFix();
	if (TX == 4)
	{
		TX = 0;
	}
}

void Grid::tetriminoOrientationUpdate()
{
	// this updates how the roatation of the player tetrimino is current orientation into a matrix that is used for collision detection
	for (int layer = 0; layer < TETROMINO_MATRIX_SIZE / 2;layer++)
	{
		
		int first = layer;
		int last = TETROMINO_MATRIX_SIZE - first - 1;
		for (int i = first; i < last; i++)
		{
			int offset = i - first;
			int top = m_copyMatrix[first][i];
			m_copyMatrix[first][i] = m_copyMatrix[last - offset][first];
			m_copyMatrix[last - offset][first] = m_copyMatrix[last][last - offset];
			m_copyMatrix[last][last - offset] = m_copyMatrix[i][last];
			m_copyMatrix[i][last] = top;
		}
	}
	/*
	for (int Y = 0; Y < 4; Y++)
	{
		for (int X = 0; X < 4; X++)
		{
			std::cout << m_copyMatrix[Y][X] << " ";
		}
		std::cout << std::endl;
	}
	*/
}

void Grid::printTetrimino(const int& cellY, const int& cellX)
{
	for (int y = 0; y < TETROMINO_MATRIX_SIZE; y++)
	{
		for (int x = 0; x < TETROMINO_MATRIX_SIZE; x++)
		{
			if (x + cellX - TETROMINO_MATRIX_SIZE / 2 < 0 || x + cellX - (TETROMINO_MATRIX_SIZE / 2) > m_gridSize.x)
			{
				continue;
			}
			if (m_grid[y + cellY][x + cellX - TETROMINO_MATRIX_SIZE / 2] == 0)
			{
				if (!(x + cellX - TETROMINO_MATRIX_SIZE / 2 < 0))
				{
					if (!(x + cellX - TETROMINO_MATRIX_SIZE / 2 > m_gridSize.x))
					{
						m_grid[y + cellY][x + cellX - TETROMINO_MATRIX_SIZE / 2] = m_copyMatrix[y][x];
					}
				}
			}
		}
	}
}

bool Grid::tetminoCollisionUpdate()
{

	sf::Vector2f savedOrigin(m_playerTetromino.getOrigin());
	m_playerTetromino.setOrigin(sf::Vector2f(0, 0));
	int cellY = m_playerTetromino.getPosition().y / SAND_SIZE;
	int cellX = (m_playerTetromino.getPosition().x - GRID_OFFSET_X) / SAND_SIZE;
	for (int i = 0; i < TETROMINO_MATRIX_SIZE; i++)
	{
			if (cellY + TETROMINO_MATRIX_SIZE > m_gridSize.y || cellX + i > m_gridSize.x)
			{
				continue;
			}
			if (m_grid[cellY + TETROMINO_MATRIX_SIZE][cellX + i] != 0 || cellY + TETROMINO_MATRIX_SIZE >= m_gridSize.y-2)
			{
				printTetrimino(cellY, cellX);
				m_playerGravity = 1;
				randomTetromino();
				m_playerTetromino.setOrigin(savedOrigin);
				
				return true;
			}
	}
	m_playerTetromino.setOrigin(savedOrigin);
	return false;
}

void Grid::moveTetromnio(const int& axisX, const int& axisY, sf::RectangleShape& collider)
{
	sf::Vector2f player = m_playerTetromino.getPosition();
	int count = 0;
	//right wall offset calculations
	if (axisX > 0)
	{
		for (int i = TETROMINO_MATRIX_SIZE / 2; i < TETROMINO_MATRIX_SIZE; i++)
		{
			if (m_copyMatrix[7][i] != 0 || m_copyMatrix[9][i] != 0)
			{
				count++;
			}
		}
		if (!(collider.getGlobalBounds().contains(m_playerTetromino.getPosition().x + count * SAND_SIZE, m_playerTetromino.getPosition().y)))
		{
			m_playerTetromino.setPosition(player.x + (axisX * SAND_SIZE), player.y + (axisY * SAND_SIZE));
		}
		else if (collider.getGlobalBounds().contains(m_playerTetromino.getPosition().x + count * SAND_SIZE, m_playerTetromino.getPosition().y))
		{
			m_playerTetromino.setPosition(player.x - SAND_SIZE, player.y);
		}
	}

	//left wall offset calculations
	if (axisX < 0)
	{
		for (int i = TETROMINO_MATRIX_SIZE / 2; i > 0; i--)
		{
			if (m_copyMatrix[7][i] != 0 || m_copyMatrix[9][i] != 0)
			{
				count++;
			}
		}
		if (!(collider.getGlobalBounds().contains(m_playerTetromino.getPosition().x - count * SAND_SIZE, m_playerTetromino.getPosition().y)))
		{
			m_playerTetromino.setPosition(player.x + (axisX * SAND_SIZE), player.y + (axisY * SAND_SIZE));
		}
		else if (collider.getGlobalBounds().contains(m_playerTetromino.getPosition().x - count * SAND_SIZE, m_playerTetromino.getPosition().y))
		{
			m_playerTetromino.setPosition(player.x + SAND_SIZE+5, player.y);
		}
	}
}

bool Grid::swap(int Y,int X,const int axisY, const int axisX)
{
	if (!(Y >= m_gridSize.y ||
		Y < 0 ||
		X >= m_gridSize.x ||
		X < 0))
	{
		if (!(Y + axisY >= m_gridSize.y ||
			Y + axisY < 0 ||
			X - axisX >= m_gridSize.x ||
			X - axisX < 0))
		{
			
			if (m_grid[Y + axisY][X - axisX] == 0)
			{
				int temp = m_grid[Y + axisY][X - axisX];
				m_grid[Y + axisY][X - axisX] = m_grid[Y][X];
				m_grid[Y][X] = temp;
				return true;
			}
			return false;
		}
	}
	return false;
}

void Grid::softAndHardDrop()
{
	m_playerGravity++;
}

void Grid::rectangleBoundsFix()
{

	
	int mGridX = (m_playerTetromino.getPosition().x - GRID_OFFSET_X) / SAND_SIZE;
	int counter = 0;;
	for (int x = 0; x < TETROMINO_MATRIX_SIZE / 2; x++)
	{
		if (m_copyMatrix[(TETROMINO_MATRIX_SIZE / 2) - 1][(TETROMINO_MATRIX_SIZE / 2 + x)]  &&  mGridX + x+1 > m_gridSize.x)
		{
			counter++;
		}
		if (m_copyMatrix[(TETROMINO_MATRIX_SIZE / 2)][(TETROMINO_MATRIX_SIZE / 2 + x)] && mGridX + x + 1 > m_gridSize.x)
		{
			counter++;
		}
	}
	m_playerTetromino.setPosition(m_playerTetromino.getPosition().x - (counter * SAND_SIZE), m_playerTetromino.getPosition().y);
	counter = 0;

	for (int x = TETROMINO_MATRIX_SIZE / 2; x >= 0; x--)
	{
		if (m_copyMatrix[(TETROMINO_MATRIX_SIZE / 2)][x-1]  && mGridX - x < 0)
		{
			counter++;
		}
		if (m_copyMatrix[(TETROMINO_MATRIX_SIZE / 2)-1][x - 1]  && mGridX - x < 0)
		{
			counter++;
		}
	}
	m_playerTetromino.setPosition(m_playerTetromino.getPosition().x + (counter * SAND_SIZE), m_playerTetromino.getPosition().y);
}

void Grid::randomTetromino()
{
	spawnTetromino(std::rand() % 5 +1, std::rand() % 5+1);
	/*
	switch (std::rand() % 5)
	{
		case (0) :
		{
			spawnTetromino(0, 2);
		}
		case (1):
		{
			spawnTetromino(1, 2);
		}
		case (2):
		{
			spawnTetromino(2, 2);
		}
		case (3):
		{
			spawnTetromino(3, 2);
		}
		case (4):
		{
			spawnTetromino(4, 2);
		}
	}
	*/
}

void Grid::wipeCopyMatrix()
{
	for (int Y = 0; Y < TETROMINO_MATRIX_SIZE; Y++)
	{
		for (int X = 0; X < TETROMINO_MATRIX_SIZE; X++)
		{
			m_copyMatrix[Y][X] = 0;
		}
	}
}