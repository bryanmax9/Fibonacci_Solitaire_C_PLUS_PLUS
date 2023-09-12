// Bryan Tineo Ccasani
// Class (CECS 325-01)
// Prog 1
// Due Date 09/18/2023
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.



#include <iostream>
//import the header file
#include "Card.h"

//constructor for jocker (when thet dont give any parameters when creating the Card object)
Card::Card() : suit(NO_SUIT), rank(JOKER) {}

//Create a card according to parameters given
Card::Card(Rank r, Suit s) : rank(r), suit(s){}

//Now we will create the functions for the class
int Card::getValue(){
	if (rank == ACE) return 1;
	//the static_cast<int> will convert the value from the enum of rank into an integer.
	if (rank >= TWO && rank <= TEN) return static_cast<int>(rank) + 1;
	if (rank == JACK ) return 11;
	if (rank == QUEEN ) return 12;
	if (rank == KING ) return 13;
	if(rank == JOKER) return 0;
	return 0; // this is just to justify the compiler,but this line shouldnt never be reached
}

void Card::show{
	//using pointer in order to treat the character as a string
	const char *suitSymbols[] = {"♠", "♥", "♦", "♣", "🤡"};

	//same for the rank names
	const char *rankNames[] = {"A","2","3","4","5","6","7","8","9","10","J", "Q","K","XX"};
	
	//Display the card
	std::cout << rankNames[rank] << suitSymbols[suit] << " ";
}


