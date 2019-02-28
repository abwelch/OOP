// Card class that creates card objects with values assigned by utilizing enums
#ifndef PLAYINGCARD_TAGGEDUNION_HPP
#define PLAYINGCARD_TAGGEDUNION_HPP
#include <cassert>
#include <deque>
#include <string>

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
  JACK,
  QUEEN,
  KING,
  ACE
};
enum Suit
{
  SPADE,
  CLUB,
  HEART,
  DIAMOND
};
// Utilized for joker cards
enum Color
{
  RED,
  BLACK
};
class playingCard_taggedUnion
{
private:
  Rank cardRank;
  Suit cardSuit;

public:
  playingCard_taggedUnion(Rank r, Suit s) : cardRank(r), cardSuit(s) {}
  Rank getRank() const { return cardRank; }
  Suit getSuit() const { return cardSuit; }
  std::string rankToString(Rank r);
  std::string suitToString(Suit s);
};

class JokerCard
{
public:
  JokerCard(Color c) : cardColor(c) {}
  Color getColor() const { return cardColor; }

private:
  Color cardColor;
};

union PlayingCardComponents {
  PlayingCardComponents(Rank r, Suit s) : sc(r, s) {}

  PlayingCardComponents(Color c) : jc(c) {}

  playingCard_taggedUnion sc;
  JokerCard jc;
};

enum PlayingCardType
{
  Standard,
  Joker
};

std::ostream &operator<<(std::ostream &os, Color r);
#endif