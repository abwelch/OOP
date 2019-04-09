#ifndef SPRITES_HPP
#define SPRITES_HPP

#include "Textures.hpp"

class Sprites
{
  private:
    Sprite background, ball, paddle, blocks[1000];

  public:
    Sprites(Textures &);
    void populateBlocks(int &, Textures &);
    void movePaddle();
    float collision(int, int);
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