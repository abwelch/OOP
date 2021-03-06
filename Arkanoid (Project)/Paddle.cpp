#include "Paddle.hpp"

Paddle::Paddle(sf::Texture *padImage)
{
    paddle.setTexture(*padImage);
}

void Paddle::setPos()
{
    paddle.setPosition(300, 440);
}

void Paddle::keyPressRight()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        paddle.move(6, 0);
}

void Paddle::keyPressLeft()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        paddle.move(-6, 0);
}

void Paddle::redirect(int x, int y, float &dy)
{
    if (sf::FloatRect(x, y, 12, 12).intersects(paddle.getGlobalBounds()))
        dy = -(rand() % 5 + 2);
}