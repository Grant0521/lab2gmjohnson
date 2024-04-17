/*
 * Name: Grant Johnson, Ethan Sychangco
 * Email: Gmjohnson@scu.edu, Esychangco@scu.edu
 */
#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;
#include "card.h"
#include "deck.h"

namespace groupGE {
	// Fisher-Yates shuffle
	void Deck::shuffle() {
		srand(time(NULL)); 
		for (int i = CARDS_PER_DECK - 1; i > 0; i--) { 
			int j = rand() % (i + 1);
			std::swap(cards[i], cards[j]);
		}
	}
}