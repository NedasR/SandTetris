#include <SFML/Graphics.hpp>
#include<iostream>
int main()
{
    
    sf::RenderWindow window(sf::VideoMode(800, 800), "coffie's game");
    window.setFramerateLimit(60);

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
                
            }
            
        }


        window.clear();
        window.display();
    }

    return 0;
}

/*
TO DO LIST
--make a grid that is made up of default cells that are blank
--make a type for the cless one of them the default ones will be blank
--in the cell make two varibales that have the row/x and and collum/y










--make cell movement logic for sand movement in derived cell classes // added this in a diffrent way
and also make gravitiy in other words make the sand go down the grid unless the cell below is occupied
make an enum for diffrent types of colord sand
have diffrent shaped sand shapes for tetris like game and randomized the coolor and what shape spawns
make the shapes rotatable and make it so we can move right and left with it untill it hits other sand
*/