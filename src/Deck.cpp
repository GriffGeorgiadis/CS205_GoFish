//
// Created by Devon on 9/29/2018.
//

#include "Deck.h"

Deck::Deck() {
    for (int i = 0; i < 13; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (i == 0) {
                if (j == 0) {
                    deck.push_back(Card(1, hearts));
                } else if (j == 1) {
                    deck.push_back(Card(1, diamonds));
                } else if (j == 2) {
                    deck.push_back(Card(1, spades));
                } else {
                    deck.push_back(Card(1, clubs));
                }
            } else if (i == 1) {
                if (j == 0) {
                    deck.push_back(Card(2, hearts));
                } else if (j == 1) {
                    deck.push_back(Card(2, diamonds));
                } else if (j == 2) {
                    deck.push_back(Card(2, spades));
                } else {
                    deck.push_back(Card(2, clubs));
                }
            } else if (i == 2) {
                if (j == 0) {
                    deck.push_back(Card(3, hearts));
                } else if (j == 1) {
                    deck.push_back(Card(3, diamonds));
                } else if (j == 2) {
                    deck.push_back(Card(3, spades));
                } else {
                    deck.push_back(Card(3, clubs));
                }
            } else if (i == 3) {
                if (j == 0) {
                    deck.push_back(Card(4, hearts));
                } else if (j == 1) {
                    deck.push_back(Card(4, diamonds));
                } else if (j == 2) {
                    deck.push_back(Card(4, spades));
                } else {
                    deck.push_back(Card(4, clubs));
                }
            } else if (i == 4) {
                if (j == 0) {
                    deck.push_back(Card(5, hearts));
                } else if (j == 1) {
                    deck.push_back(Card(5, diamonds));
                } else if (j == 2) {
                    deck.push_back(Card(5, spades));
                } else {
                    deck.push_back(Card(5, clubs));
                }
            } else if (i == 5) {
                if (j == 0) {
                    deck.push_back(Card(6, hearts));
                } else if (j == 1) {
                    deck.push_back(Card(6, diamonds));
                } else if (j == 2) {
                    deck.push_back(Card(6, spades));
                } else {
                    deck.push_back(Card(6, clubs));
                }
            } else if (i == 6) {
                if (j == 0) {
                    deck.push_back(Card(7, hearts));
                } else if (j == 1) {
                    deck.push_back(Card(7, diamonds));
                } else if (j == 2) {
                    deck.push_back(Card(7, spades));
                } else {
                    deck.push_back(Card(7, clubs));
                }
            } else if (i == 7) {
                if (j == 0) {
                    deck.push_back(Card(8, hearts));
                } else if (j == 1) {
                    deck.push_back(Card(8, diamonds));
                } else if (j == 2) {
                    deck.push_back(Card(8, spades));
                } else {
                    deck.push_back(Card(8, clubs));
                }
            } else if (i == 8) {
                if (j == 0) {
                    deck.push_back(Card(9, hearts));
                } else if (j == 1) {
                    deck.push_back(Card(9, diamonds));
                } else if (j == 2) {
                    deck.push_back(Card(9, spades));
                } else {
                    deck.push_back(Card(9, clubs));
                }
            } else if (i == 9) {
                if (j == 0) {
                    deck.push_back(Card(10, hearts));
                } else if (j == 1) {
                    deck.push_back(Card(10, diamonds));
                } else if (j == 2) {
                    deck.push_back(Card(10, spades));
                } else {
                    deck.push_back(Card(10, clubs));
                }
            } else if (i == 10) {
                if (j == 0) {
                    deck.push_back(Card(11, hearts));
                } else if (j == 1) {
                    deck.push_back(Card(11, diamonds));
                } else if (j == 2) {
                    deck.push_back(Card(11, spades));
                } else {
                    deck.push_back(Card(11, clubs));
                }
            } else if (i == 11) {
                if (j == 0) {
                    deck.push_back(Card(12, hearts));
                } else if (j == 1) {
                    deck.push_back(Card(12, diamonds));
                } else if (j == 2) {
                    deck.push_back(Card(12, spades));
                } else {
                    deck.push_back(Card(12, clubs));
                }
            } else {
                if (j == 0) {
                    deck.push_back(Card(13, hearts));
                } else if (j == 1) {
                    deck.push_back(Card(13, diamonds));
                } else if (j == 2) {
                    deck.push_back(Card(13, spades));
                } else {
                    deck.push_back(Card(13, clubs));
                }
            }
        }
    }
    random_shuffle(deck.begin(), deck.end());
}

void Deck::removeTopCard() {
    deck.erase(deck.begin());
}

void Deck::toString() {
    for (int i = 0; i < deck.size(); ++i) {
        cout << deck[i].toString() << endl;
    }
}

vector<Card> Deck::getDeck() {
    return deck;
}