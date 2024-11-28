#include "Game.h"
#include <iostream>

Game::Game() :  m_window({1920u, 1080u}, "Hat Game"), m_status(NO_INPUT), 
                input_msg(""), numberOfTeams(0) 
{
    m_window.setFramerateLimit(144);
    loadFont(m_font);
    m_msg.setString("");
    m_input.setString("");
    setText(m_msg);
    setText(m_input);
    m_input.setPosition(40, 55);
}

void Game::run() {
    while (m_window.isOpen())
    {
        for (auto event = sf::Event(); m_window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                m_window.close();
            }
            else if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode > '1' && event.text.unicode <= '9') {
                    input_msg.clear();
                    input_msg += event.text.unicode;
                    m_input.setString(input_msg);
                }
                else if (event.text.unicode == '\n' && m_status == NO_INPUT) { //number of teams is entered
                    input_msg = m_input.getString();
                    numberOfTeams = std::stoi(input_msg);
                    m_status = TEAMS_NUMBER_ENTERED;
                    std::cout << "Number of teams " << numberOfTeams << std::endl;
                    input_msg.clear();
                }
            }
        }

        m_window.clear();
        getMsg();
        m_window.draw(m_msg);
        m_window.draw(m_input);
        m_window.display();
    }
}

void Game::setText(sf::Text& text) {
    text.setCharacterSize(50);
    text.setFont(m_font);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
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