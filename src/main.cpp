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

    return 0;
}

