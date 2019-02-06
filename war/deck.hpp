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
  void distributeDeck(std::vector<card> &);
  void battle();
  void displayTurnOutcome(const std::string &, const std::string &,
                          const std::string &, const std::string &, short,
                          short, short, char);
  void war(int, int);
};

#endif