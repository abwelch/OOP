#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>

class Ball
{
private:
  sf::Sprite ball;

public:
  Ball(sf::Texture *ballImage)
  {
    ball.setTexture(*ballImage);
  }
  void setPos(int x, int y)
  {
    ball.setPosition(x, y);
  }
  sf::Sprite getBallSprite() const
  {
    return ball;
  }
};

#endif