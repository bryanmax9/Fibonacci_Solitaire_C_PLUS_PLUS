// Bryan Tineo Ccasani
// Class (CECS 325-01)
// Prog 1
// Due Date 09/18/2023
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

//Avoiding multiple intances of this header 
#ifndef DECK_H
#define DECK_H

//importing the card class header in order to use it here
#include "Card.h"
//As said by Professor Gold, we will be storing all the cards in vector arrays
#include <vector>

class Deck {
	private:
		std::vector<Card> cards;
	
	public:
		//constructor of the class
		Deck();

		//functions of the class
		void newDeck();
		Card deal();
		void shuffle();
		bool isEmpty();
		void show();
	
};

#endif //DECK_H
