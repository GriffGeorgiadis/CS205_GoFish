//
// Created by Devon on 9/23/2018.
//

#include "Card.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<Card>Deck;
    vector<Card>playerHand;
    vector<Card>computerHand;

    Card s(1,spades);
    Card d(1,diamonds);
    Card c(1,clubs);
    Card h(1,spades);

    for (int i = 1; i <= 13 ; ++i) {
        s.setRank(i);
        d.setRank(i);
        c.setRank(i);
        h.setRank(i);
        s.setSuit(spades);
        d.setSuit(diamonds);
        c.setSuit(clubs);
        h.setSuit(hearts);
        Deck.push_back(s);
        Deck.push_back(d);
        Deck.push_back(c);
        Deck.push_back(h);
    }

    int deckSize = Deck.size();
    int cardNum;
    int compLie;

    for (int j = 0; j < 7; ++j) {
        cardNum = rand() % (deckSize-1);
        playerHand.push_back(Deck[cardNum]);
        deckSize = deckSize - 1;
        Deck.erase(Deck.begin()+cardNum);
        cardNum = rand() % (deckSize-1);
        computerHand.push_back(Deck[cardNum]);
        deckSize = deckSize - 1;
        Deck.erase(Deck.begin()+cardNum);
    }

    cout <<"Select an honesty level for your opponent 1-100:" << endl;
    cin >> compLie;
    while (compLie > 100 || compLie < 0){
        cout << "Please enter a value from 1-100:" << endl;
        cin >> compLie;
    }


    cout << "Player Hand: " << endl;
    for (int k = 0; k < playerHand.size(); ++k) {
        cout << playerHand[k].toString() << endl;
    }
    cout << endl;
    cout << "Computer Hand: " << endl;
    for (int k = 0; k < computerHand.size(); ++k) {
        cout << computerHand[k].toString() << endl;
    }
    cout << endl;
    cout << "Deck: " << endl;
    for (int l = 0; l < Deck.size(); ++l) {
        cout << Deck[l].toString() << endl;
    }
    
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

    //Main game loop
    Card ask(1, hearts); //temp card
    bool hasCard;
    bool playerTurn;
    bool compTurn;
    while(playerHand.size() != 0 || computerHand.size()!= 0 || deckSize != 0){
       //loop for players turn
        playerTurn = true;

        while(playerTurn) {
            //show players hand
            cout << "Player's Hand:" << endl;
            for(Card playerCard : playerHand) {
                cout << playerCard.toString() << endl;
            }
            int playerAsk;
            cout << "Enter the rank of the card you would like to ask for: " << endl;
            cin >> playerAsk;
            //make sure the player has the card


            //player asks
            cout << "Do you have any " << playerAsk << "'s?" << endl;

            //make sure its in players hand
            //check if computer has it
            for (int i = 0; i < computerHand.size(); ++i) {
                if (computerHand[i].getRank() == ask.getRank()) {
                    hasCard = true;
                } else {
                    playerTurn = false;
                }
            }
            //decide if computer will lie
            //pick random number 0-100
            int pick = rand() % 100 +1;
            if (pick > compLie) {
                cout << "Go fish!" << endl;
                hasCard = false;
            }
            if (hasCard) {
                cout << "Yes, here they are." << endl;
                playerHand.push_back(ask);
                //delete from comp hand
            }

            //check for book
            for (int i = 0; i < playerHand.size(); ++i) {
                //look for 4 of a kind

            }
            //pick up if computer doesnt have
            Card pickUp = Deck[0];
            if (!hasCard) {
                playerHand.push_back(pickUp);
                //delete from deck
            }
            //check if the card picked up is the card asked for
            if (pickUp.getRank() == ask.getRank()) {
                cout << "Picked up the right card. Player turn continues." << endl;
                playerTurn = true;

            }
        }

//   ========================= start comp turn =================================

        compTurn = true;
        while (compTurn) {
            //computer asks
            int compAsk = rand() % computerHand.size();
            ask = computerHand[compAsk];
            cout << "Do you have any " << ask.getRank() << "'s?" << endl;

            //check if player has
            //ask player (let them lie)
            bool willLie = false;
            for (int i = 0; i < playerHand.size(); ++i) {
                if (playerHand[i].getRank() == ask.getRank()) {
                    cout << "Would you like to lie? Y or N: " << endl;
                    string lie;
                    cin >> lie;
                    while (lie != "Y" || lie != "y" || lie != "N" || lie != "n"){
                        cout << "Please enter Y or N: " << endl;
                        cin >> lie;
                    }
                    if (lie == "y" || lie == "Y"){
                        cout << "Go fish!" << endl;
                        willLie = true;
                        hasCard = false;
                    }else{
                        cout << "Yes, here they are." << endl;
                        hasCard = true;
                    }
                } else {
                    compTurn = false;
                }
            }

            //decide if computer will call out lie
            // pick random number 0-100
            if(hasCard && willLie){
                int pick = rand() % 100 +1;

                if (pick > compLie) {
                    cout << "You are lying!" << endl;
                    hasCard = true;
                }
            }

            if (hasCard) {
                computerHand.push_back(ask);
                //delete from player hand
            }

            //check for book
            for (int i = 0; i < computerHand.size(); ++i) {
                //look for 4 of a kind

            }
            //pick up if computer doesnt have
            Card pickUp = Deck[0];
            if (!hasCard) {
                computerHand.push_back(pickUp);
                //delete from deck
            }
            //check if the card picked up is the card asked for
            if (pickUp.getRank() == ask.getRank()) {
                cout << "Picked up the right card. Computer turn continues." << endl;
                compTurn = true;

            }

        }
    }

    outFile.close();

    return 0;
}