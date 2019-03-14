/*
Card class that utilizes an enum for determining if a playing card will be
a joker card or a standard card. Joker and standard cards are derived from the
card class via inheritance
*/

#ifndef CARD_HPP
#define CARD_HPP

#include <cassert>
#include <deque>

enum Suit {
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

enum Color {
  Red,
  Black,
};

class Card {
public:
  enum Type {
    JOKER,
    STANDARD,
  };
};
#endif