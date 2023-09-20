// Bryan Tineo Ccasani
// Class (CECS 325-01)
// Prog 1
// Due Date 09/18/2023
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#ifndef CARD_H
#define CARD_H

// Enum representing the various suits of a card.
enum Suit {
    SPADES,
    HEARTS,
    DIAMONDS,
    CLUBS,
    NO_SUIT // Represents cards like Joker which don't have a traditional suit.
};

// Enum representing the various ranks of a card.
enum Rank {
    ACE,
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
    JOKER // Represents a Joker card.
};

// Class representing a playing card.
class Card {
private:
    Suit suit; // The suit of the card.
    Rank rank; // The rank of the card.

public:
    // Default constructor: Represents a Joker card.
    Card();

    // Constructor: Initializes a card with a given rank and suit.
    Card(Rank r, Suit s);

    // Returns the value of the card.
    int getValue();

    // Displays the card to the console.
    void show();
};

#endif // for CARD_H

