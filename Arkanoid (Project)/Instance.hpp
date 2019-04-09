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
};

#endif