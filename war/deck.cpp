#include "deck.hpp"
#include "card.hpp"

// Default constructor to generate a randomly sorted deck and distribute to both
// player vectors
deck::deck()
{
    // Creates an array to temporarily hold all cards for random assignment
    card fullDeck[52];
    // Assign all card combinations to random array positions
    unsigned seed = time(0);
    srand(seed);
    int usedPosition[52];
    bool inUse = false;
    int randomPosition;
    const int MIN = 0, MAX = 51;

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 13; ++j)
        {
            do
            {
                randomPosition = (rand() % (MAX - MIN + 1)) + MIN;
                for (int i = 0; i < 52; ++i)
                {
                    if (randomPosition == usedPosition[i])
                    {
                        inUse = true;
                    }

                    else
                    {
                        inUse = false;
                    }
                }
            } while (inUse);
            card newCard(static_cast<rank>(j), static_cast<suit>(i));
            fullDeck[randomPosition] = newCard;
        }
    }
}