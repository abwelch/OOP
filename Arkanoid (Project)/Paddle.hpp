#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <SFML/Graphics.hpp>

class Paddle
{
  private:
    sf::Sprite paddle;

  public:
    Paddle();
    void setPos();
    void keyPressRight();
    void keyPressLeft();
    void collision(int, int, float &);
    sf::Sprite getPaddleSprite() const
    {
        return paddle;
    }
};

#endif