/*
 * Name: Grant Johnson, Ethan Sychangco
 * Email: Gmjohnson@scu.edu, Esychangco@scu.edu
 * CSEN 79 Lab Sample Code
 */
#ifndef POKER_H
#define POKER_H

// Poker class
namespace csen79 {
	class Poker {
	public:
		// An int to define each of the poker ranking
		// in decending order here.  Therefore 0 is the lowest rank, which is High card
		using PokerRank_t = int;
		// You could also use enum
		static const PokerRank_t POKER_STRAIGHT_FLUSH = 8;
		static const PokerRank_t POKER_QUAD = 7;
		static const PokerRank_t POKER_FULLHOUSE = 6;
		static const PokerRank_t POKER_FLUSH = 5;
		static const PokerRank_t POKER_STRAIGHT = 4;
		static const PokerRank_t POKER_TRIPLE = 3;
		static const PokerRank_t POKER_2_PAIR = 2;
		static const PokerRank_t POKER_PAIR = 1;
		static const PokerRank_t POKER_HIGHCARD = 0;

		Poker();
		void dealHand();
		friend std::ostream& operator<<(std::ostream& os, const Poker &c);

	private:
		Deck deck;
		// use a member to store the the hand as opposed to dealHand returning a pointer
		// don't want to deal with new/delete yet

		// helper functions for ranking, you should implement them in poker.cxx
		bool isFlush(uint s[]) {return false; }
		bool isStraight(uint r[]) {return false; }
		bool isQuad(uint r[]) {return false; }
		bool isTriple(uint r[]) {return false; }
		bool is2Pair(uint r[]) {return false; }
		bool isPair(uint r[]) {return false; }
	};
}

#endif // POKER_H
