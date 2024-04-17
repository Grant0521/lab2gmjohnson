/*
 * Name: Grant Johnson, Ethan Sychangco
 * Email: Gmjohnson@scu.edu, Esychangco@scu.edu
 */
#include <iomanip>
#include <iostream>
#include "card.h"
#include "deck.h"
#include <cstdlib>

using namespace std;
using namespace groupGE;

// Test program for Deck class
int main(void) {
    Deck deckCards;
    Card tempCard;
    for (int i = 0; i < 52; i++) {
        tempCard = deckCards.deal();
        cout << tempCard << endl;
    }
    return EXIT_SUCCESS;
}