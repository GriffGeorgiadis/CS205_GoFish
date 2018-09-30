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
#include <random>
#include <ctime>
using namespace std;

int main () {
    // useful for random number generation by computer
    srand(time(NULL));

    // create the deck (already shuffled), add new players and create outfile
    Deck deck;
    Player user(deck);
    for (int i = 0; i < 7; ++i) {
        deck.removeTopCard();
    }
    Player computer(deck);
    for (int i = 0; i < 7; ++i) {
        deck.removeTopCard();
    }
    ofstream outFile("Game Record.txt");

    // main menu
    user.setTurn(true);
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
    while (user.getHand().size() != 0 && computer.getHand().size() != 0 && deck.getDeck().size() != 0) {
        // differentiate between easy and hard difficulty (easy = no memory/lying, hard = memory/lying)
        if (difficulty == "E" || difficulty == "e") {
            if (user.checkBook()) {
                cout << "You have a book! +1 points" << endl;
                user.addPoint();
            }
            if (computer.checkBook()) {
                cout << "Computer has a book! +1 points" << endl;
                computer.addPoint();
            }

            // print out hand and points
            cout << "============================" << endl;
            cout << "Score (you vs. comp): " << user.getPoints() << " - " << computer.getPoints() << endl;
            cout << "============================" << endl;
            cout << "Your Hand: " << endl;
            cout << "==========" << endl;
            user.printHand();
            cout << endl;

            if (user.getTurn() == true && computer.getTurn() == false) {
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
                    cout << "What are you looking for? (1 = Ace, 2-10, 11 = Jack, 12 = Queen, 13 = King)" << endl;
                    int guess;
                    cin >> guess;
                    while (guess < 1 || guess > 13) {
                        cout << endl;
                        cout << "Non existent card, please try again!" << endl;
                        cout << "What are you looking for? (1 = Ace, 2-10, 11 = Jack, 12 = Queen, 13 = King)" << endl;
                        cin >> guess;
                    }

                    // output file
                    if(outFile) {
                        // output player's hand
                        outFile << "==============" << endl;
                        outFile << "Player's Hand:" << endl;
                        outFile << "==============" << endl;
                        for(Card playerCard : user.getHand()) {
                            outFile << playerCard.toString() << endl;
                        }
                        // output player's guess
                        outFile << "====================" << endl;
                        outFile << "Player's Guess Rank: " << guess << endl;
                        outFile << "====================" << endl;
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
                                computer.removeCard(indexWhereCardsAre[j] - 1);
                            }
                        }
                        // clear the two vectors necessary above
                        cardsWithThatRank.clear();
                        indexWhereCardsAre.clear();
                    } else {
                        cout << "Go Fish!" << endl << endl;
                        if (deck.getDeck()[0].getRank() == guess) {
                            user.addCard(deck.getDeck()[0]);
                            deck.removeTopCard();
                            cout << "Found card you were looking for, go again!" << endl;
                        } else {
                            cout << "You picked up " << deck.getDeck()[0].toString() << endl << endl;
                            user.addCard(deck.getDeck()[0]);
                            deck.removeTopCard();
                            user.setTurn(false);
                            computer.setTurn(true);
                        }
                    }
                } else {
                    cout << "Bye!" << endl;
                    return 0;
                }

            } else if (computer.getTurn() == true && user.getTurn() == false) {
                // pick a random card rank for computer
                int randomRank = rand() % 13 + 1;

                // output file
                if(outFile) {
                    // output computer's hand
                    outFile << "================" << endl;
                    outFile << "Computer's Hand:" << endl;
                    outFile << "================" << endl;
                    for(Card computerCard : computer.getHand()) {
                        outFile << computerCard.toString() << endl;
                    }
                    // output computer's guess
                    outFile << "======================" << endl;
                    outFile << "Computer's Guess Rank: " << randomRank << endl;
                    outFile << "======================" << endl;
                }

                // run through user's hand to see if they have any of those cards
                vector<Card> cardsWithThatRank;
                vector<int> indexWhereCardsAre;
                bool userHasCard = false;
                for (int i = 0; i < user.getHand().size(); ++i) {
                    if (user.getHand()[i].getRank() == randomRank) {
                        cardsWithThatRank.push_back(user.getHand()[i]);
                        indexWhereCardsAre.push_back(i);
                        userHasCard = true;
                    }
                }

                if (userHasCard) {
                    cout << "Computer guesses for card rank of " << randomRank << endl;
                    cout << "You have " << cardsWithThatRank.size() << " of those cards" << endl;
                    cout << "They have been added to computer's hand, and taken from yours" << endl << endl;

                    // push back all cards with that rank
                    for (int i = 0; i < cardsWithThatRank.size(); ++i) {
                        computer.addCard(cardsWithThatRank[i]);
                    }
                    // also remove card(s) from the computer's hand
                    int iterations = 0;
                    for (int j = 0; j < indexWhereCardsAre.size(); ++j) {
                        if (iterations == 0) {
                            user.removeCard(indexWhereCardsAre[j]);
                            ++iterations;
                        } else {
                            user.removeCard(indexWhereCardsAre[j] - 1);
                        }
                    }
                    // clear the two vectors necessary above
                    cardsWithThatRank.clear();
                    indexWhereCardsAre.clear();
                } else {
                    cout << "Computer guessed card of rank " << randomRank << endl;
                    cout << "* computer went go fish *" << endl;
                    if (deck.getDeck()[0].getRank() == randomRank) {
                        computer.addCard(deck.getDeck()[0]);
                        deck.removeTopCard();
                        cout << "Computer found card they were looking for, they go again!" << endl;
                    } else {
                        cout << "Computer picked up " << deck.getDeck()[0].toString() << endl << endl;
                        computer.addCard(deck.getDeck()[0]);
                        deck.removeTopCard();
                        user.setTurn(true);
                        computer.setTurn(false);
                    }
                }
            }

        } else if (difficulty == "H" || difficulty == "h") {

        }
    }

    // write to console who won
    if (user.getPoints() > computer.getPoints()) {
        cout << "You win!" << endl;
        cout << "Score: " << user.getPoints() << " - " << computer.getPoints() << endl;
    } else if (user.getPoints() < computer.getPoints()) {
        cout << "Unfortunately you lost!" << endl;
        cout << "Score: " << computer.getPoints() << " - " << user.getPoints() << endl;
    } else {
        cout << "You tied!" << endl;
        cout << "Score: " << user.getPoints() << " - " << computer.getPoints() << endl;
    }

    return 0;
}