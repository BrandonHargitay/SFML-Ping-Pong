//
// Created by Brandon Hargitay on 10/12/22.
//

#ifndef UNTITLED_SCOREBOARD_H
#define UNTITLED_SCOREBOARD_H
#include <SFML/Graphics.hpp>

class ScoreBoard : public sf::Text {
private:
    int scorePlayer1, scorePlayer2;
    sf::Vector2f scoreBoardPosition;
public:
    ScoreBoard();
    ScoreBoard(sf::Vector2f scoreBoardPosition);
    void setScoreBoard();
    void updateScoreBoard(const sf::Vector2u& windowSize, sf::FloatRect ball);
};


#endif //UNTITLED_SCOREBOARD_H
