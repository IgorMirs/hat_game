#ifndef WORD_H
#define WORD_H

#include <string>

class Word {
public:
    Word(const std::string& w = "");
    std::string getValue() const {return value; }
    bool getIsGuessed() const {return isGuessed; }
    void setIsGuessed(bool val) { isGuessed = val; }
private:
    std::string value;
    bool isGuessed;
};

#endif


////////////////////////////////////////////////////////////

#ifndef GAME_H
#define GAME_H
#include "GameState.h"
#include "StartState.h"
#include "GetTeamsState.h"
#include "GetWordsState.h"
#include "GuessWordsState.h"
#include "SFML/Graphics.hpp"

#include <vector>
#include <array>


class Game {
public:
    Game();
    ~Game();

    void        run();
    void        setText(sf::Text& text);

    sf::Font&   getFont();
    
    unsigned    getWindowWidth() const;
    unsigned    getWindowHeight() const;

    void        changeGameState(GameState::State gameState);

    void        setNumberOfPlayers(int np);
    void        setNumberOfTeams(int np);
    int         getNumberOfPlayers();
    int         getNumberOfTeams();
    void        addWord(const std::string& word);
    void        printWords() const;
    std::string pickWord();
    void        markGuessedWord();
    bool        isAllWordsGuessed() const;
    
private:
    sf::RenderWindow m_window;
    GameState* m_currentState;
    std::array<GameState*, GameState::State::COUNT> m_gameStates;
    sf::Font m_font;
    void loadFont(sf::Font& font);

    int numberOfPlayers;
    int numberOfTeams;
    std::vector<Word> words;
    int currentWord;
    int numberOfGuessedWords;
};

#endif //GAME_H