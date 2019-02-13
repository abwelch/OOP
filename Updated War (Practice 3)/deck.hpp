#ifndef DECK_HPP
#define DECK_HPP
#include "card.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include <random>
#include <iterator>

class deck
{
public:
  std::vector<card> deckVector;
  deck();
  void shuffleDeck();
  void displayDeck();
};

#endif