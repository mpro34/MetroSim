// metrosim.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "metrosim.hpp"

#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Title");

    sf::Event event;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
    }

    return 0;
 //   Station s1;
 //   Point p1(3.4, 2.5);

 //   p1.PrintLocation();
}