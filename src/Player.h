//
// Created by Devon on 9/29/2018.
//

#ifndef CS205_GOFISH_MASTER_PLAYER_H
#define CS205_GOFISH_MASTER_PLAYER_H

#include "Card.h"
#include "Deck.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Player {
private:
    vector<Card> hand;
    int points = 0;
    bool turn = false;

public:
    /*
     * Creates a new player and makes their hand when passed in a deck
     */
    Player(Deck deck);

    /*
     * Add a card to player's hand
     */
    void addCard(Card card);

    /*
     * Remove card from player's hand at specific index
     */
    void removeCard(int index);

    /*
     * Check for a book in player's hand
     */
    bool checkBook();

    /*
     * Returns player's hand
     */
    vector<Card> getHand();

    /*
     * Prints the current player's hand
     */
    void printHand();

    /*
     * Adds a point whenever a book is found
     */
    void addPoint();

    /*
     * returns player's points
     */
    int getPoints();

    /*
     * returns bool value of if it's the player's turn or not
     */
    bool getTurn();

    /*
     * set player's turn value
     */
    void setTurn(bool t);
};

#endif //CS205_GOFISH_MASTER_PLAYER_H
