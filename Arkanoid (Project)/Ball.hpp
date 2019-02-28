#ifndef BALL_HPP
#define BALL_HPP

#include "Textures.hpp"

class Ball
{
private:
  Textures ballTexture;
  Sprite ballSprite;

public:
  Ball();
  Sprite getSprite() { return ballSprite; }
};

#endif