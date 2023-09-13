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

//In order to prevent user from inputting the wrong input, we will use limits in order to stop the error and ask again the user for an input
#include <limits>

//functions that I'll be crating
Deck createNewDeck();
void displayDeck(Deck& deck);
void shuffleDeck(Deck& deck);
bool playFiboSolitaire(Deck& deck, int gamesPlayed);
bool winFiboSolitaire(Deck& deck, int gamesPlayed);

//main function
int main() {

	
	int userNumberChoice; 
	Deck currentDeck; // stor the deck of the user
	bool playing = true;
	bool win = false;
	int gamesPlayed = 0;



	do{
		std::cout << "🎮♣️Welcome to Fibonacci Solitaire!♠️🎮" << '\n';
		win = false;
		do{
			std::cout << "1) Create New Deck" << '\n';
			std::cout << "2) Display Deck" << '\n';
			std::cout << "3) Shuffle Deck" << '\n';
			std::cout << "4) Play Fibo Solitaire" << '\n';
			std::cout << "5) Win Fibo Solitaire" << '\n';
			std::cout << "6) Exit" << '\n';
	
	
			std::cout << "\nEnter your number Choice";
			std::cin >> userNumberChoice;
		
			std::cout << '\n';
	
			//heck if the input is not an int, if not then clear the error and set the choice user value to 0
			if (std::cin.fail()) {
				std::cin.clear(); // clear the error state
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
				userNumberChoice = 0; // reset to an invalid choice
			}

		} while( userNumberChoice < 1 || userNumberChoice > 6 );
	
		if ( userNumberChoice == 1){
			currentDeck = createNewDeck();
		}
		else if(userNumberChoice ==2){
			displayDeck(currentDeck);
		}
		else if(userNumberChoice == 3){
			shuffleDeck(currentDeck);
		}
		else if(userNumberChoice == 4){
			win = playFiboSolitaire(currentDeck,gamesPlayed);
			gamesPlayed += 1;
		}
		else if(userNumberChoice == 5){
			do{
				win = winFiboSolitaire(currentDeck,gamesPlayed);
				gamesPlayed += 1;
			}while(win == false);

		}
		else if(userNumberChoice == 6){
			playing = false;
			break;
		}	


	} while(playing);

	std::cout << "👻 Thanks for Playing Fibo Solitaire! 🃏🎮"




	return 0;
}


Deck createNewDeck(){
	
	std::cout << "Deck was created Succesfully! 👌" << '\n';
	return Deck();
}

void displayDeck(Deck& deck){
	deck.show();

}
void shuffleDeck(Deck& deck){
	deck.shuffle();

	std::cout << "Deck was Shuffled! 👻" << '\n';
}
bool playFiboSolitaire(Deck& deck, int gamesPlayed){
	//Start the game
	std::cout << "Playing Fibonacci Solitaire !!! 🎮" << '\n';
}
bool winFiboSolitaire(Deck& deck, int gamesPlayed){
	//Play until you win(this will execute as long as you didnt won the last match)
	std::cout << "Playing Fibonacci Solitaire !!! 🎮" << '\n';
}


