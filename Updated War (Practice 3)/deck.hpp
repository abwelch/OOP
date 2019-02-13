#ifndef DECK_HPP
#define DECK_HPP
#include "card.hpp"
#include <vector>

class deck
{
public:
  std::vector<card> fullUnsortedDeck;
  deck();
};

#endif