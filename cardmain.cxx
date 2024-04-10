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
	Card c(4,10);
	cout << c;
	Card d(4,11);
	cout << d;

	cout << int(d);

	cout << (d < c);

	return EXIT_SUCCESS;
}
