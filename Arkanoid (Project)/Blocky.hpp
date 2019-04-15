#ifndef BLOCKY_HPP
#define BLOCKY_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Blocky
{
private:
  sf::Sprite block[1000];
  int delBlocks;

public:
  Blocky(int &, sf::Texture *, sf::Texture *);
  sf::Sprite getBlock(int i)
  {
    return block[i];
  }
  void blockCollision(float &, const float, const float, const float, int &, sf::Texture *);
  int blocksRemoved() const
  {
    return delBlocks;
  }
};

#endif