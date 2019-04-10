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
    blockImage->loadFromFile("images/block01.png");
}