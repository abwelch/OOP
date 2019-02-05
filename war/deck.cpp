#include "deck.hpp"
#include "card.hpp"
// Globals for keeping track of score outside of recursive battle function
short p1score = 0, p2score = 0, turn = 1;
char outcome;

deck::deck()
{
    std::vector<card> fullDeck;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 13; ++j)
        {
            card newCard(j, i);
            fullDeck.push_back(newCard);
        }
    }
    distributeDeck(fullDeck);
}

// Utilizes rand() to create different scenarios for how deck is distributed to
// players
void deck::distributeDeck(const std::vector<card> &fullDeck)
{
    unsigned seed = time(0);
    srand(seed);
    // Equation that allows randoms between 1 and 3 (inclusively)
    int randomScenario = (rand() % (3 - 1 + 1)) + 1;
    switch (randomScenario)
    {
    // Distributes first half to p1, second half p2
    case 1:
        for (int i = 0; i < fullDeck.size(); ++i)
        {
            if (i < 26)
            {
                p1.push_back(fullDeck[i]);
            }
            else
            {
                p2.push_back(fullDeck[i]);
            }
        }
        break;
    // Distributes by alternating
    case 2:
        for (int i = 0; i < fullDeck.size(); ++i)
        {
            if (i % 2 == 0)
            {
                p1.push_back(fullDeck[i]);
            }
            else
            {
                p2.push_back(fullDeck[i]);
            }
        }
        break;
        // Distributes first 25 to p2, next 25 to p1, then 1 more to each
    case 3:
        for (int i = 0; i < fullDeck.size() - 2; ++i)
        {
            if (i < 25)
            {
                p2.push_back(fullDeck[i]);
            }
            else
            {
                p1.push_back(fullDeck[i]);
            }
        }
        p1.push_back(fullDeck[50]);
        p2.push_back(fullDeck[51]);
    }
}

// Initiates the game
void deck::battle()
{
    for (int i = 0; i < 26; ++i)
    {
        if (p1[i].getRank() > p2[i].getRank())
        {
            ++p1score;
            outcome = 'O';
            displayTurnOutcome(p1[i].rankToString(), p2[i].rankToString(),
                               p1[i].suitToString(), p2[i].suitToString());
            p1.push_back(p2[i]);
            p2.erase(p2.begin() + i);
        }
        else if (p1[i].getRank() < p2[i].getRank())
        {
            ++p2score;
            outcome = 'T';
            displayTurnOutcome(p1[i].rankToString(), p2[i].rankToString(),
                               p1[i].suitToString(), p2[i].suitToString());
            p2.push_back(p1[i]);
            p1.erase(p1.begin() + i);
        }
        // WAR
        else
        {
            if (p1[i + 1].getRank() > p2[i + 1].getRank())
            {
                ++p1score;
                outcome = 'O';
                displayTurnOutcome(p1[i + 1].rankToString(), p2[i + 1].rankToString(),
                                   p1[i + 1].suitToString(), p2[i + 1].suitToString());
                p1.push_back(p2[i + 1]);
                p2.erase(p2.begin() + i + 1);
            }
            else if (p1[i + 1].getRank() < p2[i + 1].getRank())
            {
                ++p2score;
                outcome = 'T';
                displayTurnOutcome(p1[i + 1].rankToString(), p2[i + 1].rankToString(),
                                   p1[i + 1].suitToString(), p2[i + 1].suitToString());
                p2.push_back(p1[i + 1]);
                p1.erase(p1.begin() + i) + 1;
            }
        }
        ++turn;
    }
}

void deck::displayTurnOutcome(const std::string &p1rank,
                              const std::string &p2rank,
                              const std::string &p1suit,
                              const std::string &p2suit)
{
    std::cout << "Turn " << turn << ":\n"
              << "Player 1 reveals: " << p1rank << " of " << p1suit << std::endl
              << "Player 2 reveals: " << p2rank << " of " << p2suit << std::endl;
    switch (outcome)
    {
    // Player1 wins the turn
    case 'O':
        std::cout << "Player 1 wins the hand!\n";
        break;
    // Player2 wins the turn
    case 'T':
        std::cout << "Player 2 wins the hand!\n";
        break;
    // WAR
    case 'W':
        std::cout << "War!\n";
        break;
    }
}
