#ifndef TEXTURES_HPP
#define TEXTURES_HPP

#include <SFML/Graphics.hpp>
#include <memory>

struct Textures
{
    sf::Texture *padImage;
    sf::Texture *ballImage;
    sf::Texture *backgroundImage;
    sf::Texture *blockImage;
    Textures();
};

#endif