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
    sf::Text getTeams_prompt, getTeams_input, getTeamPlayers_prompt, getTeamPlayers_input;
    std::string input_msg;
    bool nTeamsEntered;
    void get_nTeams(const sf::Event& event);
    void get_nPlayers(const sf::Event& event);

    void getInput(const sf::Event& event, sf::Text& text);
};


#endif