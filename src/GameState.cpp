#include "GameState.h"

GameState::GameState(Game* game)
    :m_game(game) 
{
}

Game* GameState::getGame() const {
    return m_game;
}

GetTeams::GetTeams(Game* game) : GameState(game) 
{
}

void GetTeams::handle_input() {

}
     
void GetTeams::update(sf::Time delta) {

}
    
void GetTeams::draw(sf::RenderWindow& window) {

}