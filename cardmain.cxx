/*
 * Name: Grant Johnson, Ethan Sychangco
 * Email: Gmjohnson@scu.edu, Esychangco@scu.edu
 */
#include <iomanip>
#include <iostream>
#include "card.h"

using namespace std;
using namespace groupGE;

// Test program for Card
int main(void) {
	cout << "Creating a full deck of cards!" << endl;

	for (int rank = 2; rank < 15; rank++){
		for (int suit = 1; suit < 5; suit++){
			Card c(suit, rank);
			cout << c << " ";
		}
		cout << endl;
	}
	return EXIT_SUCCESS;
}
