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
#include <algorithm>
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
    bool setLying = false;
    bool cardsInHand = false;
    vector<int> computerMemory;

    // main menu
    user.setTurn(true);
    cout << endl;
    cout << "Welcome to Go Fish!" << endl;
    cout << "Please choose a difficulty to play on" << endl;
    cout << endl;
    cout << "E = Easy, H = Hard" << endl;
    string difficulty;
    cin >> difficulty;
    while (difficulty != "E" && difficulty != "e" && difficulty != "H" && difficulty != "h") {
        cout << endl;
        cout << "Difficulty not found, please try again!" << endl;
        cout << "E = Easy, H = Hard" << endl;
        cin >> difficulty;
    }

    // main game loop
    while (user.getHand().size() != 0 && computer.getHand().size() != 0 && deck.getDeck().size() != 0) {
        /* ===============
         * Easy difficulty
         * ===============
         */
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

                    cardsInHand = false;
                    // make sure card asked for is in player's hand
                    for (int i = 0; i < user.getHand().size(); ++i) {
                        if (user.getHand()[i].getRank() == guess) {
                            cardsInHand = true;
                        }
                    }
                    while (!cardsInHand) {
                        cout << endl;
                        cout << "Card must be in your hand to guess" << endl;
                        cout << "What are you looking for? (1 = Ace, 2-10, 11 = Jack, 12 = Queen, 13 = King)" << endl;
                        cin >> guess;
                        for (int i = 0; i < user.getHand().size(); ++i) {
                            if (user.getHand()[i].getRank() == guess) {
                                cardsInHand = true;
                            }
                        }
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
                        outFile << "======================" << endl;
                        outFile << "Player's Guess Rank: " << guess << endl;
                        outFile << "======================" << endl;
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

                // make sure card randomized is in computer's hand
                cardsInHand = false;
                for (int i = 0; i < computer.getHand().size(); ++i) {
                    if (randomRank == computer.getHand()[i].getRank()) {
                        cardsInHand = true;
                    }
                }
                while (!cardsInHand) {
                    randomRank = rand() % 13 + 1;
                    for (int i = 0; i < computer.getHand().size(); ++i) {
                        if (randomRank == computer.getHand()[i].getRank()) {
                            cardsInHand = true;
                        }
                    }
                }

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
                    outFile << "========================" << endl;
                    outFile << "Computer's Guess Rank: " << randomRank << endl;
                    outFile << "========================" << endl;
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
                    cout << endl;
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

        }

        /* ===============
         * Hard difficulty
         * ===============
         */
        else if (difficulty == "H" || difficulty == "h") {
            int lyingPercent;
            if (setLying == false) {
                // set the computer's lying percentage
                cout << "Please select the lying chance percent of the computer (0 - 100): " << endl;
                cin >> lyingPercent;
                while (lyingPercent < 0 || lyingPercent > 100) {
                    cout << "Not valid percentage, keep it between 0 and 100!" << endl << endl;
                    cin >> lyingPercent;
                }
                setLying = true;
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

                    // make sure card asked for is in player's hand
                    cardsInHand = false;
                    for (int i = 0; i < user.getHand().size(); ++i) {
                        if (guess == user.getHand()[i].getRank()) {
                            cardsInHand = true;
                        }
                    }
                    while (!cardsInHand) {
                        cout << endl;
                        cout << "Card must be in your hand to guess" << endl;
                        cout << "What are you looking for? (1 = Ace, 2-10, 11 = Jack, 12 = Queen, 13 = King)" << endl;
                        cin >> guess;
                        for (int i = 0; i < user.getHand().size(); ++i) {
                            if (guess == user.getHand()[i].getRank()) {
                                cardsInHand = true;
                            }
                        }
                    }

                    // append player's guess to computer's memory
                    computerMemory.push_back(guess);

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
                        outFile << "======================" << endl;
                        outFile << "Player's Guess Rank: " << guess << endl;
                        outFile << "======================" << endl;
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

                    // initate random number to see if computer will lie
                    int randomNumber = rand() % 100;
                    if (compHasCard && randomNumber <= lyingPercent) {
                        compHasCard = false;
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
                // check computer's memory to see if card is storeed, if so guess
                // otherwise pick random number
                int guess;
                bool memory = false;
                int memoryRank;

                for (int i = 0; i < computer.getHand().size(); ++i) {
                    for (int j = 0; j < computerMemory.size(); ++j) {
                        if (computer.getHand()[i].getRank() == computerMemory[j]) {
                            memoryRank = computer.getHand()[i].getRank();
                            memory = true;
                        }
                    }
                }

                if (memory = true) {
                    guess = memoryRank;
                } else {
                    // pick a random card rank for computer
                    guess = rand() % 13 + 1;
                }

                // make sure card randomized is in computer's hand
                cardsInHand = false;
                for (int i = 0; i < computer.getHand().size(); ++i) {
                    if (guess == computer.getHand()[i].getRank()) {
                        cardsInHand = true;
                    }
                }
                while (!cardsInHand) {
                    guess = rand() % 13 + 1;
                    for (int i = 0; i < computer.getHand().size(); ++i) {
                        if (guess == computer.getHand()[i].getRank()) {
                            cardsInHand = true;
                        }
                    }
                }

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
                    outFile << "========================" << endl;
                    outFile << "Computer's Guess Rank: " << guess << endl;
                    outFile << "========================" << endl;
                }

                // run through user's hand to see if they have any of those cards
                vector<Card> cardsWithThatRank;
                vector<int> indexWhereCardsAre;
                bool userHasCard = false;
                for (int i = 0; i < user.getHand().size(); ++i) {
                    if (user.getHand()[i].getRank() == guess) {
                        cardsWithThatRank.push_back(user.getHand()[i]);
                        indexWhereCardsAre.push_back(i);
                        userHasCard = true;
                    }
                }

                if (userHasCard) {
                    cout << "Computer guesses for card rank of " << guess << endl;
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
                    cout << endl;
                    cout << "Computer guessed card of rank " << guess << endl;
                    cout << "* computer went go fish *" << endl;
                    if (deck.getDeck()[0].getRank() == guess) {
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