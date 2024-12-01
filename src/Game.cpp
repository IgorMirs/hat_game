#include "Game.h"
#include <iostream>
#include <exception>

Game::Game() :  m_window({1920u, 1080u}, "Hat Game"), numberOfTeams(0) 
{
    m_window.setFramerateLimit(144);
    loadFont(m_font);
    //init game states
    m_gameStates[GameState::State::START] = new StartState(this); 
    m_gameStates[GameState::State::GET_TEAMS] = new GetTeamsState(this); 

    changeGameState(GameState::START);
}

Game::~Game() {
    GameState* to_del = m_gameStates[GameState::State::GET_TEAMS];
    delete to_del;
}

//****** Getters and Setters ******/

sf::Font& Game::getFont() {
    return m_font;
}


void Game::run() {
    while (m_window.isOpen())
    {
        for (auto event = sf::Event(); m_window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                m_window.close();
            }
            if (event.type == sf::Event::TextEntered || event.type == sf::Event::KeyPressed) {
                m_currentState->handle_input(event);
            }
        }
        m_currentState->update(sf::seconds(1));
        m_window.clear();
        m_currentState->draw(m_window);
        m_window.display();
    }
}

void Game::setText(sf::Text& text) {
    text.setCharacterSize(50);
    text.setFont(m_font);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
}

void Game::loadFont(sf::Font& font) {
    if (!font.loadFromFile("/Users/igor_air/Documents/coding/01_hat_game/fonts/arial.ttf")) {
        throw std::runtime_error("ERROR loading font!");
        exit(EXIT_FAILURE);
    }
}

void Game::changeGameState(GameState::State gameState) {
    m_currentState = m_gameStates[gameState];
}


unsigned Game::getWindowWidth() const {
    sf::Vector2u v = m_window.getSize();
    return v.x;
}

unsigned Game::getWindowHeight() const {
    sf::Vector2u v = m_window.getSize();
    return v.y;
}