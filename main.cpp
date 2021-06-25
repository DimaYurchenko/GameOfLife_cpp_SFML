#include <SFML/Graphics.hpp>
#include "GameBoard.h"

int main()
{
    GameBoard board(1000, 1000  );

    sf::RenderWindow window(sf::VideoMode(board.getWidth(), board.getHeight()),
                            "Conway's Game of Life",
                            sf::Style::Titlebar | sf::Style::Close);

    bool running = false;



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            else if (event.type == sf::Event::MouseButtonPressed)
            {
                auto pos = sf::Mouse::getPosition(window);

                board.click(pos.y, pos.x);
            }

            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space) {
                    running = !running;
                }
                else if (event.key.code == sf::Keyboard::BackSpace) {
                    board.reset();
                    running = false;
                }
                else if (event.key.code == sf::Keyboard::Enter) {
                    if (running)
                        running = false;
                    board.reset();
                    board.fillRandomly();
                }
            }
        }

        if (running) {
            board.iterate();
        }

        window.clear();

        board.draw(&window);

        window.display();
    }

    return 0;
}
