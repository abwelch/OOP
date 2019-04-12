#include "Ball.hpp"

Ball::Ball(sf::Texture *ballImage)
{
    ball.setTexture(*ballImage);
}

void Ball::setPos(int x, int y)
{
    ball.setPosition(x, y);
}