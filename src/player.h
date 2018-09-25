//
// Created by Griffin Georgiadis on 9/25/18.
//

#ifndef CS205_GOFISH_MASTER_PLAYER_H
#define CS205_GOFISH_MASTER_PLAYER_H

#endif //CS205_GOFISH_MASTER_PLAYER_H

using namespace std;

#include <vector>

class {

public:

    /**
     * default constructor
     *
     */
    player();


    /**
     * Player draw action
     *
     */
    void draw();


    /**
     * places card
     *
     */
    void giveCard();

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
    int book(books);



protected:

private:

    vector<int> playerHand;
    int books = 0;



};
