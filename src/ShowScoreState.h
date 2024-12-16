#ifndef SHOWSCORESTATE_H
#define SHOWSCORESTATE_H

#include "GameState.h"

class ShowScoreState : public GameState {
public:
    ShowScoreState(Game* game);

    void handle_input(const sf::Event& event);
    void update(sf::Time delta);
    void draw(sf::RenderWindow& window);
    
private:
    sf::Text scoreText, teamsText, roundText, holder;

    bool gotTeamNames;
    bool isScoreUpdated;

    void initTeamNames();
    void setRoundText();
};

#endif