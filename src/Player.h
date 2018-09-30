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
};

#endif //CS205_GOFISH_MASTER_PLAYER_H
