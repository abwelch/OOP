#include "card.hpp"

// Default constructor only needed for declaration of of card array.
card::card()
{
    cardRank = TWO;
    cardSuit = SPADE;
}
card::card(rank startRank, suit startSuit)
{
    cardRank = startRank;
    cardSuit = startSuit;
}