#include "deck.hpp"
#include "card.hpp"

deck::deck()
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 13; ++j)
        {
            card newCard(static_cast<rank>(j), static_cast<suit>(i));
            deckVector.push_back(newCard);
        }
    }
    shuffleDeck();
}

void deck::shuffleDeck()
{
    auto rng = std::default_random_engine{};
    std::shuffle(std::begin(deckVector),
                 std::end(deckVector), rng);
}

void deck::displayDeck()
{
    int rowCounter = 0;
    for (std::vector<card>::iterator beginIter = deckVector.begin();
         beginIter < deckVector.end(); ++beginIter)
    {
        if (rowCounter % 12 == 0)
            std::cout << std::endl;
    }
}