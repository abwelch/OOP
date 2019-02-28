// playingCard class that utilizes bit manipulation for both jokers and standard
// cards

#include "playingCard_binaryRep.hpp"

const Color playingCard_binaryRep::getColor()
{
    if (isJoker())
    {
        return static_cast<Color>(data & 0xf);
    }
}

bool playingCard_binaryRep::isJoker()
{
    // If the bits of card object match designated bits for a joker
    return ((data & 0b1000000) == 0b1000000);
}

const Rank playingCard_binaryRep::getRank()
{

    return static_cast<Rank>(data & 0xf);
}

const Suit playingCard_binaryRep::getSuit()
{
    return static_cast<Suit>(data >> 4);
}

std::string playingCard_binaryRep::colorToString()
{
    switch (static_cast<Color>(data & 0xf))
    {
    case 0:
        return "RED";
        break;
    case 1:
        return "BLACK";
        break;
    }
}

std::string playingCard_binaryRep::rankToString()
{
    switch (static_cast<Rank>(data & 0xf))
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

std::string playingCard_binaryRep::suitToString()
{
    switch (static_cast<Suit>(data >> 4))
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
