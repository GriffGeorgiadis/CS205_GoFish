//
// Created by Devon on 9/29/2018.
//

#ifndef CS205_GOFISH_MASTER_DECK_H
#define CS205_GOFISH_MASTER_DECK_H

#include "Card.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Deck {
private:
    vector<Card> deck;
public:
    /*
     * Creates the new deck and randomizes it
     */
    Deck();

    /*
     * Remove top card in deck
     */
    void removeTopCard();

    /*
     * Prints deck to console
     */
    void toString();

    /*
     * Returns a vector of cards (the deck)
     */
    vector<Card> getDeck();
};

#endif //CS205_GOFISH_MASTER_DECK_H