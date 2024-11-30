#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "SFML/Graphics.hpp"

class Game;

class GameState {
public:
    GameState(Game* game);
    Game* getGame() const;
    enum State {
        GET_TEAMS,
        START
    };

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