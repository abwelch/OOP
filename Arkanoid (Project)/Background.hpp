#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <SFML/Graphics.hpp>

class Background
{
  private:
    sf::Sprite background;

  public:
    Background();
    sf::Sprite getBackgroundSprite()
    {
        return background;
    }
};

#endif