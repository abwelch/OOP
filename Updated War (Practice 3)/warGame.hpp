#ifndef WARGAME_HPP
#define WARGAME_HPP
#include "deck.hpp"
#include <algorithm>
#include <iostream>
#include <random>

class warGame
{
  private:
    std::vector<card> p1;
    std::vector<card> p2;

  public:
    warGame(deck &);
    void battle(std::vector<card>::iterator, std::vector<card>::iterator);
    /* void displayTurnOutcome(const std::string &, const std::string &,
                      const std::string &, const std::string &, short,
                      short, short, char);
void displayWinner(int, int);
*/
};

#endif