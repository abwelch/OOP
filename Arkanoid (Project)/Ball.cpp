#include "Ball.hpp"

Ball::Ball()
{
    sf::Texture ballImage;
    ballImage.loadFromFile("images/ball.png");
    ball.setTexture(ballImage);
}

void Ball::setPos(int x, int y)
{
    ball.setPosition(x, y);
}