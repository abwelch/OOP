/* 
Executes necessary functions to run an instance of Arkanoid
*/

#ifndef INSTANCE_HPP
#define INSTANCE_HPP

#include "Sprites.hpp"
#include <iostream>
#include <time.h>

class Instance
{
  private:
    float x, y, dx, dy;
    Textures images;
    Sprites objects;
    int n;

  public:
    Instance();
    void startGame();
    float getX() const
    {
        return x;
    }
    float getY() const
    {
        return y;
    }
    float getDX() const
    {
        return dx;
    }
    float getDY() const
    {
        return dy;
    }
    int getN() const
    {
        return n;
    }
};

#endif