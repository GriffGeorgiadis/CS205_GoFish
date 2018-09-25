//
// Created by Devon on 9/6/2018.
//

#include "Card.h"
#include <string>
#include <cstring>
using namespace std;

Card::Card(int r, Suit s) {
    rank = r;
    suit = s;
}

int Card::getRank() {
    return rank;
}

void Card::setRank(int r) {
    rank = r;
}

Suit Card::getSuit() {
    return suit;
}

void Card::setSuit(Suit s) {
    suit = s;
}

string Card::toString() {
    if (rank == 1) {
        if (suit == hearts) {
            return "Ace of Hearts";
        } else if (suit == diamonds) {
            return "Ace of Diamonds";
        } else if (suit == spades) {
            return "Ace of Spades";
        } else if (suit == clubs) {
            return "Ace of Clubs";
        }
    } else if (rank == 2) {
        if (suit == hearts) {
            return "2 of Hearts";
        } else if (suit == diamonds) {
            return "2 of Diamonds";
        } else if (suit == spades) {
            return "2 of Spades";
        } else if (suit == clubs) {
            return "2 of Clubs";
        }
    } else if (rank == 3) {
        if (suit == hearts) {
            return "3 of Hearts";
        } else if (suit == diamonds) {
            return "3 of Diamonds";
        } else if (suit == spades) {
            return "3 of Spades";
        } else if (suit == clubs) {
            return "3 of Clubs";
        }
    } else if (rank == 4) {
        if (suit == hearts) {
            return "4 of Hearts";
        } else if (suit == diamonds) {
            return "4 of Diamonds";
        } else if (suit == spades) {
            return "4 of Spades";
        } else if (suit == clubs) {
            return "4 of Clubs";
        }
    } else if (rank == 5) {
        if (suit == hearts) {
            return "5 of Hearts";
        } else if (suit == diamonds) {
            return "5 of Diamonds";
        } else if (suit == spades) {
            return "5 of Spades";
        } else if (suit == clubs) {
            return "5 of Clubs";
        }
    } else if (rank == 6) {
        if (suit == hearts) {
            return "6 of Hearts";
        } else if (suit == diamonds) {
            return "6 of Diamonds";
        } else if (suit == spades) {
            return "6 of Spades";
        } else if (suit == clubs) {
            return "6 of Clubs";
        }
    } else if (rank == 7) {
        if (suit == hearts) {
            return "7 of Hearts";
        } else if (suit == diamonds) {
            return "7 of Diamonds";
        } else if (suit == spades) {
            return "7 of Spades";
        } else if (suit == clubs) {
            return "7 of Clubs";
        }
    } else if (rank == 8) {
        if (suit == hearts) {
            return "8 of Hearts";
        } else if (suit == diamonds) {
            return "8 of Diamonds";
        } else if (suit == spades) {
            return "8 of Spades";
        } else if (suit == clubs) {
            return "8 of Clubs";
        }
    } else if (rank == 9) {
        if (suit == hearts) {
            return "9 of Hearts";
        } else if (suit == diamonds) {
            return "9 of Diamonds";
        } else if (suit == spades) {
            return "9 of Spades";
        } else if (suit == clubs) {
            return "9 of Clubs";
        }
    } else if (rank == 10) {
        if (suit == hearts) {
            return "10 of Hearts";
        } else if (suit == diamonds) {
            return "10 of Diamonds";
        } else if (suit == spades) {
            return "10 of Spades";
        } else if (suit == clubs) {
            return "10 of Clubs";
        }
    } else if (rank == 11) {
        if (suit == hearts) {
            return "Jack of Hearts";
        } else if (suit == diamonds) {
            return "Jack of Diamonds";
        } else if (suit == spades) {
            return "Jack of Spades";
        } else if (suit == clubs) {
            return "Jack of Clubs";
        }
    } else if (rank == 12) {
        if (suit == hearts) {
            return "Queen of Hearts";
        } else if (suit == diamonds) {
            return "Queen of Diamonds";
        } else if (suit == spades) {
            return "Queen of Spades";
        } else if (suit == clubs) {
            return "Queen of Clubs";
        }
    } else if (rank == 13) {
        if (suit == hearts) {
            return "King of Hearts";
        } else if (suit == diamonds) {
            return "King of Diamonds";
        } else if (suit == spades) {
            return "King of Spades";
        } else if (suit == clubs) {
            return "King of Clubs";
        }
    }
}