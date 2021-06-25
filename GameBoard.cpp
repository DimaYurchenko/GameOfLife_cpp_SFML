#include <stdlib.h>
#include <set>
#include <utility>
#include <vector>
#include <time.h>

#include "GameBoard.h"

GameBoard::GameBoard(int height, int width)
{
    setHeight(height);
    setWidth(width);
    boardState = std::vector<std::vector<sf::RectangleShape>>(int(getHeight()/10), std::vector<sf::RectangleShape>(int(getWidth()/10), sf::RectangleShape(sf::Vector2f(11, 11))));
    for (int i = 0; i < height / 10; i++)
    {
        for (int j = 0; j < width / 10; j++)
        {
            boardState[i][j].setFillColor(sf::Color(120, 120, 120));
            boardState[i][j].setOutlineThickness(-1.f);
            boardState[i][j].setOutlineColor(sf::Color::Black);
            boardState[i][j].setPosition(j * 10, i * 10);
        }
    }
}

void GameBoard::click(int x, int y)
{
    auto hold = alive.find({x / 10, y / 10});
    if(hold != alive.end()){
        alive.erase(hold);
    }else{
        alive.insert({x / 10, y / 10});
    }
}

void GameBoard::fillRandomly() {
    srand(time(NULL));
    for (int i = 0; i < (height*width)/300; ++i) {
        int x = rand() % (height/10);
        int y = rand() % (width/10);

        alive.insert({x,y});
    }
}

void GameBoard::reset()
{
    alive.clear();
}

void GameBoard::iterate()
{
    int neighbors;
    std::vector<std::pair<int, int>> n;
    std::set<std::pair<int, int>> temp;

    for (auto i : alive)
    {
        neighbors = 0;
        for (int x = -1; x <= 1; x++)
        {
            for (int y = -1; y <= 1; y++)
            {
                if ((x != 0 || y != 0) && alive.find({i.first + x, i.second + y}) != alive.end())
                    neighbors++;
                else if (x != 0 || y != 0)
                    n.push_back({i.first + x, i.second + y});
            }
        }
        if (neighbors == 2 || neighbors == 3)
            temp.insert(i);
    }

    for (auto i : n)
    {
        neighbors = 0;
        for (int x = -1; x <= 1; x++)
        {
            for (int y = -1; y <= 1; y++)
            {
                if ((x != 0 || y != 0) && alive.find({i.first + x, i.second + y}) != alive.end())
                    neighbors++;
            }
        }
        if (neighbors == 3)
        {
            temp.insert(i);
        }
    }
    alive = temp;
}

void GameBoard::draw(sf::RenderWindow *window)
{
    for (auto i : boardState)
    {
        for (auto j : i)
        {
            (*window).draw(j);
        }
    }
    for (auto i : alive)
    {
        sf::CircleShape temp(5.5);
        temp.setPosition(i.second * 10, i.first * 10);
        temp.setFillColor(sf::Color(255, 0, 0));
        temp.setOutlineThickness(-1.f);
        temp.setOutlineColor(sf::Color::Black);
        (*window).draw(temp);
    }
}

int GameBoard::getHeight() {
    return height;
}

void GameBoard::setHeight(int height) {
    GameBoard::height = height;
}

int GameBoard::getWidth() {
    return width;
}

void GameBoard::setWidth(int width) {
    GameBoard::width = width;
}
