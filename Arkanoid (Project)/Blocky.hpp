#ifndef BLOCKY_HPP
#define BLOCKY_HPP

#include "Textures.hpp"
#include <vector>

class Blocky {
private:
  Textures blockTexture;
  std::vector<Sprite> blockSprites;

public:
  Blocky(int);
};
#endif