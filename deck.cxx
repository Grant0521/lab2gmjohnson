/*
 * Name: Grant Johnson, Ethan Sychangco
 * Email: Gmjohnson@scu.edu, Esychangco@scu.edu
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "card.h"
#include "deck.h"

using namespace groupGE;

namespace groupGE{


Deck::Deck() {
    guard = 5;
    next = -1;
    for (int i = 0; i < CARDS_PER_DECK; ++i) {
        cards[i] = Card(i / 13 + 1, i % 13 + 2); // Initialize cards array
    }
}

const Card &Deck::deal() {
    next += 1;
    if ((CARDS_PER_DECK - next) <= guard) {
        shuffle();
        next = 0;
    }
    return cards[next];
}

std::ostream& operator<<(std::ostream& os, const Deck &d) {
    // Implement printing of Deck

    for (int row = 0; row < 4; row ++){
        for (int i = 0; i < 13; i++) {
            std::cout << d.cards[(13 * row) + i] << " ";
        }    
        std::cout << std::endl;
    }
    return os;
}
}