// playingCard class that utilizes a tagged union

#include "playingCard_taggedUnion.hpp"

playingCard_taggedUnion::playingCard_taggedUnion(Rank startRank, Suit startSuit)
    : cardRank(startRank), cardSuit(startSuit) {}

playingCard_taggedUnion::playingCard_taggedUnion(Color startColor)
{
}
// Accessors
const Rank playingCard_taggedUnion::getRank()
{
    return static_cast<rank>(data & 0xf);
}
const Suit playingCard_taggedUnion::getSuit()
{
    return static_cast<suit>(data >> 4);
}

std::string playingCard_taggedUnion::rankToString()
{
    switch (static_cast<rank>(data & 0xf))
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

std::string playingCard_taggedUnion::suitToString()
{
    switch (static_cast<suit>(data >> 4))
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