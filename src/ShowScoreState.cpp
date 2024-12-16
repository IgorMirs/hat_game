#include "ShowScoreState.h"
#include "Game.h"
#include <iostream>

ShowScoreState::ShowScoreState(Game* game) : 
GameState(game),
gotTeamNames(false),
isScoreUpdated(false)
{
    //set text parameters
    configureText(scoreText); 
    configureText(teamsText); 
    configureText(roundText); 
    configureText(holder);
    holder.setString("                     "); 
    scoreText.setString("");
    teamsText.setString("");
    setRoundText();
    centerTextHorizontally(holder);
    centerTextVertically(holder);
    centerTextHorizontally(roundText);
}

void ShowScoreState::handle_input(const sf::Event& event) {
    if (event.type == sf::Event::TextEntered && 
        event.text.unicode == ' ' &&
        getGame()->getGameRound() <= 3) 
    {
        // TODO track round number and pass to start game 
        isScoreUpdated = false;
        getGame()->changeGameState(GameState::GUESS_WORDS);
    }
}
     
void ShowScoreState::update(sf::Time delta) {
    if (!gotTeamNames) {
        initTeamNames();
        gotTeamNames = true;
        teamsText.setOrigin(teamsText.getGlobalBounds().width / 2.f, teamsText.getGlobalBounds().height / 2.f);
        teamsText.setPosition(holder.getGlobalBounds().left, holder.getGlobalBounds().top);
    }
    if (!isScoreUpdated) {
        scoreText.setString("");
        std::vector<int> scores = getGame()->getScore();
        for (int i = 1; i < scores.size(); i++) {
            scoreText.setString(scoreText.getString() + std::to_string(getGame()->getScore()[i]) + "\n");    
        }
        scoreText.setOrigin(scoreText.getGlobalBounds().width / 2.f, scoreText.getGlobalBounds().height / 2.f);
        scoreText.setPosition(holder.getGlobalBounds().left + holder.getGlobalBounds().width, holder.getGlobalBounds().top);

        isScoreUpdated = true;
    }
    setRoundText();
}
    
void ShowScoreState::draw(sf::RenderWindow& window) {
    window.draw(scoreText);
    window.draw(teamsText);
    window.draw(roundText);
    window.draw(holder);
}

void ShowScoreState::initTeamNames() {
    int nTeams = getGame()->getScore().size();
    for (int i = 1; i < nTeams; i++) {
        teamsText.setString(teamsText.getString() + "Team " + std::to_string(i) + "\n");
    }
}

void ShowScoreState::setRoundText() {
    int round = getGame()->getGameRound();
    if (round <= 3) {
        roundText.setString("Round " + std::to_string(getGame()->getGameRound()));
    }
    else {
        roundText.setString("***END OF GAME***");
    }
    centerTextHorizontally(roundText);
}