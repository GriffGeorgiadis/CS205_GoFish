//
// Created by Devon on 9/29/2018.
//

#include "Player.h"

Player::Player(Deck deck) {
    for (int i = 0; i < 7; ++i) {
        hand.push_back(deck.getDeck()[i]);
    }
}

void Player::addCard(Card card) {
    hand.push_back(card);
}

void Player::removeCard(int index) {
    hand.erase(hand.begin() + index);
}

vector<Card> Player::getHand() {
    return hand;
}

void Player::printHand() {
    for (int i = 0; i < hand.size(); ++i) {
        cout << hand[i].toString() << endl;
    }
}

void Player::addPoint() {
    points++;
}

int Player::getPoints() {
    return points;
}