#include "GetTeamsState.h"
#include "Game.h"
#include <iostream>

GetTeamsState::GetTeamsState(Game* game) : 
GameState       (game), 
input_msg       (""),
nTeamsEntered   (false) 
{
    configureText(getTeams_prompt);
    configureText(getTeams_input);
    configureText(getTeamPlayers_prompt);
    configureText(getTeamPlayers_input);
    getTeams_prompt.setString("Enter the number of teams\n> ");
    getTeams_input.setPosition(40, 55);
    getTeams_input.setString("");
    getTeamPlayers_prompt.setString("");
    getTeamPlayers_prompt.setPosition(0, 110);
    getTeamPlayers_input.setString("");
    getTeamPlayers_input.setPosition(40, 165);
}

void GetTeamsState::handle_input(const sf::Event& event) {
    if (!nTeamsEntered) {
        get_nTeams(event);
    }
    else {
        get_nPlayers(event);
    }
}
     
void GetTeamsState::update(sf::Time delta) {

}
    
void GetTeamsState::draw(sf::RenderWindow& window) {
    window.draw(getTeams_prompt);
    window.draw(getTeams_input);
    window.draw(getTeamPlayers_prompt);
    window.draw(getTeamPlayers_input);
}

void GetTeamsState::get_nTeams(const sf::Event& event) {
    getInput(event, getTeams_input);
    if (!getTeams_input.getString().isEmpty() && event.text.unicode == '\n') { //number of teams is entered
        input_msg = getTeams_input.getString(); 
        getGame()->setNumberOfTeams(std::stoi(input_msg));
        getTeamPlayers_prompt.setString("How many players will be on each team?\n> ");
        nTeamsEntered = true;
    }
}

void GetTeamsState::get_nPlayers(const sf::Event& event) {
    getInput(event, getTeamPlayers_input);
    if (!getTeamPlayers_input.getString().isEmpty() && event.text.unicode == '\n') { //number of teams is entered
        input_msg = getTeamPlayers_input.getString();
        getGame()->setNumberOfPlayers(std::stoi(input_msg));
        getGame()->changeGameState(GameState::GET_WORDS);   
    }
}


void GetTeamsState::getInput(const sf::Event& event, sf::Text& text) {
    if (event.text.unicode > '1' && event.text.unicode <= '9') {
        input_msg.clear();
        input_msg += event.text.unicode;
        text.setString(input_msg);
    }
}