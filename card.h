/*
 * Name: Grant Johnson, Ethan Sychangco
 * Email: Gmjohnson@scu.edu, Esychangco@scu.edu
 */
#ifndef CARD_H
#define CARD_H

#include <iostream> // Include necessary headers

namespace groupGE {
    typedef int rank_t;
    typedef int suit_t;

    class Card {
    public:
        Card(suit_t s = 0, rank_t r = 0): rank(r), suit(s) {}
        int getSuit() const { return suit; } // Define functions inline
        int getRank() const { return rank; }

    friend std::ostream& operator<<(std::ostream& os, const Card &c);

    operator int() const;
    friend bool operator< (const Card &c1, const Card &c2);

    void swap(Card &c1, Card &c2) {
        std::swap(c1.rank, c2.rank);
        std::swap(c1.suit, c2.suit);
    }

    private:
        rank_t rank;
        suit_t suit;
    };
}

#endif // CARD_H
