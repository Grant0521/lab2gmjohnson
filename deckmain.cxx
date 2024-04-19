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
    cout << "[Decktest] Printing 3 full decks! (Shuffled at 5 cards remaining)" << endl;
    for (int deck = 0; deck < 3; deck++){
        for (int row = 0; row < 4; row ++){
            for (int i = 0; i < 13; i++) {
                tempCard = deckCards.deal();
                cout << tempCard << " ";
            }    
            cout << endl;
        }
    }
    return EXIT_SUCCESS;
}