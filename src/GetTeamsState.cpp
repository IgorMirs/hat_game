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
    getTeams_input.setPosition(40, 55);
    getTeams_prompt.setString("Enter the number of teams\n> ");
    getTeamPlayers_prompt.setString("");
    getTeamPlayers_prompt.setPosition(0, 110);
    getTeamPlayers_input.setString("");
    getTeamPlayers_input.setPosition(40, 165);
    getTeams_input.setString("");
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
    if (event.text.unicode > '1' && event.text.unicode <= '9') {
        input_msg.clear();
        input_msg += event.text.unicode;
        getTeams_input.setString(input_msg);
    }
    else if (!getTeams_input.getString().isEmpty() && event.text.unicode == '\n') { //number of teams is entered
        //input_msg = getTeams_input.getString(); //TODO 
        // numberOfTeams = std::stoi(input_msg);
        getTeamPlayers_prompt.setString("How many players will be on each team?\n> ");
        
        input_msg.clear();
        nTeamsEntered = true;
    }
}

void GetTeamsState::get_nPlayers(const sf::Event& event) {
    if (event.text.unicode > '1' && event.text.unicode <= '9') {
        input_msg.clear();
        input_msg += event.text.unicode;
        getTeamPlayers_input.setString(input_msg);
    }
    else if (!getTeams_input.getString().isEmpty() && event.text.unicode == '\n') { //number of teams is entered
        //input_msg = getTeams_input.getString(); //TODO 
        // numberOfTeams = std::stoi(input_msg);
        getGame()->changeGameState(GameState::GET_WORDS);   
    }
    
    
    // if (event.text.unicode == '\n') {
    //     input_msg.clear();
    //     getTeams_input.setString(input_msg);
    // }
    // else {
    //     input_msg += event.text.unicode;
    //     getTeams_input.setString(input_msg);
    // }
}
