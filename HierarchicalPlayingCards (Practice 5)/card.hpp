/*
Card class that utilizes an enum for determining if a playing card will be
a joker card or a standard card. Joker and standard cards are derived from the
card class via inheritance
*/

#ifndef CARD_HPP
#define CARD_HPP

#include <cassert>
#include <deque>

enum Rank
{
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JOKER,
    QUEEN,
    KING,
    ACE,
};

enum Suit
{
    HEARTS,
    DIAMONDS,
    SPADES,
    CLUBS,
};

enum Color
{
    Red,
    Black,
};

// Base Card class that joker/standard cards will be derived from.
// Declares the type enum that designates type of card
class Card
{
  public:
    enum Type
    {
        JOKER,
        STANDARD,
    };
    Type cardType;
    Card(Type n) { cardType = n; };
};

class StandardCard : Card
{
  public:
    Rank cardRank;
    Suit cardSuit;

    StandardCard(Rank r, Suit s) : Card(STANDARD), cardRank(r), cardSuit(s) {}
};
#endif