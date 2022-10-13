//
// Created by Jessie Mejia on 10/10/22.
//

#ifndef UNTITLED_PADDLE_H
#define UNTITLED_PADDLE_H
#include <SFML/Graphics.hpp>


class paddle : public sf::RectangleShape {
private:
    sf::Vector2f size;
    sf::Vector2f velocity;
public:
    paddle();
    paddle(float width, float length);
    void setPaddle();
    void movePaddleUp(const sf::Vector2u& windowSize);
    void movePaddleDown(const sf::Vector2u& windowSize);
};


#endif //UNTITLED_PADDLE_H
