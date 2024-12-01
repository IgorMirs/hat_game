#ifndef GET_TEAMS_STATE_H
#define GET_TEAMS_STATE_H

#include "GameState.h"
#include <string>

class GetTeamsState : public GameState {
public:
    GetTeamsState(Game* game);

    void handle_input(const sf::Event& event);
    void update(sf::Time delta);
    void draw(sf::RenderWindow& window);
private:
    sf::Text getTeams_prompt, getTeams_input;
    std::string input_msg;
};


#endif