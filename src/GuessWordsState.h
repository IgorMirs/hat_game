#ifndef GUESSWORDSSTATE_H
#define GUESSWORDSSTATE_H

#include "GameState.h"
#include <SFML/Audio.hpp>

class GuessWordsState : public GameState {
public:
    GuessWordsState(Game* game);

    void handle_input(const sf::Event& event);
    void update(sf::Time delta);
    void draw(sf::RenderWindow& window);
    
private:
    sf::Text wordToGuess;
    sf::Clock clock;
    sf::Text clockText;
    uint roundTime;
    bool roundStart;
    bool playBeep;
    sf::SoundBuffer clockBuffer, endClockBuffer;
    sf::Sound clockBeep;
};

#endif