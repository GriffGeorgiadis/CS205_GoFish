//
// Created by Devon on 9/6/2018.
//

#ifndef CS205_GOFISH_CARD_H
#define CS205_GOFISH_CARD_H

#endif //CS205_GOFISH_CARD_H

class Card {
private:
    int cardNumber;

public:
    /*
     * Constructor that takes a card number as n
     * and sets the integer num variable
     * 1 = Ace, 2-10 = Normal, 11 = Jack, 12 = Queen, 13 = King
     */
    Card(int n);

    /*
     * Get card's number value
     */
    int getCardNumber();

    /*
     * Set card's number value (not necessarily needed)
     */
    void setCardNumber(int n);
};