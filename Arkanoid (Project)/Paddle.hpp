#ifndef PADDLE_HPP
#define PADDLE_HPP
#include "Textures.hpp"

class Paddle {
private:
  Textures padTexture;
  Sprite padSprite;

public:
  Paddle();
  void paddleMovement();
  sf::FloatRect getBounds();
  void setPos(int, int);
};
#endif