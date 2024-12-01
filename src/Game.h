#ifndef GAME_H
#define GAME_H
#include "GameState.h"
#include "StartState.h"
#include "GetTeamsState.h"
#include "SFML/Graphics.hpp"
#include <string>
#include <array>

class Game {
public:
    Game();
    ~Game();

    void run();
    void setText(sf::Text& text);

    sf::Font& getFont();
    
    unsigned getWindowWidth() const;
    unsigned getWindowHeight() const;

    void changeGameState(GameState::State gameState);

private:
    sf::RenderWindow m_window;
    GameState* m_currentState;
    std::array<GameState*, GameState::State::COUNT> m_gameStates;
    sf::Font m_font;
    void loadFont(sf::Font& font);

    int numberOfTeams; //TODO remove
};

#endif //GAME_H