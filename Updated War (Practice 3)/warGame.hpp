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
  std::vector<card>::iterator getp1Iter()
  {
    std::vector<card>::iterator p1iter = p1.begin();
    return p1iter;
  }
  std::vector<card>::iterator getp2Iter()
  {
    std::vector<card>::iterator p2iter = p2.begin();
    return p2iter;
  }
  void battle(std::vector<card>::iterator, std::vector<card>::iterator,
              int = 1);
  void displayHand(const std::vector<card>::iterator,
                   const std::vector<card>::iterator, const int);
  void displayEndResult();
  void displayPlayerHands();
};

#endif