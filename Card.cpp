// Bryan Tineo Ccasani
// Class (CECS 325-01)
// Prog 1
// Due Date 09/18/2023
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include "Card.h"

//constructor for joker (when they don't give any parameters when creating the Card object)
Card::Card() : suit(NO_SUIT), rank(JOKER) {}

//Create a card according to parameters given
Card::Card(Rank r, Suit s) : rank(r), suit(s) {}

// Now we will create the functions for the class
int Card::getValue() {
    if (rank == ACE) return 1;
    if (rank >= TWO && rank <= TEN) return static_cast<int>(rank) + 1;
    if (rank == JACK) return 11;
    if (rank == QUEEN) return 12;
    if (rank == KING) return 13;
    if(rank == JOKER) return 0;
    return 0; // this is just to satisfy the compiler, but this line shouldn't ever be reached
}

void Card::show() {
    // using pointer in order to treat the character as a string
    const char *suitSymbols[] = {"♠", "♥", "♦", "♣", "🃏"};

    // same for the rank names
    const char *rankNames[] = {"A","2","3","4","5","6","7","8","9","10","J", "Q","K","XX"};

    if (rank < ACE || rank > JOKER || suit < SPADES || suit > NO_SUIT) {
        std::cout << "Invalid card" << std::endl;
        return;
    }

    // Display the card
    std::cout << rankNames[rank] << suitSymbols[suit] << " ";
}


