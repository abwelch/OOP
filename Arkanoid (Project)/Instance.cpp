#include "Instance.hpp"

void Instance::startGame()
{
    srand(time(0));
    sf::RenderWindow app(sf::VideoMode(520, 450), "Arkanoid!");
    app.setFramerateLimit(60);
    paddle.setPos();
    while (app.isOpen())
    {
        sf::Event e;
        while (app.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
                app.close();
        }
        x += dx;

        for (int i = 0; i < n; i++)
            if (sf::FloatRect(x + 3, y + 3, 6, 6)
                    .intersects(blocks.getBlock(i).getGlobalBounds()))
            {
                blocks.getBlock(i).setPosition(-100, 0);
                dx = -dx;
            }

        y += dy;
        for (int i = 0; i < n; i++)
            if (sf::FloatRect(x + 3, y + 3, 6, 6)
                    .intersects(blocks.getBlock(i).getGlobalBounds()))
            {
                blocks.getBlock(i).setPosition(-100, 0);
                dy = -dy;
            }

        if (x < 0 || x > 520)
            dx = -dx;
        if (y < 0 || y > 450)
            dy = -dy;

        paddle.keyPressRight();
        paddle.keyPressLeft();
        paddle.collision(x, y, dy);
        ball.setPos(x, y);

        app.clear();
        this->drawObjects(app);
    }
}

void Instance::drawObjects(sf::RenderWindow &app)
{
    app.draw(background.getBackgroundSprite());
    app.draw(ball.getBallSprite());
    app.draw(paddle.getPaddleSprite());
    for (int i = 0; i < n; i++)
        app.draw(blocks.getBlock(i));
    app.display();
}