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
    cout << "[Decktest] Printing 3 full decks! Deal 52 cards after each print, with the deck shuffled at 5 cards remaining" << endl;
    for (int deck = 0; deck < 3; deck++){
        cout << deckCards;
        cout << endl;
        for (int i = 0; i < 52; i++){
            deckCards.deal();
        }
    }
    return EXIT_SUCCESS;
}