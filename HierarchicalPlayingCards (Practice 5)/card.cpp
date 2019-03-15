#include "card.hpp"

bool Card::isStandard()
{
    if (cardType == STANDARD)
        return true;
    else
        return false;
}

Color Card::getColor()
{
}