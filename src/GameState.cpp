#include "GameState.h"
#include "Game.h"

GameState::GameState(Game* game) :
m_game(game)
{

}

GameState::~GameState()
{
}

Game* GameState::getGame() const {
    return m_game;
}

void GameState::configureText(sf::Text& text) {
    text.setCharacterSize(50);
    text.setFont(m_game->getFont());
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
}
