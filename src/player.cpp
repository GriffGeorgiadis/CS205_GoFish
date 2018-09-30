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

bool Player::checkBook() {
    int count = 0;
    for (int j = 0; j < hand.size(); ++j){
        count = 0;
        for(int i = 0; i < hand.size(); ++i){
            if (hand.at(i).getRank() == j){
                count++;
            }
            if (count == 4){
                for (int k = 0; k < hand.size(); ++k){
                    if (hand.at(k).getRank() == j){
                        hand.erase(hand.begin() + k);
                        k--;
                        i--;
                    }
                }
                return true;
            }
        }
    }
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

bool Player::getTurn() {
    return turn;
}

void Player::setTurn(bool t) {
    turn = t;
}