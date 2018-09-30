//
// Created by Devon on 9/29/2018.
//

#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main () {
    // create the deck (already shuffled) and new players
    Deck deck;
    Player user(deck);
    for (int i = 0; i < 7; ++i) {
        deck.removeTopCard();
    }

    Player computer(deck);
    for (int i = 0; i < 7; ++i) {
        deck.removeTopCard();
    }

    // main menu
    cout << endl;
    cout << "Welcome to Go Fish!" << endl;
    cout << "Please choose a difficulty to play on" << endl;
    cout << endl;
    cout << "E = Easy, H = Hard" << endl;
    string difficulty;
    cin >> difficulty;
    while (difficulty != "E" && difficulty != "e" && difficulty != "H" && difficulty != "e") {
        cout << endl;
        cout << "Difficulty not found, please try again!" << endl;
        cout << "E = Easy, H = Hard" << endl;
        cin >> difficulty;
    }

    // main game loop
    while (user.getHand().size() > 0 || computer.getHand().size() > 0 || deck.getDeck().size() > 0) {
        // differentiate between easy and hard difficulty (easy = no memory/lying, hard = memory/lying)
        if (difficulty == "E" || difficulty == "e") {
            // always check to see if user or computer has a book to start
            for (int i = 0; i < user.getHand().size(); ++i) {
                // if there is a book add point and remove cards

            }
            for (int i = 0; i < computer.getHand().size(); ++i) {
                // if there is a book add point and remove cards

            }

            // print out hand and points
            cout << "Score (you vs. comp): " << user.getPoints() << " - " << computer.getPoints() << endl;
            cout << "Your Hand: " << endl;
            user.printHand();
            cout << endl;
            cout << "Comptuer's Hand: " << endl;
            computer.printHand();
            cout << endl;

            // ask for user's choice
            cout << "A = Ask, Q = Quit" << endl;
            string choice;
            cin >> choice;
            while (choice != "A" && choice != "a" && choice != "Q" && choice != "q") {
                cout << endl;
                cout << "Option not found, please try again!" << endl;
                cout << "A = Ask, Q = Quit" << endl;
                cin >> choice;
            }

            // ask for choices
            if (choice == "A" || choice == "a") {
                cout << "What are you looking for? (1 = Ace, 2-10, 11 = Jack, 12 = Queen, 13 = King" << endl;
                int guess;
                cin >> guess;
                while (guess < 1 || guess > 13) {
                    cout << endl;
                    cout << "Non existent card, please try again!" << endl;
                    cout << "1 = Ace" << endl;
                    cout << "2-10 = Normal Cards" << endl;
                    cout << "11 = Jack" << endl;
                    cout << "12 = Queen" << endl;
                    cout << "13 = King" << endl;
                    cin >> guess;
                }

                // run through computer's hand to see if they have any of those cards
                vector<Card> cardsWithThatRank;
                vector<int> indexWhereCardsAre;
                bool compHasCard = false;
                for (int i = 0; i < computer.getHand().size(); ++i) {
                    if (computer.getHand()[i].getRank() == guess) {
                        cardsWithThatRank.push_back(computer.getHand()[i]);
                        indexWhereCardsAre.push_back(i);
                        compHasCard = true;
                    }
                }

                if (compHasCard) {
                    cout << "Computer has " << cardsWithThatRank.size() << " of those card(s)" << endl;
                    cout << "They have now been added to your hand" << endl;

                    // push back all cards with that rank
                    for (int i = 0; i < cardsWithThatRank.size(); ++i) {
                        user.addCard(cardsWithThatRank[i]);
                    }
                    // also remove card(s) from the computer's hand
                    int iterations = 0;
                    for (int j = 0; j < indexWhereCardsAre.size(); ++j) {
                        if (iterations == 0) {
                            computer.removeCard(indexWhereCardsAre[j]);
                            ++iterations;
                        } else {
                            computer.removeCard(indexWhereCardsAre[j]-1);
                        }
                    }
                    // clear the two vectors necessary above
                    cardsWithThatRank.clear();
                    indexWhereCardsAre.clear();
                } else {
                    cout << "Go Fish!" << endl;
                    // push back top card, and remove from deck
                    user.getHand().push_back(deck.getDeck()[0]);
                    deck.removeTopCard();
                }
            } else {
                    cout << "Bye!" << endl;
                    return 0;
                }


        } else if (difficulty == "H" || difficulty == "h") {

        }
    }

    // write to console who won
    if (user.getHand().size() == 0) {
        cout << "Congratulations you won!" << endl;
        cout << "Score: " << user.getPoints() << " - " << computer.getPoints() << endl;
    } else if (computer.getHand().size() == 0) {
        cout << "Unfortunately you lost" << endl;
        cout << "Score: " << user.getPoints() << " - " << computer.getPoints() << endl;
    } else {
        if (user.getPoints() > computer.getPoints()) {
            cout << "Congratulations you won!" << endl;
            cout << "Score: " << user.getPoints() << " - " << computer.getPoints() << endl;
        } else {
            cout << "Unfortunately you lost" << endl;
            cout << "Score: " << user.getPoints() << " - " << computer.getPoints() << endl;
        }
    }

    return 0;
}