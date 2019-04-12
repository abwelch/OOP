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
        blocks.blockCollision(dx, x, y, n, score);
        y += dy;
        blocks.blockCollision(dy, x, y, n, score);

        if (x < 0 || x > 520)
            dx = -dx;
        if (y < 0 || y > 450)
            dy = -dy;

        paddle.keyPressRight();
        paddle.keyPressLeft();
        paddle.collision(x, y, dy);
        ball.setPos(x, y);

        this->drawObjects(app);
    }
}

void Instance::drawObjects(sf::RenderWindow &app)
{
    app.clear();
    app.draw(background.getBackgroundSprite());
    app.draw(ball.getBallSprite());
    app.draw(paddle.getPaddleSprite());
    for (int i = 0; i < n; i++)
        app.draw(blocks.getBlock(i));
    app.display();
}
