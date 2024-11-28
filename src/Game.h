#ifndef GAME_H
#define GAME_H
#include "SFML/Graphics.hpp"

class Game {
public:
    Game();

    void run();

private:
    sf::RenderWindow m_window;

};

#endif