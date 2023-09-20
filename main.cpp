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
bool playFiboSolitaire(Deck& deck, int& gamesPlayed, bool deckExists);
bool winFiboSolitaire(Deck& deck, int& gamesPlayed, bool deckExists);
bool isFibonacci(int n);

//main function
int main() {
	//We will say to the program that later we will be suing random number for shuffling(this is only done once in order to get better results)
	srand(time(NULL));

	//variable for cheking if Deck was created
	bool deckExists = false;

	int userNumberChoice; 
	Deck currentDeck; // stor the deck of the user
	bool playing = true;
	bool win = false;
	int gamesPlayed = 0;



	do{
		std::cout << "\n";
		std::cout << "🎮♣️Welcome to Fibonacci Solitaire!♠️🎮" << '\n';
		win = false;
		do{
			std::cout << "1) Create New Deck" << '\n';
			std::cout << "2) Display Deck" << '\n';
			std::cout << "3) Shuffle Deck" << '\n';
			std::cout << "4) Play Fibo Solitaire" << '\n';
			std::cout << "5) Win Fibo Solitaire" << '\n';
			std::cout << "6) Exit" << '\n';
	
	
			std::cout << "\nEnter your number Choice: ";
			std::cin >> userNumberChoice;
		
			std::cout << '\n';
	
			//Check if the input is not an int, if not then clear the error and set the choice user value to 0
			if (std::cin.fail()) {
				std::cin.clear(); // clear the error state
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
				userNumberChoice = 0; // reset to an invalid choice
			}

		} while( userNumberChoice < 1 || userNumberChoice > 6 );
	
		if ( userNumberChoice == 1){
			currentDeck = createNewDeck();
			deckExists = true;
		}
		else if(userNumberChoice ==2){
			if(deckExists) {
				displayDeck(currentDeck);
			} else {
				std::cout << "Please create a deck first! 😤😡🤬" << std::endl;
			}
			
		}
		else if(userNumberChoice == 3){
			if(deckExists) {
				shuffleDeck(currentDeck);
			} else {
				std::cout << "Please create a deck first! 😤😡🤬" << std::endl;
			}
		}
		else if(userNumberChoice == 4){
			if(deckExists) {
				win = playFiboSolitaire(currentDeck,gamesPlayed,deckExists);
				gamesPlayed += 1;
			} else {
				std::cout << "Please create a deck first! 😤😡🤬" << std::endl;
			}

			//Since we finished plating. We will need a new deck the next time we chose an option
			deckExists = false;
			
		}
		else if(userNumberChoice == 5){
			if(deckExists) {
				do{
					win = winFiboSolitaire(currentDeck,gamesPlayed,deckExists);
					gamesPlayed += 1;
				}while(win == false);
			} else {
				std::cout << "Please create a deck first! 😤😡🤬" << std::endl;
			}
			//Since we finished plating. We will need a new deck the next time we chose an option
			//Still we will always win here and the loop of the playing will be done in the function winfibo itself
			deckExists = false;
			

		}
		else if(userNumberChoice == 6){
			playing = false;
			
		}	


	} while(playing);

	std::cout << "👻 Thanks for Playing Fibo Solitaire! 🃏🎮" << '\n';




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
bool playFiboSolitaire(Deck& deck, int& gamesPlayed, bool deckExists) {
    std::cout << "\nPlaying Fibonacci Solitaire! 🎮 \n";

    if(!deckExists) {
        std::cout << "Please create a deck first!" << std::endl;
        return false;
    }

    std::vector<Card> pile;
    std::vector<std::vector<Card>> allPiles;
    int currentSum = 0;
    bool won = false;

    while(!deck.isEmpty()) {
        Card card = deck.deal();
        int cardValue = card.getValue();

        currentSum += cardValue;
        pile.push_back(card);
        
        if(isFibonacci(currentSum)) {
            allPiles.push_back(pile);
            pile.clear();
            currentSum = 0;
        } 
        else if(deck.isEmpty() && isFibonacci(cardValue)) {
            allPiles.push_back({card});
            won = true;
            break;
        }
    }

    if(!pile.empty()) {
        allPiles.push_back(pile); // Push the remaining cards as a pile.
    }

    if(deck.isEmpty() && isFibonacci(currentSum)) {
        won = true;
    }

    gamesPlayed++;

    // Display all piles.
    for(const auto& currentPile : allPiles) {
			int pileSum = 0;
			for (const Card& constCard : currentPile) {
				Card card = constCard;  // create a non-const copy
				card.show();
				pileSum += card.getValue();
			}
			std::cout << " Fibo:" << pileSum;
			std::cout << "\n";
		}



    if(won) {
        std::cout << "Winner! 👀" << std::endl;
    } else {
        std::cout << "Loser! 👻" << std::endl;
    }

    std::cout << "Games Played: " << gamesPlayed << std::endl;
    return won;
}

bool winFiboSolitaire(Deck& deck, int& gamesPlayed, bool deckExists) {
    if(!deckExists) {
        std::cout << "Please create a deck first!" << std::endl;
        return false;
    }

    bool won = false;

    while(!won) {
        std::cout << "\nPlaying Fibonacci Solitaire Until we WIN!!! 🎮😎\n";
       
        deck = createNewDeck();
        deck.shuffle();
        won = playFiboSolitaire(deck, gamesPlayed, true);

        if(!won) {
            std::cout << "Reshuffled your deck to try for a win! 🔀\n";
        }
    }

    return true;
}



bool isFibonacci(int n) {
  // Initialize the first two Fibonacci numbers: 0 and 1.
  int a = 0, b = 1;
    
  // Compute the next Fibonacci number, which is the sum of the previous two.
  int c = a + b;

  // Keep computing Fibonacci numbers until they exceed or equal to the given number 'n'.
  while (c <= n) {
		// If the computed Fibonacci number equals the given number 'n', it means 'n' is a Fibonacci number.
    if (c == n) {
      return true;
    }
        
    // Move one step forward in the Fibonacci sequence.
    a = b;      // Now, 'a' will become the next previous number.
    b = c;      // 'b' takes the value of 'c'.
    c = a + b;  // Compute the next Fibonacci number.
  }

  // If we exit the loop without returning true, then 'n' is not a Fibonacci number.
  return false;
}



