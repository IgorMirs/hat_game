#ifndef GETWORDSSTATE_H
#define GETWORDSSTATE_H

#include "GameState.h"

class GetWordsState : public GameState {
public:
    GetWordsState(Game* game);

    void handle_input(const sf::Event& event);
    void update(sf::Time delta);
    void draw(sf::RenderWindow& window);
    
private:
    sf::Text start_prompt;
};

#endif