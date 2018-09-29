//
// Created by Devon on 9/29/2018.
//

#ifndef GO_FISH_PLAYER_H
#define GO_FISH_PLAYER_H

using namespace std;

#include <vector>
#include <string>
#include <cstring>
#include <iostream>

class Player {

public:

    /**
     * default constructor
     *
     */
    Player();


    /**
     * Player draw action
     *
     */
    void draw();


    /**
     * places card
     *
     */
    void placeCard();

    /**
     * ask for card
     *
     */
    void ask();

    /**
     *  respond to ask
     */
    void respond();

    /**
     *  score keeper
     *
     */
    int book();

protected:

private:

    vector<int> playerHand;
    int books = 0;



};

#endif //GO_FISH_PLAYER_H
