#include "Background.hpp"

Background::Background()
{
    sf::Texture backgroundImage;
    backgroundImage.loadFromFile("images/background.jpg");
    background.setTexture(backgroundImage);
}