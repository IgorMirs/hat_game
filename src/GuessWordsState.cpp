#include "GuessWordsState.h"
#include "Game.h"
#include <iostream>
#include <string>

GuessWordsState::GuessWordsState(Game* game) : 
GameState(game),
roundTime(10),
roundStart(true),
playBeep(true)
{
    configureText(wordToGuess);
    configureText(clockText);
    wordToGuess.setCharacterSize(100);
    if (!clockBuffer.loadFromFile("/Users/igor_air/Documents/coding/01_hat_game/sound/beep.mp3") || !endClockBuffer.loadFromFile("/Users/igor_air/Documents/coding/01_hat_game/sound/end_beep.mp3")) {
        throw std::runtime_error("ERROR loading sound!");
        exit(EXIT_FAILURE);
    }
    clockBeep.setBuffer(clockBuffer);
}

void GuessWordsState::handle_input(const sf::Event& event) {
    if (event.text.unicode == ' ') {
        wordToGuess.setString(getGame()->pickWord());
    }
}
     
void GuessWordsState::update(sf::Time delta) { 
    static sf::Time timeBuffer = sf::Time::Zero; 
    timeBuffer += delta;

    if ((int) timeBuffer.asSeconds() % 65 == 0) {
        playBeep = !playBeep;
    }
    if (roundStart) {
        clock.restart();
        roundStart = false;
        wordToGuess.setString(getGame()->pickWord());
        clockText.setFillColor(sf::Color::White);
    }
    uint seconds = roundTime - clock.getElapsedTime().asSeconds();
    if (seconds == 0) {
        roundStart = true;
        clockBeep.setBuffer(endClockBuffer);
        clockBeep.play();
        getGame()->changeGameState(GameState::START);
    }
    else if (seconds < 6) {
        clockText.setFillColor(sf::Color::Red);
        if (playBeep) {
            clockBeep.play();
        }
    }
    clockText.setString(std::to_string(seconds));
    wordToGuess.setOrigin(wordToGuess.getGlobalBounds().getSize() / 2.f + wordToGuess.getLocalBounds().getPosition());
    wordToGuess.setPosition(getGame()->getWindowWidth() / 2.f, getGame()->getWindowHeight() / 2.f);
    clockText.setPosition(getGame()->getWindowWidth() - clockText.getGlobalBounds().width - 15, clockText.getLocalBounds().top);
}
    
void GuessWordsState::draw(sf::RenderWindow& window) {
    window.draw(wordToGuess);
    window.draw(clockText);
}
