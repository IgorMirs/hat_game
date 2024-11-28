#include "Game.h"

Game::Game() : m_window({1920u, 1080u}, "Hat Game") {
    m_window.setFramerateLimit(144);
}

void Game::run() {
    while (m_window.isOpen())
    {
        for (auto event = sf::Event(); m_window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                m_window.close();
            }
        }

        m_window.clear();
        m_window.display();
    }
}