#ifndef SPRITES_HPP
#define SPRITES_HPP

#include <SFML/Graphics.hpp>
using namespace sf;

class Sprites
{
  private:
    Sprite background, ball, paddle, blocks[1000];

  public:
    Sprites(int &);
    void movePaddle();
    void collision(int, int, float &);
    void ballPosition(int, int);
    Sprite getBackgroundSprite()
    {
        return background;
    }
    Sprite getBallSprite()
    {
        return ball;
    }
    Sprite getPaddleSprite()
    {
        return paddle;
    }
    Sprite getBlocksSprite(int i)
    {
        return blocks[i];
    }
};
#endif