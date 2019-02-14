#include "card.hpp"

card::card(rank startRank, suit startSuit)
{
    cardRank = startRank;
    cardSuit = startSuit;
}

// Accessors
const rank card::getRank() { return cardRank; }
const suit card::getSuit() { return cardSuit; }

std::string card::rankToString()
{
    switch (cardRank)
    {
    case 0:
        return "TWO";
        break;
    case 1:
        return "THREE";
        break;
    case 2:
        return "FOUR";
        break;
    case 3:
        return "FIVE";
        break;
    case 4:
        return "SIX";
        break;
    case 5:
        return "SEVEN";
        break;
    case 6:
        return "EIGHT";
        break;
    case 7:
        return "NINE";
        break;
    case 8:
        return "TEN";
        break;
    case 9:
        return "JACK";
        break;
    case 10:
        return "QUEEN";
        break;
    case 11:
        return "KING";
        break;
    case 12:
        return "ACE";
        break;
    }
}

std::string card::suitToString()
{
    switch (cardSuit)
    {
    case 0:
        return "SPADE";
        break;
    case 1:
        return "CLUB";
        break;
    case 2:
        return "HEART";
        break;
    case 3:
        return "DIAMOND";
        break;
    }
}