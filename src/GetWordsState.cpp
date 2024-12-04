#include "GetWordsState.h"
#include "Game.h"
#include <iostream>

GetWordsState::GetWordsState(Game* game) : 
GameState(game) 
{
    configureText(getWords_prompt);
    configureText(getWords_input);
    getWords_input.setPosition(40, 55);
    getWords_prompt.setString("Enter the word\n> ");
    getWords_input.setString("");
}

void GetWordsState::handle_input(const sf::Event& event) {
    if (event.text.unicode == '\n') {
        input_msg.clear();
        getWords_input.setString(input_msg);
    }
    else {
        input_msg += event.text.unicode;
        getWords_input.setString(input_msg);
    }
}
     
void GetWordsState::update(sf::Time delta) {

}
    
void GetWordsState::draw(sf::RenderWindow& window) {
    window.draw(getWords_prompt);
    window.draw(getWords_input);
}