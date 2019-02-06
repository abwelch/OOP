#ifndef DECK_HPP
#define DECK_HPP
#include "card.hpp"
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

class deck
{
private:
  std::vector<card> p1;
  std::vector<card> p2;

public:
  deck();
  void distributeDeck(const std::vector<card> &);
  void battle();
  void displayTurnOutcome(const std::string &, const std::string &,
                          const std::string &, const std::string &);
};

#endif