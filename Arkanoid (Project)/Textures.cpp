#include "Textures.hpp"

Textures::Textures()
{
    padImage.loadFromFile("images/paddle.png");
    ballImage.loadFromFile("images/ball.png");
    backgroundImage.loadFromFile("images/background.jpg");
    blockImage.loadFromFile("images/block01.png");
}