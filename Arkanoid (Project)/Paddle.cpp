#include "Paddle.hpp"

Paddle::Paddle()
{
    padSprite = Sprite(padTexture.getPaddleTexture());
    padSprite.setPosition(300, 440);
}

void Paddle::paddleMovement()
{
    if (Keyboard::isKeyPressed(Keyboard::Right))
        padSprite.move(6, 0);
    if (Keyboard::isKeyPressed(Keyboard::Left))
        padSprite.move(-6, 0);
}

sf::FloatRect Paddle::getBounds() {}