#include <SFML/Graphics.hpp>
#include<iostream>
#include "Gird.hpp"
int main()
{
    
    sf::RenderWindow window(sf::VideoMode(800, 800), "coffie's game");
    window.setFramerateLimit(60);
    Grid game;
    game.spawnTetromino();
    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == event.Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::R)
                {
                    game.rotationUpdate();
                }
            }
            
        }
        //game.run();
        if (clock.getElapsedTime() >= sf::milliseconds(120))
        {
            game.gravity();
            clock.restart();
        }
        game.playerGravity();

        window.clear();
        game.drawGrid(window);
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