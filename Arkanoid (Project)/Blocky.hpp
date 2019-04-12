#ifndef BLOCKY_HPP
#define BLOCKY_HPP

#include <SFML/Graphics.hpp>

class Blocky
{
private:
  sf::Sprite block[1000];

public:
  Blocky(int &, sf::Texture *);
  sf::Sprite getBlock(int i)
  {
    return block[i];
  }
};

#endif