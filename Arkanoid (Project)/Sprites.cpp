#include "Sprites.hpp"

Sprites::Sprites(int &n)
{
    Texture t1, t2, t3, t4;
    t1.loadFromFile("images/block01.png");
    t2.loadFromFile("images/background.jpg");
    t3.loadFromFile("images/ball.png");
    t4.loadFromFile("images/paddle.png");
    background.setTexture(t2);
    ball.setTexture(t3);
    paddle.setTexture(t4);
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
        {
            blocks[n].setTexture(t1);
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

void Sprites::collision(int x, int y, float &dy)
{
    if (FloatRect(x, y, 12, 12).intersects(paddle.getGlobalBounds()))
        dy = -(rand() % 5 + 2);
}