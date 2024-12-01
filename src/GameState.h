#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "SFML/Graphics.hpp"

class Game;

class GameState {
public:
    GameState(Game* game);
    virtual ~GameState();
    Game* getGame() const;
    
    enum State {
        START,
        GET_TEAMS,
        COUNT
    };

    void configureText(sf::Text& text);

    virtual void handle_input(const sf::Event& event) = 0;
    virtual void update(sf::Time delta) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;

private:
    Game* m_game;
};


#endif