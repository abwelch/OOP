#include "Instance.hpp"
#include "Sprites.hpp"

Instance::Instance() : x(300), y(300), dx(6), dy(5), n(0), images(), objects(images)
{
}

void Instance::startGame()
{
    RenderWindow app(VideoMode(520, 450), "Arkanoid!");
    app.setFramerateLimit(60);
    objects.populateBlocks(n, images);

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
                    .intersects(objects.getBlocksSprite(i).getGlobalBounds()))
            {
                objects.getBlocksSprite(i).setPosition(-100, 0);
                dx = -dx;
            }
        y += dy;
        for (int i = 0; i < n; i++)
            if (FloatRect(x + 3, y + 3, 6, 6)
                    .intersects(objects.getBlocksSprite(i).getGlobalBounds()))
            {
                objects.getBlocksSprite(i).setPosition(-100, 0);
                dy = -dy;
            }
        if (x < 0 || x > 520)
            dx = -dx;
        if (y < 0 || y > 450)
            dy = -dy;
        objects.movePaddle();
        objects.collision(x, y, dy);
        app.clear();
        app.draw(objects.getBackgroundSprite());
        app.draw(objects.getBallSprite());
        app.draw(objects.getPaddleSprite());
        for (int i = 0; i < n; i++)
            app.draw(objects.getBlocksSprite(i));
        app.display();
    }
}