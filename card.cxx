/*
 * Name: Grant Johnson, Ethan Sychangco
 * Email: Gmjohnson@scu.edu, Esychangco@scu.edu
 */
#include <iomanip>
#include <iostream>
#include "card.h"
using namespace std;

// Stand-alone Card definitions
namespace groupGE {
	ostream& operator<<(ostream& os, const Card &c) {
		string faces[4] = {"J", "Q", "K", "A"};
		if (c.rank <= 10){
			os << c.rank;
		}
		else {
			os << faces[c.rank - 11];
		}

		// 1, 2, 3, 4
		string suits[4] = {"♠", "♥", "♦", "♣"};
		os << suits[c.suit - 1];

		return os;
	};

	Card::operator int() const {
		return (suit * rank);
	};

	bool operator< (const Card &c1, const Card &c2){
		if (int(c1) < int(c2)){
			return true;
		}
		return false;
	}
}
