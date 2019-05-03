#include "Instance.hpp"

void Instance::difficultySetting() {
  std::cout
      << "Choose which mode you wish to play by entering the appropriate "
         "integer: \n"
      << "1. EASY- no score deductions.\n"
      << "2. MEDIUM - minus 1 from score every time ball hits the bottom.\n"
      << "3. HARD - game will END if ball hits the bottom\n";
  std::cin >> difficulty;
  std::cout << "Difficulty set! Press enter to begin!\n";
  std::cin.ignore();
  std::cin.get();
}

void Instance::startGame(const Textures &images) {
  srand(time(0));
  sf::RenderWindow app(sf::VideoMode(520, 450), "Arkanoid!");
  app.setFramerateLimit(60);
  paddle.setPos();
  while (app.isOpen()) {
    sf::Event e;
    while (app.pollEvent(e)) {
      if (e.type == sf::Event::Closed)
        app.close();
    }

    ball.hitBottom(score, app, difficulty);
    x += dx;
    blocks.blockCollision(dx, x, y, n, score, images.redBlockImage);
    y += dy;
    blocks.blockCollision(dy, x, y, n, score, images.redBlockImage);

    if (x < 0 || x > 520)
      dx = -dx;
    if (y < 0 || y > 450)
      dy = -dy;

    paddle.keyPressRight();
    paddle.keyPressLeft();
    paddle.redirect(x, y, dy);
    ball.setPos(x, y);
    this->drawObjects(app);
    gameComplete(app);
  }
}

void Instance::drawObjects(sf::RenderWindow &app) {
  app.clear();
  app.draw(background.getBackgroundSprite());
  app.draw(ball.getBallSprite());
  app.draw(paddle.getPaddleSprite());
  for (int i = 0; i < n; i++)
    app.draw(blocks.getBlock(i));
  app.display();
}

void Instance::gameComplete(sf::RenderWindow &app) {
  if (blocks.blocksRemoved() == 80) {
    std::cout << "GAME COMPLETE!\n"
              << "FINAL SCORE: " << score << std::endl;
    app.close();
    return;
  }
}