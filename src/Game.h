#ifndef GAME_H
#define GAME_H
#include "GameState.h"
#include "StartState.h"
#include "SFML/Graphics.hpp"
#include <string>
#include <array>


enum Status {
    TEAMS_NUMBER_ENTERED,
    WORDS_ENTERED,
    NO_INPUT
};

class Game {
public:
    Game();
    ~Game();

    void run();
    void setText(sf::Text& text);

    sf::Font& getFont();
    sf::Text& getPrompt();
    sf::Text& getInputText();

    void changeGameState(GameState::State gameState);

private:
    sf::RenderWindow m_window;
    GameState* m_currentState;
    std::array<GameState*, GameState::State::COUNT> m_gameStates;
    sf::Font m_font;
    sf::Text m_msg, m_input;
    enum Status m_status;
    std::string input_msg;

    int numberOfTeams;

    void loadFont(sf::Font& font);
    void getMsg();

    void create_intro(sf::Event& event);
};

#endif //GAME_H