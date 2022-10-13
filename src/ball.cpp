//
// Created by Jessie Mejia on 10/10/22.
//

#include "../include/ball.h"

void ball::setVelocity(sf::Vector2f velocity)
{
    this->velocity = velocity;
}
void ball::bounce(const sf::Vector2u& windowSize, sf::FloatRect leftPaddle, sf::FloatRect rightPaddle)
{
    sf::FloatRect b = getGlobalBounds();
    if (b.top + b.height >= windowSize.y || b.top <= 0)
    {
        velocity.y = -velocity.y;
    }

    if(rightPaddle.intersects(getGlobalBounds()))
    {
        velocity.x = -velocity.x;
        changeColor();
        std::cout << "Collision";
    }
    if(leftPaddle.intersects(getGlobalBounds()))
    {
        velocity.x = -velocity.x;
        changeColor();
        std::cout << "Collision";
    }

    sf::CircleShape::move(velocity);
}
void ball::changeColor(){
    sf::Color color(
            rand() % 256,
            rand() % 256,
            rand() % 256
    );
    setFillColor(color);
}


