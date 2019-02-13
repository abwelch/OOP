#ifndef WARGAME_HPP
#define WARGAME_HPP
#include "deck.hpp"

class warGame
{
  private:
    std::vector<card> p1;
    std::vector<card> p2;

  public:
    warGame(deck &);
    void battle(std::vector<card>::iterator = p1.begin(), std::vector<card>::iterator = p2.begin(), int = 1);
    void displayHand(std::vector<card>::iterator,
                     std::vector<card>::iterator, int);
    void displayEndResult();
};

#endif