//
// Created by Devon on 9/23/2018.
//

#include "Card.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

int main() {
    // all of this can be in the game loop
    // so every turn will record player's guesses
    // and their hands of cards
    ofstream outFile = "Game Record.txt";

    if(outFile) {
        // output player's hand
        for(Card playerCard : playerHand) {
            outFile << "Player's Hand:" << endl;
            outFile << playerCard.toString() << endl;
        }
        // output computer's hand
        for(Card computerCard : computerHand) {
            outFile << "Computer's Hand:" << endl;
            outFile << computerCard.toString() << endl;
        }
        // output player's guess
        outFile << "Player's Guess: " << playerGuess << endl;
        // output computer's guess
        outFile << "Computer's Guess: " << computerGuess << endl;
    }

    outFile.close();

    return 0;
}