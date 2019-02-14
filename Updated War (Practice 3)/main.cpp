#include "warGame.hpp"

int main()
{
  // Create a shuffled deck object that will be used to play war
  deck warDeck;
  // Create a warGame object with the deck object
  warGame warInstance(warDeck);
  // Commence the recursive war function
  warInstance.battle(warInstance.getp1Iter(), warInstance.getp2Iter());
  return 0;
}