#include <SFML/Graphics.hpp>
#include <iostream>
#include "include/ball.h"
#include "include/paddle.h"
#include "include/ScoreBoard.h"

int main()
{
    bool play = false;
    //Window
    sf::RenderWindow window({1280, 720, 32}, "Ping-Pong");

    sf::Font font;
    font.loadFromFile("/Users/hargy/CLionProjects/Ping-Pong-Game/RobotoMono-VariableFont_wght.ttf");
    ScoreBoard scoreBoard({585,50});
    scoreBoard.setFont(font);
    scoreBoard.setScoreBoard();

    //Ball
    ball circle;
    circle.setRadius(15);
    circle.setPosition(630,350);
    circle.setFillColor(sf::Color::Red );
    circle.setVelocity({.1, -.13});

    //Left Paddle
    paddle paddleLeft(20,100);
    paddleLeft.setPosition(0,200);
    paddleLeft.setFillColor(sf::Color::Green);
    paddleLeft.setPaddle();

    //Right Paddle
    paddle paddleRight(20,100);
    paddleRight.setPosition(window.getSize().x - 20,100);
    paddleRight.setFillColor(sf::Color::Blue);
    paddleRight.setPaddle();

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            play = !play;
        }
        if(play){
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                paddleRight.movePaddleUp(window.getSize());
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                paddleRight.movePaddleDown(window.getSize());
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                paddleLeft.movePaddleUp(window.getSize());
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                paddleLeft.movePaddleDown(window.getSize());
            }
            // circle.bounce(window.getSize());
            circle.bounce(window.getSize(), paddleLeft.getGlobalBounds(), paddleRight.getGlobalBounds());
        }
        window.clear(sf::Color::Black);
        scoreBoard.updateScoreBoard(window.getSize(), circle.getGlobalBounds());
        if(circle.getGlobalBounds().left + circle.getGlobalBounds().width >= window.getSize().x || circle.getGlobalBounds().left <= 0 ){
            circle.setPosition(630,350);
            play = !play;
        }
        window.draw(circle);
        window.draw(paddleLeft);
        window.draw(paddleRight);
        window.draw(scoreBoard);
        window.display();
    }
    return 0;
}