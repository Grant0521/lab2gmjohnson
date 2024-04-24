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
		deck.shuffle();
	}

	void Poker::dealHand(){
		// deal 5 cards from the deck and capture those cards
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
		return os;
	}
	
	// All the following functions are for determining poker hands
	bool Poker::isFullhouse() {
		int temp;
		bool straight;
		for (int i = 0; i < 5; i++) {
			for (int j = i; j < 5; j++) {
				if (hand_ranks[j] > hand_ranks[i]) {
					temp = hand_ranks[i];
					hand_ranks[i] = hand_ranks[j];
					hand_ranks[j] = temp;
				}
			}
		}
		if (((hand_ranks[0] == hand_ranks[1] && hand_ranks[1] == hand_ranks[2]) && (hand_ranks[3] == hand_ranks[4])) || ((hand_ranks[0] == hand_ranks[1]) && (hand_ranks[2] == hand_ranks[3]) && (hand_ranks[3] == hand_ranks[4]))) {
			return true;
		}
		return false;
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
				if ((hand_ranks[i] + 1) != (hand_ranks[i - 1])) {
					return false;
				}
			}
		}
		return true;
	}
	bool Poker::isQuad() {
		int count1 = 1, count2 = 1;
		for (int i = 2; i < 5; i++) {
			if (hand_ranks[i] == hand_ranks[0]) {
				count1 += 1;
			}
			else if (hand_ranks[i] == hand_ranks[1]) {
				count2 += 1;
			}
		}
		if (count1 > 3 || count2 > 3) {
			return true;
		}
		return false;
	}
	bool Poker::isTriple() {
		int count1 = 0, count2 = 0, count3 = 0;
		for (int i = 0; i < 5; i++) {
			if (hand_ranks[i] == hand_ranks[0]) {
				count1 += 1;
			}
			else if (hand_ranks[i] == hand_ranks[1]) {
				count2 += 1;
			}
			else if (hand_ranks[i] == hand_ranks[2]) {
				count3 += 1;
			}
		}
		if (count1 > 2 || count2 > 2 || count3 > 2) {
			return true;
		}
		return false;
	}
	bool Poker::is2Pair() {
		int count1 = 0, count2 = 0, count3 = 0, count4 = 0;
		for (int i = 0; i < 5; i++) {
			if (hand_ranks[i] == hand_ranks[0]) {
				count1 += 1;
			}
			else if (hand_ranks[i] == hand_ranks[2]) {
				count2 += 1;
			}
			else if (hand_ranks[i] == hand_ranks[4]) {
				count3 += 1;
			}
		}
		if ((count1 > 1 && count2 > 1) || (count3 > 1 && count2 > 1) || (count1 > 1 && count3 > 1)) {
			return true;
		}
		return false;
	}
	bool Poker::isPair() {
		int count1 = 0, count2 = 0, count3 = 0, count4 = 0;
		for (int i = 0; i < 5; i++) {
			if (hand_ranks[i] == hand_ranks[0]) {
				count1 += 1;
			}
			else if (hand_ranks[i] == hand_ranks[1]) {
				count2 += 1;
			}
			else if (hand_ranks[i] == hand_ranks[2]) {
				count3 += 1;
			}
			else if (hand_ranks[i] == hand_ranks[2]) {
				count4 += 1;
			}
		}
		if (count1 > 1 || count2 > 1 || count3 > 1 || count4 > 1) {
			return true;
		}
		return false;
	}
}

