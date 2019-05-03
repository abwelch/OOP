#include "Instance.hpp"

int main()
{
  srand(time(0));
  Textures images;
  Instance arkGame(images);
  arkGame.difficultySetting();
  arkGame.startGame(images);
  return 0;
}
