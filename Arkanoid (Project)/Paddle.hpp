#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <SFML/Graphics.hpp>

class Paddle
{
private:
  sf::Sprite paddle;

public:
  Paddle(sf::Texture *);
  void setPos();
  void keyPressRight();
  void keyPressLeft();
  void redirect(int, int, float &);
  sf::Sprite getPaddleSprite() const
  {
    return paddle;
  }
};

#endif