/*
Executes necessary functions to run an instance of Arkanoid
*/

#ifndef INSTANCE_HPP
#define INSTANCE_HPP

#include "Background.hpp"
#include "Ball.hpp"
#include "Blocky.hpp"
#include "Events.hpp"
#include "Paddle.hpp"
#include "Textures.hpp"
#include <time.h>

class Instance {
private:
  float x, y, dx, dy;
  int n;
  Blocky blocks;
  Ball ball;
  Background background;
  Paddle paddle;
  int score, difficulty;

public:
  Instance(Textures &images)
      : x(300), y(300), dx(6), dy(5), n(0),
        blocks(n, images.blockImage, images.redBlockImage),
        ball(images.ballImage), background(images.backgroundImage),
        paddle(images.padImage), score(0), difficulty(0) {}
  void difficultySetting();
  void startGame(const Textures &);
  void drawObjects(sf::RenderWindow &);
  void gameComplete(sf::RenderWindow &);
};

#endif