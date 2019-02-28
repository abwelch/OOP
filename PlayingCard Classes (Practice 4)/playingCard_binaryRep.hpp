// Card class that creates card objects with values assigned by utilizing enums
#ifndef PLAYINGCARD_BINARYREP_HPP
#define PLAYINGCARD_BINARYREP_HPP
#include <string>

enum Rank
{
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
};
enum Suit
{
    SPADE,
    CLUB,
    HEART,
    DIAMOND
};
// Utilized for joker cards
enum Color
{
    RED,
    BLACK
};
class playingCard_binaryRep
{
  private:
    unsigned char data;

  public:
    // Constructor for standard playing cards
    playingCard_binaryRep(Rank r, Suit s)
        : data(static_cast<unsigned>(s) << 4 | static_cast<unsigned>(r)) {}

    playingCard_binaryRep(Color c) : data(0b1000000 | static_cast<unsigned>(c)) {}
    // Accessors
    const Rank getRank();
    const Suit getSuit();
    const Color getColor();
    std::string rankToString();
    std::string suitToString();
    std::string colorToString();
    // Joker flag
    bool isJoker();
};
#endif