//
// Created by Devon on 9/6/2018.
//

#ifndef CS205_GOFISH_CARD_H
#define CS205_GOFISH_CARD_H

#include <string>
#include <cstring>
using namespace std;



enum Suit {hearts, diamonds, spades, clubs};

class Card {
private:
    int rank;
    Suit suit;

public:
    /*
     * Constructor that takes a card number as n
     * and sets the integer num variable
     * 1 = Ace, 2-10 = Normal, 11 = Jack, 12 = Queen, 13 = King
     */
    Card(int r, Suit s);

    /*
     * Get card's number value
     */
    int getRank();

    /*
     * Set card's number value (not necessarily needed)
     */
    void setRank(int r);

    /*
     * Get card's suit value
     */
    Suit getSuit();

    /*
     * Set suit value
     */
    void setSuit(Suit s);

    /*
     * Converts all card's to a string value
     */
    string toString();
};

#endif //CS205_GOFISH_CARD_H