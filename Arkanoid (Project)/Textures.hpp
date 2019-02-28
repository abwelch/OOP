#ifndef TEXTURES_HPP
#define TEXTURES_HPP

#include <SFML/Graphics.hpp>
using namespace sf;

class Textures
{
  private:
    Texture ballTexture;
    Texture paddleTexture;
    Texture blockTexture;
    Texture backgroundTexture;

  public:
    Textures();
    Texture getBallTexture();
    Texture getPaddleTexture();
    Texture getBlockTexture();
    Texture getBackgroundTexture();
};
#endif