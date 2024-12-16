#include "GameState.h"
#include "Game.h"

#include <iostream>

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

void GameState::centerTextHorizontally(sf::Text& text) {
    text.setOrigin(text.getGlobalBounds().width / 2.f, text.getOrigin().y);
    text.setPosition(getGame()->getWindowWidth() / 2.f, text.getPosition().y);
}

void GameState::centerTextVertically(sf::Text& text) {
    text.setOrigin(text.getOrigin().x, text.getGlobalBounds().height / 2.f);
    text.setPosition(text.getPosition().x, getGame()->getWindowHeight() / 2.f);
}
