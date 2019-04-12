#include "Ball.hpp"

void Ball::hitBottom(int &score, sf::RenderWindow &app, int difficulty)
{
    if (ball.getPosition().y > 450)
    {
        std::cout << "Collision!\n";
        if (difficulty == 2)
        {
            // No negative scores
            if (score == 0)
                return;
            --score;
            std::cout << "SCORE: " << score << std::endl;
        }
        if (difficulty == 3)
        {
            std::cout << "YOU LOSE!\n";
            app.close();
        }
    }
}