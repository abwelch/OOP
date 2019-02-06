#include "deck.hpp"
#include "card.hpp"

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

// Utilizes shuffle on full deck and then distributes to player vectors
void deck::distributeDeck(std::vector<card> &fullDeck)
{
    auto rng = std::default_random_engine{};
    std::shuffle(std::begin(fullDeck), std::end(fullDeck), rng);
    // Distribute first half of shuffled deck to p1 vector and second half to p2
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
}

// Initiates the game
void deck::battle()
{
    short p1score = 0, p2score = 0, turn = 1;
    char outcome;
    int p1position = 0, p2position = 0;
    // Game will continue until one player runs out of cards
    while (!(p1.empty()) && !(p2.empty()))
    {
        if (p1[p1position].getRank() > p2[p2position].getRank())
        {
            ++p1score;
            outcome = 'O';
            displayTurnOutcome(
                p1[p1position].rankToString(), p2[p2position].rankToString(),
                p1[p1position].suitToString(), p2[p2position].suitToString(), p1score,
                p2score, turn, outcome);
            // Add p2's card to buttom of p1 deck
            p1.push_back(p2[p2position]);
            p2.erase(p2.begin() + p2position);
        }
        else if (p1[p1position].getRank() < p2[p2position].getRank())
        {
            ++p2score;
            outcome = 'T';
            displayTurnOutcome(
                p1[p1position].rankToString(), p2[p2position].rankToString(),
                p1[p1position].suitToString(), p2[p2position].suitToString(), p1score,
                p2score, turn, outcome);
            p2.push_back(p1[p1position]);
            p1.erase(p1.begin() + p1position);
        }
        else
        {
            war(p1position, p2position);
        }
        ++turn;
    }
    displayWinner(p1score, p2score);
}

// Used to display all information about cards played during a hand, who won,
// and what turn it is
void deck::displayTurnOutcome(const std::string &p1rank,
                              const std::string &p2rank,
                              const std::string &p1suit,
                              const std::string &p2suit, short p1score,
                              short p2score, short turn, char outcome)
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

// Function with recursive use intent for successive wars
void deck::war(int p1position, int p2position)
{
    if (p1.size() == 1 || p2.size() == 1)
    {
        return;
    }
    ++p1position;
    ++p2position;
    if (p1[p1position].getRank() > p2[p2position].getRank())
    {
        p1.push_back(p2[p2position]);
        p2.erase(p2.begin() + p2position);
    }
    else if (p1[p1position].getRank() < p2[p2position].getRank())
    {
        p2.push_back(p1[p1position]);
        p1.erase(p1.begin() + p1position);
    }
    else
    {
        war(p1position, p2position);
    }
}

// display winner based on which vector is empty
void deck::displayWinner(int p1score, int p2score)
{
    if (p2score > p1score)
    {
        std::cout << "Player 2 has won the game!\n";
    }
    else
    {
        std::cout << "Player 1 has won the game!\n";
    }
}