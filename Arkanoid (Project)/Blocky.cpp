#include "Blocky.hpp"

Blocky::Blocky(int &n, sf::Texture *blockyImage, sf::Texture *redBlockyImage) : delBlocks(0)
{
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            if (i % 4 == 0)
            {
                block[n].setTexture(*redBlockyImage);
                block[n].setPosition(i * 43, j * 20);
                n++;
            }
            else
            {
                block[n].setTexture(*blockyImage);
                block[n].setPosition(i * 43, j * 20);
                n++;
            }
        }
    }
}

void Blocky::blockCollision(float &dXY, const float x, const float y,
                            const float n, int &score, sf::Texture *redBlockyImage)
{
    for (int i = 0; i < n; i++)
    {

        if (sf::FloatRect(x + 3, y + 3, 6, 6)
                .intersects(block[i].getGlobalBounds()))
        {
            if (block[i].getTexture() == redBlockyImage)
            {
                dXY = -dXY;
            }
            else
            {
                block[i].setPosition(-100, 0);
                dXY = -dXY;
                ++score;
                ++delBlocks;
                std::cout << "SCORE: " << score << std::endl;
            }
        }
    }
}