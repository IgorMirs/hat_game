#ifndef GETWORDSSTATE_H
#define GETWORDSSTATE_H

#include "GameState.h"

#define WORDSNUMBER 3
class GetWordsState : public GameState {
public:
    GetWordsState(Game* game);

    void handle_input(const sf::Event& event);
    void update(sf::Time delta);
    void draw(sf::RenderWindow& window);
    
private:
    sf::Text getWords_prompt;
    sf::Text getWords_input;
    std::string input_msg;
    int playerNumber;
    int teamNumber;
    int wordNumber;

    std::string createPrompt(int tn, int pn, int wn);
};

#endif