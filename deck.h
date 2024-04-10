/*
 * Name: Grant Johnson, Ethan Sychangco
 * Email: Gmjohnson@scu.edu, Esychangco@scu.edu
 */
namespace groupGE {
	// Deck class with an embedded Card class
	// See stand-alone Card class in "card.h"
	class Deck {
	public:
		static const size_t CARDS_PER_DECK = 52;
		Deck();
		const Card &deal(void);
		void shuffle(void);

	friend std::ostream& operator<<(std::ostream& os, const Deck &);

	private:
		int nCards;
		Card cards[CARDS_PER_DECK];
		int next = -1;
		int guard = 5;
	};
}
