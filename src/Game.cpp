#include "Game.h"
#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>

////////////////////////////////////////////////////////////
Game::Game() :  
m_window        ({1920u, 1080u}, "Hat Game"),
numberOfPlayers (0),
numberOfTeams   (0),
currentWord(-1),
numberOfGuessedWords(0),
gameRound(1)
{
    srand(time(NULL));
    m_window.setFramerateLimit(144);
    loadFont(m_font);
    //init game states
    m_gameStates[GameState::State::START] = new StartState(this); 
    m_gameStates[GameState::State::GET_TEAMS] = new GetTeamsState(this); 
    m_gameStates[GameState::State::GET_WORDS] = new GetWordsState(this); 
    m_gameStates[GameState::State::GUESS_WORDS] = new GuessWordsState(this); 
    m_gameStates[GameState::State::SHOW_SCORE] = new ShowScoreState(this); 
    changeGameState(GameState::START);
}

////////////////////////////////////////////////////////////
Game::~Game() {
    for(GameState* gs : m_gameStates) {
        delete gs;
    }
}

////////////////////////////////////////////////////////////
sf::Font& Game::getFont() {
    return m_font;
}

////////////////////////////////////////////////////////////
void Game::run() {
    while (m_window.isOpen())
    {
        for (auto event = sf::Event(); m_window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                m_window.close();
            }
            if (event.type == sf::Event::TextEntered ) {
                m_currentState->handle_input(event);
            }
        }
        m_currentState->update(sf::seconds(1));
        m_window.clear();
        m_currentState->draw(m_window);
        m_window.display();
    }
}

////////////////////////////////////////////////////////////
void Game::setText(sf::Text& text) {
    text.setCharacterSize(50);
    text.setFont(m_font);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
}

////////////////////////////////////////////////////////////
void Game::loadFont(sf::Font& font) {
    if (!font.loadFromFile("/Users/igor_air/Documents/coding/01_hat_game/fonts/arial.ttf")) {
        throw std::runtime_error("ERROR loading font!");
        exit(EXIT_FAILURE);
    }
}

////////////////////////////////////////////////////////////
void Game::changeGameState(GameState::State gameState) {
    m_currentState = m_gameStates[gameState];
}

////////////////////////////////////////////////////////////
unsigned Game::getWindowWidth() const {
    sf::Vector2u v = m_window.getSize();
    return v.x;
}

////////////////////////////////////////////////////////////
unsigned Game::getWindowHeight() const {
    sf::Vector2u v = m_window.getSize();
    return v.y;
}

////////////////////////////////////////////////////////////
void Game::setNumberOfPlayers(int np) {
    numberOfPlayers = np;
}

////////////////////////////////////////////////////////////
void Game::setNumberOfTeams(int nt) {
    numberOfTeams = nt;
}

////////////////////////////////////////////////////////////
int Game::getNumberOfPlayers() {
    return numberOfPlayers;
}

////////////////////////////////////////////////////////////
int Game::getNumberOfTeams() {
    return numberOfTeams;
}

////////////////////////////////////////////////////////////
void Game::addWord(const std::string& word) {
    Word w(word);
    words.push_back(w);
}

////////////////////////////////////////////////////////////
void Game::printWords() const {
    for (Word w : words) {
        std::cout << w.getValue() << std::endl;
    }
}

////////////////////////////////////////////////////////////
std::string Game::pickWord() {
    if (words.empty()) {
        return "";
    }
    else {
        int i = rand() % words.size();
        while (words[i].getIsGuessed()) {
            i = rand() % words.size();
        }
        currentWord = i;
        return words[i].getValue();    
    }
}

////////////////////////////////////////////////////////////
void Game::markGuessedWord() {
    if (currentWord >= 0 && currentWord < words.size()) {
        words[currentWord].setIsGuessed(true);
        numberOfGuessedWords++;
    }
}

////////////////////////////////////////////////////////////
bool Game::isAllWordsGuessed() const {
    return (numberOfGuessedWords == words.size());
}

////////////////////////////////////////////////////////////
void Game::markAllWordsNotGuessed() {
    for (int i = 0; i < words.size(); i++) {
        words[i].setIsGuessed(false);
    }
    numberOfGuessedWords = 0;
}

////////////////////////////////////////////////////////////
void Game::initScore(int size) {
    if (size > 0) {
        score.resize(size);
        for (int i = 0; i < size; i++) {
            score[i] = 0;
        }
    }
}

////////////////////////////////////////////////////////////
void Game::addScore(int teamNumber) {
    if (teamNumber < 0 || teamNumber >= score.size()) {
        return;
    }
    score[teamNumber]++;
}

////////////////////////////////////////////////////////////
std::vector<int> Game::getScore() const {
    return score;
}

////////////////////////////////////////////////////////////
void Game::setGameRound(int r) {
    gameRound = r;
}

////////////////////////////////////////////////////////////
int Game::getGameRound() const {
    return gameRound;
}

////////////////////////////////////////////////////////////
Word::Word(const std::string& w) :
value(w),
isGuessed(false)
{

}

