#include "Instance.hpp"

int main()
{
  srand(time(0));
  Textures images;

  Instance arkGame(images);
  arkGame.startGame();
  return 0;
}
