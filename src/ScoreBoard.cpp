//
// Created by Brandon Hargitay on 10/12/22.
//

#include "../include/ScoreBoard.h"

ScoreBoard::ScoreBoard(){
    scoreBoardPosition.x = 0;
    scoreBoardPosition.y = 0;
    scorePlayer1 = 0;
    scorePlayer2 = 0;
}
ScoreBoard::ScoreBoard(sf::Vector2f poistion){
    scoreBoardPosition.x = poistion.x;
    scoreBoardPosition.y = poistion.y;
    scorePlayer1 = 0;
    scorePlayer2 = 0;
}
void ScoreBoard::setScoreBoard(){
    sf::Text::setString("0 : 0");
    sf::Text::setPosition(scoreBoardPosition);
    sf::Text::setCharacterSize(40);
    sf::Text::setStyle(sf::Text::Bold);
}
void ScoreBoard::updateScoreBoard(const sf::Vector2u& windowSize, sf::FloatRect ball){

    if(ball.left + ball.width >= windowSize.x){
        scorePlayer1 = scorePlayer1 + 1;
        std::string score = std::to_string(scorePlayer1) + " : " + std::to_string(scorePlayer2);
        sf::Text::setString(score);
    }

    if(ball.left <= 0){
        scorePlayer2 = scorePlayer2 + 1;
        std::string score = std::to_string(scorePlayer1) + " : " + std::to_string(scorePlayer2);
        sf::Text::setString(score);

    }

}