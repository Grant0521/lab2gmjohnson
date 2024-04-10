/*
 * Name: Grant Johnson, Ethan Sychangco
 * Email: Gmjohnson@scu.edu, Esychangco@scu.edu
 */
#ifndef CARD_H
#define CARD_H

// short hand to define static const varables

// stand-alone Card class
namespace groupGE {
	class Card {
	public:
		using rank_t = int;
		using suit_t = int;
		Card(suit_t s=0, rank_t r=0): rank{r}, suit{s} {}
		
	friend std::ostream& operator<<(std::ostream& os, const Card &c);

	// encode a card into an integer
	operator int() const;

	private:
		rank_t rank;	// A, King, Queen, ..., 2
		suit_t suit;	// Spade, Heart, Diamond, Club
	};
}

#endif // CARD_H
