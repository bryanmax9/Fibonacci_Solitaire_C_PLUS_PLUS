// Bryan Tineo Ccasani
// Class (CECS 325-01)
// Prog 1
// Due Date 09/18/2023
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.
#include <iostream>
#include "Deck.h"
#include <cstdlib>
#include <ctime>
#include <algorithm> // For std::swap

Deck::Deck() {
    newDeck();
}

void Deck::newDeck() {
    cards.clear();

    for (int s = SPADES; s <= CLUBS; s++) {
        for (int r = ACE; r <= KING; r++) {
            cards.push_back(Card(static_cast<Rank>(r), static_cast<Suit>(s)));
        }
    }
}

Card Deck::deal() {
    if (isEmpty()) {
        return Card(); // Return Joker if deck is empty.
    }

    Card topCard = cards.back();
    cards.pop_back();
    return topCard;
}

void Deck::shuffle() {
    // Ensure srand(time(NULL)) is initialized in the main function for randomness.
    for (int i = cards.size() - 1; i > 0; i--) {
        int swap_index = rand() % (i + 1);
        std::swap(cards[i], cards[swap_index]);
    }
}

bool Deck::isEmpty() {
    return cards.empty();
}

void Deck::show() {
    for (size_t i = 0; i < cards.size(); i++) {
        cards[i].show();
        
        if ((i + 1) % 13 == 0) {
            std::cout << '\n'; 
        }
    }
}
