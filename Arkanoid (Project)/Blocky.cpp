#include "Blocky.hpp"

Blocky::Blocky(int size) {
  blockSprites.reserve(size);
  int n = 0;
  for (int i = 1; i <= 10; i++)
    for (int j = 1; j <= 10; j++) {
      blockSprites[n].setTexture(blockTexture.getBlockTexture());
      blockSprites[n].setPosition(i * 43, j * 20);
      n++;
    }
}