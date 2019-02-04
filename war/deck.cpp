#include "deck.hpp"
#include "card.hpp"

// Default constructor to generate a randomly sorted deck and distribute to both
// player vectors
deck::deck()
{
    // Creates an array to temporarily hold all cards for random assignment
    card fullDeck[52];
    unsigned seed = time(0);
    srand(seed);
    int randomPosition;
    // Used with rand()
    const int MIN = 0, MAX = 51;
    // Used to maintain record of previously generated numbers
    std::vector<int> usedPosition;
    bool inUse = false;

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 13; ++j)
        {
            do
            {
                // Formula to generate random number between 0 and 51
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
                        usedPosition.push_back(randomPosition);
                    }
                }
            } while (inUse);
            card newCard(static_cast<rank>(j), static_cast<suit>(i));
            fullDeck[randomPosition] = newCard;
        }
    }
}