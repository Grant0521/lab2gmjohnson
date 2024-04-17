/*
 * Name: Grant Johnson, Ethan Sychangco
 * Email: Gmjohnson@scu.edu, Esychangco@scu.edu
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

namespace groupGE {
	Poker::Poker() {
		Deck d; // make a deck
		deck = d; // set pokerobj.deck to that deck
	}

	void Poker::dealHand(){
		for (int card = 0; card < 5; card++){
			Card c = deck.deal();
			hand[card] = c;
			hand_ranks[card] = c.getRank();
			hand_suits[card] = c.getSuit();
		}
	}
	
	// so that we can simply "cout << " a poker hand
	ostream& operator<<(ostream& os, const Poker &h) {
		for (int card = 0; card < 5; card++){
			cout << h.hand[card];
		}
		cout << endl; 
		return os;
	}

	bool isFullhouse() {
		return true;
	}
	bool Poker::isFlush() {
		int j;
		for (int i = 0; i < 4; i++) {
			j = i + 1;
			if (hand_suits[j] != hand_suits[i]) {
				return false;
			}
		}
		return true;
	}
	bool Poker::isStraight() {
		int temp;
		bool straight;
		for (int i = 0; i < 5; i++) {
			if (hand_ranks[i] == 14) {
				if (hand_ranks[i + 1] > 7) {
					hand_ranks[i] = 14;
				}
				else {
					hand_ranks[i] = 1;
				}
			}
			for (int j = i; j < 5; j++) {
				if (hand_ranks[j] > hand_ranks[i]) {
					temp = hand_ranks[i];
					hand_ranks[i] = hand_ranks[j];
					hand_ranks[j] = temp;
				}
			}
			if (i > 0) {
				if (hand_ranks[i] != hand_ranks[i - 1] + 1) {
					return false;
				}
			}
		}
		return true;
	}
	bool Poker::isQuad() {
		int testNum;
		bool oneFail = true;
		for (int i = 0; i < 5; i++) {

		}
		return true;
	}
	bool Poker::isTriple() {
		return true;
	}
	bool Poker::is2Pair() {
		return true;
	}
	bool Poker::isPair() {
		return true;
	}
}

