// Bryan Tineo Ccasani
// Class (CECS 325-01)
// Prog 1
// Due Date 09/18/2023
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

//importing the Deck Header
#include "Deck.h"

//This are going to be used for the random number generator
#include <cstdlib>
#include <ctime>

//Contructor of the class that will initialize the deck of cards
Deck::Deck() {
	newDeck();
}

void Deck::newDeck(){
	//We will first remove ny Cards stored in the vector array (ensures vector is empty)
	cards.clear();

	//outer loop going through each suit
	for (int s = SPADES; s <= CLUBS;s++){
		//inner loop goes through each rank for a given suit
		for (int r = ACE; r <= KING; r++){
			cards.push_back(Card(static_cast<Rank>(r), static_cast<Suit>(s)));

		}
	}

}

//Giving out a card from the deck to the user
Card Deck::deal(){
	if(isEmpty()){
		return Card(); //return Joker if deck is empty
	}

	//get top card
	Card topCard = cards.back();
	
	//card off the deck
	cards.pop_back();

	//return the top card to the user
	return topCard;
}


//The shuffle I guided myself from this video:
//Link: https://www.youtube.com/watch?v=7OIZ_W75lAM
void Deck::shuffle(){
	//srand(time(NULL)); <-- Do this in the main function in order to not return the same value
	for (int i = 0;i < cards.size();i++){
		int swap_index = rand() % cards.size(); //a value between 0 and the cards size - 1
		Card temp = cards[i];
		cards[i] = cards[swap_index];
		cards[swap_index] = temp;
	}
}

bool Deck::isEmpty(){
	return cards.empty;
}

void Deck::show(){
	//showing the cards in 13 columns and 4 rows
	//size_t representing non negative values. Also is used when using std::vector::size()
	for(size_t i = 0; i < cards.size(); i++ ){
		cards[i].show();
		
		//New row after every 13 cards
		if((i+1)%13 == 0){
			std::cout << '\n'; 
		}
	}
}



