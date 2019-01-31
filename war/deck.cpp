#include "warGame.hpp"
#include "card.hpp"

// Default constructor to generate a randomly sorted deck and distribute to both
// player vectors
warGame::warGame()
{
    // Creates an array to temporarily hold all cards for random assignment
    card fullDeck[52];
    // Assign all card combinations to random array positions
    unsigned seed = time(0);
    srand(seed);
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 13; ++j)
        {
        }
    }
}