#ifndef GAME_H
#define GAME_H
#include "SFML/Graphics.hpp"

enum Status {
    TEAMS_NUMBER_ENTERED,
    WORDS_ENTERED,
    NO_INPUT
};

class Game {
public:
    Game();

    void run();
    void setText();

private:
    sf::RenderWindow m_window;
    sf::Font m_font;
    sf::Text m_msg;
    enum Status m_status;
    void loadFont(sf::Font& font);
    void getMsg();
};

#endif