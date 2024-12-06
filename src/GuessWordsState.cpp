#include "GuessWordsState.h"
#include "Game.h"
#include <iostream>
#include <string>

GuessWordsState::GuessWordsState(Game* game) : 
GameState(game),
roundTime(10),
roundStart(true)
{
    configureText(wordToGuess);
    configureText(clockText);
    clockText.setPosition(350, 50); 
}

void GuessWordsState::handle_input(const sf::Event& event) {
    if (event.text.unicode == ' ') {
        wordToGuess.setString(getGame()->pickWord());
    }
}
     
void GuessWordsState::update(sf::Time delta) { 
    std::cout << "Players " << getGame()->getNumberOfPlayers() << std::endl;
    std::cout << "Teams " << getGame()->getNumberOfTeams() << std::endl;
    if (roundStart) {
        clock.restart();
        roundStart = false;
        wordToGuess.setString(getGame()->pickWord());
    }
    uint seconds = roundTime - clock.getElapsedTime().asSeconds();
    if (seconds == 0) {
        roundStart = true;
        getGame()->changeGameState(GameState::START);
    }
    clockText.setString(std::to_string(seconds));
}
    
void GuessWordsState::draw(sf::RenderWindow& window) {
    window.draw(wordToGuess);
    window.draw(clockText);
}
