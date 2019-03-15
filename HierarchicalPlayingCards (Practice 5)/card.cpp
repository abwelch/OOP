#include "card.hpp"

bool Card::isStandard()
{
    if (cardType == STANDARD)
        return true;
    else
        return false;
}

std::ostream &operator<<(std::ostream &outputStream, const Card &x)
{
    outputStream << x.cardType;
    return outputStream;
}

std::ostream &operator<<(std::ostream &outputStream, const StandardCard &x)
{
    outputStream << x.cardRank << " " << x.cardSuit;
    return outputStream;
}

std::ostream &operator<<(std::ostream &outputStream, const JokerCard &x)
{
    outputStream << x.cardColor;
    return outputStream;
}