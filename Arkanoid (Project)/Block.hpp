#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "Textures.hpp"
#include <vector>

class Block
{
  private:
    Textures blockTexture;
    std::vector<Sprite> blockSprites;

  public:
    Block(int);
};
#endif