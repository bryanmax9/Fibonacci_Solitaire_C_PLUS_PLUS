// Bryan Tineo Ccasani
// Class (CECS 325-01)
// Prog 1
// Due Date 09/18/2023
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.


//These preprocessors will allow us to avoid double inclusion(Only for one .cpp file to use this header and not multiple files)

//This creates the CARD_H when the Card class use it
#ifndef CARD_H
//This next line will ensure that since we already created the CARD_H then we will not do that for another file
#define CARD_H

//user defined data types categories (we will use the number index position)
enum Suit {
	SPADES,
	HEARTS,
	DIAMONDS,
	CLUBS,
	NO_SUIT
};

//same for the Rank
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
	JOKER
};

//On this header file we will specify all functions that the class will perform and the variables that will store
class Card {
	private:
		Suit suit;
		Rank rank;
	public:
		//defining the contructors
		//This one for the joker card
		Card();

		//create specific cards if given parameter
		Card(Rank r,Suit s);

		//functions inside the class
		int getValue();
		void show();


};

#endif //for CARD_HCard();

