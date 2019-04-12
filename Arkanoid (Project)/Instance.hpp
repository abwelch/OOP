/* 
Executes necessary functions to run an instance of Arkanoid
*/

#ifndef INSTANCE_HPP
#define INSTANCE_HPP

#include "Ball.hpp"
#include "Blocky.hpp"
#include "Background.hpp"
#include "Paddle.hpp"
#include "Textures.hpp"

#include <iostream>
#include <time.h>

class Instance
{
private:
  float x, y, dx, dy;
  int n;
  Blocky blocks;
  Ball ball;
  Background background;
  Paddle paddle;

public:
  Instance(Textures &images) : x(300), y(300), dx(6), dy(5), n(0),
                               blocks(n, images.blockImage), ball(images.ballImage),
                               background(images.backgroundImage), paddle(images.padImage)
  {
  }
  void startGame();
};

#endif