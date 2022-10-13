//
// Created by Jessie Mejia on 10/10/22.
//

#include "../include/paddle.h"

paddle::paddle() : sf::RectangleShape(){
    size.x = 15;
    size.y = 75;
    velocity.x = 0.3;
    velocity.y  = 0.3;
}
paddle::paddle(float width, float length){
    size.x = width;
    size.y = length;
    velocity.x = 0.3;
    velocity.y  = 0.3;
}

void paddle::setPaddle() {
    sf::RectangleShape::setSize(size);
}

void paddle::movePaddleUp(const sf::Vector2u& windowSize){
    sf::FloatRect b = getGlobalBounds();

    if(b.top <= 0){
        sf::RectangleShape::move({0,0});
    }else{
        sf::RectangleShape::move({0,-velocity.y});
    }

}
void paddle::movePaddleDown(const sf::Vector2u& windowSize){
    sf::FloatRect b = getGlobalBounds();

    if(b.top + b.height >= windowSize.y){
        sf::RectangleShape::move({0,0});
    }else{
        sf::RectangleShape::move({0,velocity.y});
    }
}
