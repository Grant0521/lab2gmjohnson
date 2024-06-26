/*
 * Name: Grant Johnson, Ethan Sychangco
 * Email: Gmjohnson@scu.edu, Esychangco@scu.edu
 */
#include <ctime>
#include <iomanip>
#include <iostream>
#include <cstring>
#include <cmath>
#include "card.h"
#include "deck.h"
#include "poker.h"
#include <chrono>

using namespace std;
using namespace groupGE;

// Poker test code
int main(void) {
	Poker p;
	
	cout << "[Pokertest] One hand for each ranking!" << endl;
	
	bool handsCompleted[9] = {false, false, false, false, false, false, false ,false, false};
	bool allHandsCompleted = false;
	/* This bool array is based on the numbers in the Poker header file. Reiterated here:
	 * static const PokerRank_t POKER_STRAIGHT_FLUSH = 8;
	 * static const PokerRank_t POKER_QUAD = 7;
	 * static const PokerRank_t POKER_FULLHOUSE = 6;
	 * static const PokerRank_t POKER_FLUSH = 5;
	 * static const PokerRank_t POKER_STRAIGHT = 4;
	 * static const PokerRank_t POKER_TRIPLE = 3;
	 * static const PokerRank_t POKER_2_PAIR = 2;
	 * static const PokerRank_t POKER_PAIR = 1;
	 * static const PokerRank_t POKER_HIGHCARD = 0;
	 */

	int totalHands = 0;
	double percent;
	auto start = std::chrono::high_resolution_clock::now();
	while (!allHandsCompleted) {
		bool newHandType = false;
		p.dealHand();

		if (p.isFlush() && p.isStraight() && !handsCompleted[Poker::POKER_STRAIGHT_FLUSH]){
			handsCompleted[Poker::POKER_STRAIGHT_FLUSH] = true;
			cout << p << " (Straight Flush)" << endl;
		}
		else if (p.isQuad() && !handsCompleted[Poker::POKER_QUAD]) {
			handsCompleted[Poker::POKER_QUAD] = true;
			cout << p << " (Four of a Kind)" << endl;
		}
		else if (p.isFullhouse() && !handsCompleted[Poker::POKER_FULLHOUSE]){
			handsCompleted[Poker::POKER_FULLHOUSE] = true;
			cout << p << " (Full House)" << endl;
		}
		else if (p.isFlush() && !handsCompleted[Poker::POKER_FLUSH]){
			handsCompleted[Poker::POKER_FLUSH] = true;
			cout << p << " (Flush)" << endl;
		}
		else if (p.isStraight() && !handsCompleted[Poker::POKER_STRAIGHT]){
			handsCompleted[Poker::POKER_STRAIGHT] = true;
			cout << p << " (Straight)" << endl;
		}
		else if (p.isTriple() && !handsCompleted[Poker::POKER_TRIPLE]){
			handsCompleted[Poker::POKER_TRIPLE] = true;
			cout << p << " (Three of a Kind)" << endl;
		}
		else if (p.is2Pair() && !handsCompleted[Poker::POKER_2_PAIR]){
			handsCompleted[Poker::POKER_2_PAIR] = true;
			cout << p << " (Two Pair)" << endl;
		}
		else if (p.isPair() && !handsCompleted[Poker::POKER_PAIR]){
			handsCompleted[Poker::POKER_PAIR] = true;
			cout << p << " (One Pair)" << endl;
		}
		else if (!handsCompleted[Poker::POKER_HIGHCARD]){
			handsCompleted[Poker::POKER_HIGHCARD] = true;
			cout << p << " (High Card)" << endl;
		}

		// check to see if we have printed all the hands
		// if at least one incomplete, we are not done; keep looping
		bool atLeastOneIncomplete = false;
		for (int i = 0; i < 9; i++){
			if (!handsCompleted[i]) {
				atLeastOneIncomplete = true;
			}
		}
		if (!atLeastOneIncomplete){
			allHandsCompleted = true;
		}
	}

	cout << "[Pokertest] Hand statistics!" << endl;
	const int HAND_COUNT = 999999;
	int handStats[9];

	for (int hand = 0; hand < HAND_COUNT; hand++){
		p.dealHand();
		totalHands += 1;
		if (p.isFlush() && p.isStraight()){
			handStats[Poker::POKER_STRAIGHT_FLUSH] += 1;
		}
		else if (p.isQuad()) {
			handStats[Poker::POKER_QUAD] += 1;
		}
		else if (p.isFullhouse()){
			handStats[Poker::POKER_FULLHOUSE] += 1;
		}
		else if (p.isFlush()){
			handStats[Poker::POKER_FLUSH] += 1;
		}
		else if (p.isStraight()){
			handStats[Poker::POKER_STRAIGHT] += 1;
		}
		else if (p.isTriple()){
			handStats[Poker::POKER_TRIPLE] += 1;
		}
		else if (p.is2Pair()){
			handStats[Poker::POKER_2_PAIR] += 1;
		}
		else if (p.isPair()){
			handStats[Poker::POKER_PAIR] += 1;
		}
		else {
			handStats[Poker::POKER_HIGHCARD] += 1;
		}
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;

	// print the results in a nice format
	string hands[9] = {"High Card", "Pair", "Two Pair", "Three of a Kind", "Straight", "Flush",
		"Full House", "Four of a Kind", "Straight Flush"};

	cout << "Dealt " << totalHands << " hands. Elapsed Time: " << duration.count() << " seconds." << endl;
	cout << fixed << setprecision(6) << "Average " << (duration.count() / totalHands) * 50000 << " seconds per 50k hands" << endl;
	for (int i = 0; i < 9; i++){
		percent = (handStats[i] * 100.00) / totalHands;
		cout << setw(20) << hands[i] << ": " << setw(20) << handStats[i] << setw(20) << setprecision(2) << percent << "%" << endl;
	}

	return EXIT_SUCCESS;
}