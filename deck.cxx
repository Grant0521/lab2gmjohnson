/*
 * Name: Your Name
 * Email: Your email
 */
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;
#include "card.h"
#include "deck.h"

// Deck class implementation
namespace csen79 {
	// deal out one card
	const Card &Deck::deal() {
		// this is stud function.  Replace it with your code
		return cards[0];
	}

	// print 13 cards each row
	ostream& operator<<(ostream& os, const Deck &d) {
		// this is stud function.  Replace it with your code
		return os;
	}
}

