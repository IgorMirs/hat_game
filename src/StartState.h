#ifndef STARTSTATE_H
#define STARTSTATE_H

#include "GameState.h"

class StartState : public GameState {
public:
    StartState(Game* game);

    void handle_input(const sf::Event& event);
    void update(sf::Time delta);
    void draw(sf::RenderWindow& window);
    
private:
    sf::Text start_prompt;
    bool displayText;
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif