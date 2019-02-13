#include "warGame.hpp"

// Utilizes shuffle on full deck and then distributes to player vectors
warGame::warGame(deck &fullDeck)
{
    auto rng = std::default_random_engine{};
    std::shuffle(std::begin(fullDeck.fullUnsortedDeck),
                 std::end(fullDeck.fullUnsortedDeck), rng);
    // Distribute first half of shuffled deck to p1 vector and second half to p2
    for (int i = 0; i < fullDeck.fullUnsortedDeck.size(); ++i)
    {
        if (i < 26)
        {
            p1.push_back(fullDeck.fullUnsortedDeck[i]);
        }
        else
        {
            p2.push_back(fullDeck.fullUnsortedDeck[i]);
        }
    }
}

void warGame::battle(std::vector<card>::iterator p1pos,
                     std::vector<card>::iterator p2pos, int turn)
{
	displayHand(p1pos, p2pos, turn);
    // Recursion base case
    if (p1.empty() || p2.empty())
    {
    	displayEndResult();
        return;
    }
    // If p1 iterator is pointing to end of p1 deck: reset to beginning
    if (p1pos == p1.end())
    {
        p1pos = p1.begin();
    }
    // If p2 iterator is pointing to end of p2 deck: reset to beginning
    if (p2pos == p2.end())
    {
        p2pos = p2.begin();
    }
    // p1 wins the hand
    if (p1pos->getRank() > p2pos->getRank())
    {
        // Add p2's card to buttom of p1 deck
        p1.push_back(*p2pos);
        p2.erase(p2pos);
        battle(++p1pos, ++p2pos, ++turn);
    }
    // p2 wins the hand
    else if (p1pos->getRank() < p2pos->getRank())
    {
        // Add p1's card to buttom of p2 deck
        p2.push_back(*p1pos);
        p1.erase(p1pos);
        battle(++p1pos, ++p2pos, ++turn);
    }
    // WAR
    else
    {
    	std::vector<card>::iterator p1posTemp = p1pos;
    	std::vector<card>::iterator p2posTemp = p2pos;
    	//card p1temp = card(p1pos->getRank(), p1pos->getSuit());
    	//card p2temp = card(p2pos->getRank(), p2pos->getSuit());
    	int p1SizeBefore = p1.size();
    	battle(++p1pos, ++p2pos, ++turn);
    	// p1 won the war
    	if (p1.size() > p1SizeBefore)
    	{
    		p1.push_back(*p2posTemp);
    		p2.erase(p2posTemp);
    	}
    	// p2 won the war
    	else
    	{
    		p2.push_back(*p1posTemp);
    		p1.erase(p1posTemp);
    	}
    	battle(++p1pos, ++p2pos, ++turn);
    }
}

void warGame::displayHand(std::vector<card>::iterator p1pos,
                     std::vector<card>::iterator p2pos, int turn)
{
	std::cout << "TURN " << turn << ":\n"
			  << "p1's card: " << p1pos->rankToString() << " of "
			  << p1pos->suitToString()
			  << "p2's card: " << p2pos->rankToString() << " of "
			  << p2pos->suitToString() << std::endl;

}
void warGrame::displayEndResult()
{
	if (p1.empty())
		std::cout << "p1 is out of cards! p2 has won!\n";
	else 
		std::cout << "p2 is out of cards! p1 has won!\n";
}

