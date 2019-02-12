// Card class that creates card objects with values assigned by utilizing enums
#ifndef CARD_HPP
#define CARD_HPP
#include <string>

enum rank
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
enum suit
{
  SPADE,
  CLUB,
  HEART,
  DIAMOND
};
class card
{
private:
  rank cardRank;
  suit cardSuit;

public:
  card(int, int);
  // Accessors
  const rank getRank();
  const suit getSuit();
  std::string rankToString();
  std::string suitToString();
};
#endif