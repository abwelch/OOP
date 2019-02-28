#include "Textures.hpp"
Textures::Textures()
{
    blockTexture.loadFromFile("images/block01.png");
    backgroundTexture.loadFromFile("images/background.jpg");
    ballTexture.loadFromFile("images/ball.png");
    paddleTexture.loadFromFile("images/paddle.png");
}

Texture Textures::getBallTexture() { return ballTexture; }
Texture Textures::getPaddleTexture() { return paddleTexture; }
Texture Textures::getBlockTexture() { return blockTexture; }
Texture Textures::getBackgroundTexture() { return backgroundTexture; }