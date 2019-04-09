#include "Sprites.hpp"

Sprites::Sprites(Textures &images) : background(images.getBackgroundTexture()),
                                     ball(images.getBallTexture()), paddle(images.getPaddleTexture())
{
}

void Sprites::populateBlocks(int &n, Textures &images)
{
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
        {
            blocks[n].setTexture(images.getBlockTexture());
            blocks[n].setPosition(i * 43, j * 20);
            n++;
        }
}

void Sprites::movePaddle()
{
    if (Keyboard::isKeyPressed(Keyboard::Right))
        paddle.move(6, 0);
    if (Keyboard::isKeyPressed(Keyboard::Left))
        paddle.move(-6, 0);
}

void Sprites::ballPosition(int x, int y)
{
    ball.setPosition(x, y);
}

float Sprites::collision(int x, int y)
{
    if (FloatRect(x, y, 12, 12).intersects(paddle.getGlobalBounds()))
        return -(rand() % 5 + 2);
}