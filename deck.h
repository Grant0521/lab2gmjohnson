/*
 * Name: Grant Johnson, Ethan Sychangco
 * Email: Gmjohnson@scu.edu, Esychangco@scu.edu
 */
#ifndef DECK_H
#define DECK_H

#include "card.h" // Include necessary headers

namespace groupGE {
    class Deck {
    public:
        static const size_t CARDS_PER_DECK = 52;
        Deck();
        const Card &deal(void);
        void shuffle(void);

        friend std::ostream& operator<<(std::ostream& os, const Deck &);

        // Consider implementing a swap function if needed
    private:
        int next;
        Card cards[CARDS_PER_DECK];
        int guard;
    };
}

#endif // DECK_H