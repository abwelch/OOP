#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <SFML/Graphics.hpp>

class Background
{
private:
  sf::Sprite background;

public:
  Background(sf::Texture *backgroundImage)
  {
    background.setTexture(*backgroundImage);
  }
  sf::Sprite getBackgroundSprite() const
  {
    return background;
  }
};

#endif