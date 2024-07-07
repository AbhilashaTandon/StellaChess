#include <SFML/Graphics.hpp>

#include <limits>
#include <iostream>

#include "BoardDisplay.h"
#include "Board.h"


int main()
{
    /*sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    
    BoardDisplay display;

    display.init_textures();
    display.init_board();


    std::vector<sf::RectangleShape> board = display.get_board();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }


        window.clear();
        for (sf::RectangleShape tile : board) {
            window.draw(tile);

        }
        window.display();
    }*/

    Board x = Board();
    x.print();

    return 0;
}

