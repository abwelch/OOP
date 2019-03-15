/*
Card class that utilizes an enum for determining if a playing card will be
a joker card or a standard card. Joker and standard cards are derived from the
card class via inheritance
*/

#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>

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
    RED,
    BLACK,
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
    friend std::ostream &operator<<(std::ostream &outputStream, const Card &x);
    bool isStandard();
};

class StandardCard : Card
{
  public:
    Rank cardRank;
    Suit cardSuit;
    StandardCard(Rank r, Suit s) : Card(STANDARD), cardRank(r), cardSuit(s) {}
    friend std::ostream &operator<<(std::ostream &outputStream,
                                    const StandardCard &x);
};

class JokerCard : Card
{
  public:
    Color cardColor;
    JokerCard(Color c) : Card(JOKER), cardColor(c) {}
    friend std::ostream &operator<<(std::ostream &outputStream,
                                    const JokerCard &x);
};
#endif