#include "GetTeamsState.h"


GetTeamsState::GetTeamsState(Game* game) : GameState(game), input_msg("") 
{
    configureText(getTeams_prompt);
    configureText(getTeams_input);
    getTeams_input.setPosition(40, 55);
    getTeams_prompt.setString("Enter the number of teams\n> ");
}

void GetTeamsState::handle_input(const sf::Event& event) {
    if (event.text.unicode > '1' && event.text.unicode <= '9') {
        input_msg.clear();
        input_msg += event.text.unicode;
        getTeams_input.setString(input_msg);
    }
    else if (!getTeams_input.getString().isEmpty() && event.text.unicode == '\n') { //number of teams is entered
        input_msg = getTeams_input.getString();
        // numberOfTeams = std::stoi(input_msg);
        getTeams_input.setString("");
    }
}
     
void GetTeamsState::update(sf::Time delta) {

}
    
void GetTeamsState::draw(sf::RenderWindow& window) {
    window.draw(getTeams_prompt);
    window.draw(getTeams_input);
}
