#include <SFML/Graphics.hpp>
#include<iostream>
#include "Gird.hpp"
int main()
{
    
    sf::RenderWindow window(sf::VideoMode(800, 800), "coffie's game");
    sf::RectangleShape sideWallOne(sf::Vector2f(20, 800));
    sideWallOne.setFillColor(sf::Color(66, 65, 62));
    sf::RectangleShape sideWallTwo(sf::Vector2f(20, 800));
    sideWallTwo.setFillColor(sf::Color(66, 65, 62));
    window.setFramerateLimit(60);
    Grid game;
    game.spawnTetromino(4,2);
    game.makeClickablePauseButton(sf::Vector2f(120, 60), sf::Vector2f(595 + ((205 + sideWallTwo.getSize().x - 120) / 2), 600));
    game.makeClickableQuitButton(sf::Vector2f(120, 60), sf::Vector2f(595 + ((205 + sideWallTwo.getSize().x - 120) / 2), 680));
    game.loadBestScore();
    sf::Clock clock;
    sf::Clock clock2;
    std::srand(static_cast<unsigned int>(std::time(0)));
    sf::Event event;
    sf::Clock keybordspeed;
    while (window.isOpen())
    {

        while (window.pollEvent(event))
        {
            if (event.type == event.Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.key.code == sf::Mouse::Left)
                {
                    game.clickButton(sf::Vector2f(sf::Mouse::getPosition(window)));

                    game.clickQuitButton(sf::Vector2f(sf::Mouse::getPosition(window)), window);
                }
            }


            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::R)
                {
                    game.rotationUpdate();
                }
                if (event.key.code == sf::Keyboard::P)
                {
                    game.pauseButton();
                }
            }
            
        }

        if (keybordspeed.getElapsedTime() >= sf::milliseconds(24))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                game.moveTetromnio(-1, 0, sideWallTwo);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                game.moveTetromnio(1, 0, sideWallOne);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                // moves one cell down if pressed and if held dose hard drop
                game.softAndHardDrop();
            }
            keybordspeed.restart();
        }

        if (clock.getElapsedTime() >= sf::milliseconds(30))
        {
            game.tetminoCollisionUpdate();
            game.gravity();
            game.playerGravity();
            clock.restart();
        }
        
        if (clock2.getElapsedTime() >= sf::milliseconds(240))
        {
            game.connectionDetection();
            clock2.restart();
        }
        game.eliminateConnectedCells();
        game.scoreUpdate();
        game.bestScoreUpdate();

        window.clear();
        game.drawGrid(window);
        sideWallTwo.setPosition(200 - sideWallTwo.getSize().x, 0);
        window.draw(sideWallTwo);
        sideWallOne.setPosition(200 + 400-5, 0);
        window.draw(sideWallOne);
        window.display();
    }

    return 0;
}

/*
TO DO LIST
--make a grid that is made up of default cells that are blank
--make a type for the cless one of them the default ones will be blank
--in the cell make two varibales that have the row/x and and collum/y
--and a class fr what coolor the the shapes are and the cell
--make a gravity method in gird class so all the cells go down and drop to the sides like sand
--have diffrent shaped sand shapes for tetris like game and randomized the coolor and what shape spawns
make the shapes rotatable and make it so we can move right and left with it untill it hits other sand
*/