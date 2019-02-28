#include "Background.hpp"
#include "Ball.hpp"
#include "Blocky.hpp"
#include "Paddle.hpp"
#include "Textures.hpp"
#include <time.h>

int main()
{
  srand(time(0));

  RenderWindow app(VideoMode(520, 450), "Arkanoid!");
  app.setFramerateLimit(60);

  // Create objects
  Paddle paddle;
  Blocky blocks(1000);
  Ball ball;
  Background background;

  paddle.setPos(300, 440);

  float dx = 6, dy = 5;
  float x = 300, y = 300;

  while (app.isOpen())
  {
    Event e;
    while (app.pollEvent(e))
    {
      if (e.type == Event::Closed)
        app.close();
    }

    x += dx;
    for (int i = 0; i < n; i++)
      if (FloatRect(x + 3, y + 3, 6, 6)
              .intersects(block[i].getGlobalBounds()))
      {
        block[i].setPosition(-100, 0);
        dx = -dx;
      }

    y += dy;
    for (int i = 0; i < n; i++)
      if (FloatRect(x + 3, y + 3, 6, 6)
              .intersects(block[i].getGlobalBounds()))
      {
        block[i].setPosition(-100, 0);
        dy = -dy;
      }

    if (x < 0 || x > 520)
      dx = -dx;
    if (y < 0 || y > 450)
      dy = -dy;

    if (FloatRect(x, y, 12, 12).intersects(sPaddle.getGlobalBounds()))
      dy = -(rand() % 5 + 2);

    sBall.setPosition(x, y);

    app.clear();
    app.draw(background.getSprite());
    app.draw(ball.getSprite());
    app.draw(paddle.getSprite());

    for (int i = 0; i < n; i++)
      app.draw(block[i]);

    app.display();
  }

  return 0;
}
