#include "StartState.h"
#include "Game.h"
#include <iostream>

StartState::StartState(Game* game) : GameState(game) 
{
    configureText(start_prompt);
    start_prompt.setString("START GAME");
    // start_prompt.setCharacterSize(50);
    // start_prompt.setFont(game->getFont());
    // start_prompt.setFillColor(sf::Color::White);
    // start_prompt.setStyle(sf::Text::Bold);
}

void StartState::handle_input() {

}
     
void StartState::update(sf::Time delta) {

}
    
void StartState::draw(sf::RenderWindow& window) {
    window.draw(start_prompt);
}