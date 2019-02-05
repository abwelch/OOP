#include "card.hpp"

card::card(int startRank, int startSuit)
{
    switch (startRank)
    {
    case 0:
        cardRank = TWO;
        break;
    case 1:
        cardRank = THREE;
        break;
    case 2:
        cardRank = FOUR;
        break;
    case 3:
        cardRank = FIVE;
        break;
    case 4:
        cardRank = SIX;
        break;
    case 5:
        cardRank = SEVEN;
        break;
    case 6:
        cardRank = EIGHT;
        break;
    case 7:
        cardRank = NINE;
        break;
    case 8:
        cardRank = TEN;
        break;
    case 9:
        cardRank = JACK;
        break;
    case 10:
        cardRank = QUEEN;
        break;
    case 11:
        cardRank = KING;
        break;
    case 12:
        cardRank = ACE;
        break;
    }

    switch (startSuit)
    {
    case 0:
        cardSuit = SPADE;
        break;
    case 1:
        cardSuit = CLUB;
        break;
    case 2:
        cardSuit = HEART;
        break;
    case 3:
        cardSuit = DIAMOND;
        break;
    }
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