#include "Game.h"
#include <iostream>

Game::Game() : m_window({1920u, 1080u}, "Hat Game"), m_status(NO_INPUT) {
    m_window.setFramerateLimit(144);
    loadFont(m_font);
}

void Game::run() {
    while (m_window.isOpen())
    {
        for (auto event = sf::Event(); m_window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                m_window.close();
            }
            else if (event.type == sf::Event::KeyPressed) {
                m_status = TEAMS_NUMBER_ENTERED;
            }
        }

        m_window.clear();
        setText();
        getMsg();
        m_window.draw(m_msg);
        m_window.display();
    }
}

void Game::setText() {
    m_msg.setCharacterSize(50);
    m_msg.setFont(m_font);
    m_msg.setFillColor(sf::Color::White);
    m_msg.setStyle(sf::Text::Bold);
}

void Game::getMsg() {
    switch (m_status) {
    case TEAMS_NUMBER_ENTERED:
        m_msg.setString("Enter the word\n> ");
        break;
    case NO_INPUT:
        m_msg.setString("Enter the number of teams\n> ");
        break;
    
    default:
        break;
    }
}

void Game::loadFont(sf::Font& font) {
    if (!font.loadFromFile("/Users/igor_air/Documents/coding/01_hat_game/fonts/arial.ttf")) {
        std::cout << "ERROR loading font!" << std::endl;
        exit(EXIT_FAILURE);
    }
}