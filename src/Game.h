#ifndef GAME_H
#define GAME_H
#include "SFML/Graphics.hpp"
#include <string>

enum Status {
    TEAMS_NUMBER_ENTERED,
    WORDS_ENTERED,
    NO_INPUT
};

class Game {
public:
    Game();

    void run();
    void setText(sf::Text& text);

private:
    sf::RenderWindow m_window;
    sf::Font m_font;
    sf::Text m_msg, m_input;
    enum Status m_status;
    std::string input_msg;

    int numberOfTeams;

    void loadFont(sf::Font& font);
    void getMsg();
};

#endif