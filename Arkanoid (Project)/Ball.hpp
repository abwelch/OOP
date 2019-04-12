#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>

class Ball
{
private:
  sf::Sprite ball;

public:
  Ball(sf::Texture *);
  void setPos(int, int);
  sf::Sprite getBallSprite() const
  {
    return ball;
  }
};

#endif