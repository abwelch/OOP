#include "deck.hpp"
#include "card.hpp"

deck::deck()
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 13; ++j)
        {
            card newCard(j, i);
            fullUnsortedDeck.push_back(newCard);
        }
    }
}
