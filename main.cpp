// Bryan Tineo Ccasani
// Class (CECS 325-01)
// Prog 1
// Due Date 09/18/2023
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.


#include <iostream>

//We will first immport the deck class
#include "Deck.h"

int main() {
    Deck deck;
    deck.shuffle();
    deck.show();
    std::cout << "\n\nDealing some cards...\n";
    for (int i = 0; i < 5; i++) {
        Card c = deck.deal();
        c.show();
        std::cout << std::endl;
    }
    std::cout << "\nRemaining cards in deck:\n";
    deck.show();

    return 0;
}

