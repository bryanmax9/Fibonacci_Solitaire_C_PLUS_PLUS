// Bryan Tineo Ccasani
// Class (CECS 325-01)
// Prog 1
// Due Date 09/18/2023
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>

class Deck {
private:
    std::vector<Card> cards; // Container to store all the cards.

public:
    // Default constructor: Initializes a standard deck of cards.
    Deck();

    // Resets the deck to a standard deck of 52 cards.
    void newDeck();

    // Deals the top card from the deck.
    Card deal();

    // Shuffles the cards in the deck.
    void shuffle();

    // Checks if the deck is empty.
    bool isEmpty();

    // Displays all the cards in the deck to the console.
    void show();
};

#endif // DECK_H
