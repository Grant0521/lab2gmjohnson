/*
 * Name: Grant Johnson, Ethan Sychangco
 * Email: Gmjohnson@scu.edu, Esychangco@scu.edu
 */
#include <iostream>
#include "card.h"
using namespace groupGE;

// Stand-alone Card definitions
namespace groupGE{
    std::ostream& operator<<(std::ostream& os, const Card &c) {
        std::string faces[4] = {"J", "Q", "K", "A"};
        if (c.rank <= 10){
            os << c.rank;
        }
        else {
            os << faces[c.rank - 11];
        }

        // 1, 2, 3, 4
        std::string suits[4] = {"♠", "♥", "♦", "♣"};
        os << suits[c.suit - 1];

        return os;
    }

    Card::operator int() const {
        return suit * rank;
    }

    bool operator< (const Card &c1, const Card &c2) {
        return int(c1) < int(c2);
    }
}