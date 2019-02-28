// Card class that creates card objects with values assigned by utilizing enums
#ifndef PLAYINGCARD_TAGGEDUNION_HPP
#define PLAYINGCARD_TAGGEDUNION_HPP
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
  union cardUnions {
    struct c
    {
      Color cardColor;
      const Color getColor();
      std::string colorToString();
    };
    struct r
    {
      Rank cardRank;
      const Rank getRank();
      std::string rankToString();
    };
    struct s
    {
      Suit cardSuit;
      const Suit getSuit();
      std::string suitToString();
    };
  };

public:
  playingCard_taggedUnion(Rank, Suit);
  playingCard_taggedUnion(Color);
};
#endif