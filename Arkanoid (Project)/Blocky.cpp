#include "Blocky.hpp"

Blocky::Blocky(int &n)
{
    sf::Texture blockyImage;
    blockyImage.loadFromFile("images/block01.png");
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
        {
            block[n].setTexture(blockyImage);
            block[n].setPosition(i * 43, j * 20);
            n++;
        }
}