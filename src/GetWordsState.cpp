#include "GetWordsState.h"
#include "Game.h"
#include <iostream>

GetWordsState::GetWordsState(Game* game) : 
GameState(game),
playerNumber(1),
teamNumber(1),
wordNumber(1) 
{
    configureText(getWords_prompt);
    configureText(getWords_input);
    getWords_input.setPosition(40, 165);
    getWords_prompt.setString(createPrompt(teamNumber, playerNumber, wordNumber));
    getWords_input.setString("");
}

void GetWordsState::handle_input(const sf::Event& event) {
    if (event.text.unicode == '\n') {
        input_msg.clear();
        getWords_input.setString(input_msg);
        wordNumber++;
        if (wordNumber > WORDSNUMBER) {
            wordNumber = 1;
            playerNumber++;
        }
        if (playerNumber > getGame()->getNumberOfPlayers()) {
            teamNumber++;
            wordNumber = 1;
            playerNumber = 1;
        }
        if (teamNumber > getGame()->getNumberOfTeams()) {
            getGame()->changeGameState(GameState::START);
        }
        getWords_prompt.setString(createPrompt(teamNumber, playerNumber, wordNumber));
    }
    else {
        input_msg += event.text.unicode;
        getWords_input.setString(input_msg);
    }
}
     
void GetWordsState::update(sf::Time delta) {

}
    
void GetWordsState::draw(sf::RenderWindow& window) {
    window.draw(getWords_prompt);
    window.draw(getWords_input);
}


std::string GetWordsState::createPrompt(int tn, int pn, int wn) {
    std::string s("");
     s += "Team ";
    s += std::to_string(tn);
    s += "\nPlayer ";
    s += std::to_string(pn);
    s += "\nEnter the word ";
    s += std::to_string(wn);
    s += "\n>";

    return s;
}