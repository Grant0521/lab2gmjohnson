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

Deck::Deck() {
    guard = 5;
    next = -1;
    for (int i = 0; i < CARDS_PER_DECK; ++i) {
        cards[i] = Card(i / 13 + 1, i % 13 + 1); // Initialize cards array
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

std::ostream& operator<<(std::ostream& os, const Deck &) {
    // Implement printing of Deck
    return os;
}