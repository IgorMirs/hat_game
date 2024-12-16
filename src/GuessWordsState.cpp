#include "GuessWordsState.h"
#include "Game.h"
#include <iostream>
#include <string>

GuessWordsState::GuessWordsState(Game* game) : 
GameState(game),
roundTime(2),
roundStart(true),
playBeep(true),
currentTeam(1)
{
    configureText(wordToGuess);
    configureText(clockText);
    wordToGuess.setCharacterSize(100);
    if (!clockBuffer.loadFromFile("/Users/igor_air/Documents/coding/01_hat_game/sound/beep.mp3") 
                                    || !endClockBuffer.loadFromFile("/Users/igor_air/Documents/coding/01_hat_game/sound/end_beep.mp3")) 
    {
        throw std::runtime_error("ERROR loading sound!");
        exit(EXIT_FAILURE);
    }
    clockBeep.setBuffer(clockBuffer);
}

void GuessWordsState::handle_input(const sf::Event& event) {
    if (event.text.unicode == ' ') {
        getGame()->markGuessedWord();
        getGame()->addScore(currentTeam);
        if (getGame()->isAllWordsGuessed()) {
            getGame()->setGameRound(getGame()->getGameRound() + 1);
            getGame()->markAllWordsNotGuessed();
            getGame()->changeGameState(State::SHOW_SCORE);
        }
        else {
            wordToGuess.setString(getGame()->pickWord());
        }
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
        currentTeam = (currentTeam) % (getGame()->getNumberOfTeams()) + 1;
        getGame()->changeGameState(GameState::SHOW_SCORE);
    }
    else if (seconds < 6) {
        clockText.setFillColor(sf::Color::Red);
        if (playBeep) {
            clockBeep.play();
        }
    }
    clockText.setString(std::to_string(seconds));
    centerTextVertically(wordToGuess);
    centerTextHorizontally(wordToGuess);
    clockText.setPosition(getGame()->getWindowWidth() - clockText.getGlobalBounds().width - 15, clockText.getLocalBounds().top);
}
    
void GuessWordsState::draw(sf::RenderWindow& window) {
    window.draw(wordToGuess);
    window.draw(clockText);
}
