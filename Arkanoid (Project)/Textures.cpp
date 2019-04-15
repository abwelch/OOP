#include "Textures.hpp"

Textures::Textures()
{
    padImage = new sf::Texture;
    padImage->loadFromFile("images/paddle.png");
    ballImage = new sf::Texture;
    ballImage->loadFromFile("images/ball.png");
    backgroundImage = new sf::Texture;
    backgroundImage->loadFromFile("images/background.jpg");
    blockImage = new sf::Texture;
    blockImage->loadFromFile("images/block04.png");
    redBlockImage = new sf::Texture;
    redBlockImage->loadFromFile("images/block02.png");
}

Textures::~Textures()
{
    delete padImage;
    delete ballImage;
    delete backgroundImage;
    delete blockImage;
    delete redBlockImage;
}