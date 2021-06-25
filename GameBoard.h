#include <vector>
#include <SFML/Graphics.hpp>
#include <set>
#include <unordered_set>
#include <utility>
#include <stdlib.h>
#include <time.h>

#ifndef BOARDGAME_H
#define BOARDGAME_H

class GameBoard
{
private:
    int height;
    int width;
    std::vector<std::vector<sf::RectangleShape>> boardState;
    std::set<std::pair<int, int>> alive;

public:
    GameBoard(int height, int width);
    void click(int x, int y);
    void fillRandomly();
    void iterate();
    void draw(sf::RenderWindow *window);
    void reset();
    int getHeight();
    void setHeight(int height);
    int getWidth();
    void setWidth(int width);
};

#endif
