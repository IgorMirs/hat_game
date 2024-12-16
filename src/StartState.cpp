#include "StartState.h"
#include "Game.h"
#include <iostream>

StartState::StartState(Game* game) : 
GameState(game)
{
    // Load a sprite to display
    if (!texture.loadFromFile("/Users/igor_air/Documents/coding/01_hat_game/img/hat.jpg")) {
        exit(EXIT_FAILURE);
    }
    sprite.setTexture(texture);
    sprite.setOrigin(sprite.getGlobalBounds().width / 2.f, sprite.getGlobalBounds().top);
    sprite.setPosition(game->getWindowWidth() / 2.f, sprite.getLocalBounds().getPosition().y);
    sprite.setScale(0.2f, 0.2f);

    //set text parameters
    configureText(start_prompt); 
    start_prompt.setString("PRESS SPACE TO START THE GAME");
    centerTextHorizontally(start_prompt);
    centerTextVertically(start_prompt);
    displayText = true;
}

void StartState::handle_input(const sf::Event& event) {
    if (event.type == sf::Event::TextEntered && event.text.unicode == ' ') {
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
    window.draw(sprite);
}