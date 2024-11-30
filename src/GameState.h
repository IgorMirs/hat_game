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

    virtual void handle_input() = 0;
    virtual void update(sf::Time delta) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;

private:
    Game* m_game;
};







class GetTeams : public GameState {
public:
    GetTeams(Game* game);

    void handle_input();
    void update(sf::Time delta);
    void draw(sf::RenderWindow& window);
};




#endif