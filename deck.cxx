/*
 * Name: Grant Johnson, Ethan Sychangco
 * Email: Gmjohnson@scu.edu, Esychangco@scu.edu
 */
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;
#include "card.h"
#include "deck.h"

// Deck class implementation
namespace groupGE {
	Deck::Deck() {
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 13; j++) {
				cards[Card(i, j)];
			}
		}
	}
	// deal out one card
	const Card &Deck::deal() {
		next += 1;
		if ((52 - next) <= (guard)) {
			shuffle();
			next = 0;
		}
		return cards[next];
	}

	// print 13 cards each row
	ostream& operator<<(ostream& os, const Deck &d) {
		// this is stud function.  Replace it with your code
		return os;
	}
}

