#include "StartState.h"
#include "Game.h"
#include <iostream>

StartState::StartState(Game* game) : GameState(game) 
{
    configureText(start_prompt); //set text parameters
    start_prompt.setString("PRESS SPACE TO START THE GAME");
    start_prompt.setOrigin(start_prompt.getGlobalBounds().getSize() / 2.f + start_prompt.getLocalBounds().getPosition());
    start_prompt.setPosition(game->getWindowWidth() / 2.f, game->getWindowHeight() / 2.f);
    displayText = true;
}

void StartState::handle_input(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
        getGame()->changeGameState(GameState::GET_TEAMS);
    }
}
     
void StartState::update(sf::Time delta) {
    static sf::Time timeBuffer = sf::Time::Zero; 
    timeBuffer += delta;

    if ((int) timeBuffer.asSeconds() % 100 == 0) {
        displayText = !displayText;
    }
}
    
void StartState::draw(sf::RenderWindow& window) {
    if (displayText == false) {
        window.draw(start_prompt);
    }
}