#include "warGame.hpp"

// Utilizes shuffle on full deck and then distributes to player vectors
warGame::warGame(deck &fullDeck)
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

void warGame::battle(std::vector<card>::iterator p1pos,
                     std::vector<card>::iterator p2pos)
{
    // Recursion base case
    if (p1.empty() || p2.empty())
    {
        return;
    }
    // If p1 iterator is pointing to end: reset to beginning
    if (p1pos == p1.end())
    {
        p1pos = p1.begin();
    }
    // If p2 iterator is pointing to end: reset to beginning
    if (p2pos == p2.end())
    {
        p2pos = p2.begin();
    }
    // p1 wins the hand
    if (p1pos->getRank() > p2pos->getRank())
    {
        // Add p2's card to buttom of p1 deck
        p1.push_back(*p2pos);
        p2.erase(p2pos);
    }
    // p2 wins the hand
    else if (p1pos->getRank() < p2pos->getRank())
    {
        // Add p1's card to buttom of p2 deck
        p2.push_back(*p1pos);
        p1.erase(p1pos);
    }
    // WAR
    else
    {
    }
}
