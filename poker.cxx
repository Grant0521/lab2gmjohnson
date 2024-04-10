/*
 * Name: Your Name
 * Email: Your email
 */
#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include "card.h"
#include "deck.h"
#include "poker.h"

using namespace std;

namespace csen79 {
	// so that we can simply "cout << " a poker hand
	ostream& operator<<(ostream& os, const Poker &h) {
		return os;
	}
}

