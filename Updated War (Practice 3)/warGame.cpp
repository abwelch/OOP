#include "warGame.hpp"

// Utilizes shuffle on full deck and then distributes to player vectors
void warGame::distributeDeck(deck &fullDeck)
{
    auto rng = std::default_random_engine{};
    std::shuffle(std::begin(fullDeck.fullUnsortedDeck),
                 std::end(fullDeck.fullUnsortedDeck), rng);
    // Distribute first half of shuffled deck to p1 vector and second half to p2
    for (int i = 0; i < fullDeck.fullUnsortedDeck.size(); ++i)
    {
        if (i < 26)
        {
            p1.push_back(fullDeck.fullUnsortedDeck[i]);
        }
        else
        {
            p2.push_back(fullDeck.fullUnsortedDeck[i]);
        }
    }
}
