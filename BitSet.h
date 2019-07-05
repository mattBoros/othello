
#ifndef OTHELLO_BITSET_H
#define OTHELLO_BITSET_H

#include "Debug.h"

static const unsigned long long ONE = 1LL;
static const unsigned long long SHIFTED_ONES[64] = {
        ONE << (unsigned char) 0,
        ONE << (unsigned char) 1,
        ONE << (unsigned char) 2,
        ONE << (unsigned char) 3,
        ONE << (unsigned char) 4,
        ONE << (unsigned char) 5,
        ONE << (unsigned char) 6,
        ONE << (unsigned char) 7,
        ONE << (unsigned char) 8,
        ONE << (unsigned char) 9,
        ONE << (unsigned char) 10,
        ONE << (unsigned char) 11,
        ONE << (unsigned char) 12,
        ONE << (unsigned char) 13,
        ONE << (unsigned char) 14,
        ONE << (unsigned char) 15,
        ONE << (unsigned char) 16,
        ONE << (unsigned char) 17,
        ONE << (unsigned char) 18,
        ONE << (unsigned char) 19,
        ONE << (unsigned char) 20,
        ONE << (unsigned char) 21,
        ONE << (unsigned char) 22,
        ONE << (unsigned char) 23,
        ONE << (unsigned char) 24,
        ONE << (unsigned char) 25,
        ONE << (unsigned char) 26,
        ONE << (unsigned char) 27,
        ONE << (unsigned char) 28,
        ONE << (unsigned char) 29,
        ONE << (unsigned char) 30,
        ONE << (unsigned char) 31,
        ONE << (unsigned char) 32,
        ONE << (unsigned char) 33,
        ONE << (unsigned char) 34,
        ONE << (unsigned char) 35,
        ONE << (unsigned char) 36,
        ONE << (unsigned char) 37,
        ONE << (unsigned char) 38,
        ONE << (unsigned char) 39,
        ONE << (unsigned char) 40,
        ONE << (unsigned char) 41,
        ONE << (unsigned char) 42,
        ONE << (unsigned char) 43,
        ONE << (unsigned char) 44,
        ONE << (unsigned char) 45,
        ONE << (unsigned char) 46,
        ONE << (unsigned char) 47,
        ONE << (unsigned char) 48,
        ONE << (unsigned char) 49,
        ONE << (unsigned char) 50,
        ONE << (unsigned char) 51,
        ONE << (unsigned char) 52,
        ONE << (unsigned char) 53,
        ONE << (unsigned char) 54,
        ONE << (unsigned char) 55,
        ONE << (unsigned char) 56,
        ONE << (unsigned char) 57,
        ONE << (unsigned char) 58,
        ONE << (unsigned char) 59,
        ONE << (unsigned char) 60,
        ONE << (unsigned char) 61,
        ONE << (unsigned char) 62,
        ONE << (unsigned char) 63
};

static const unsigned long long INVERTED_SHIFTED_ONES[64] = {
        ~(ONE << (unsigned char) 0),
        ~(ONE << (unsigned char) 1),
        ~(ONE << (unsigned char) 2),
        ~(ONE << (unsigned char) 3),
        ~(ONE << (unsigned char) 4),
        ~(ONE << (unsigned char) 5),
        ~(ONE << (unsigned char) 6),
        ~(ONE << (unsigned char) 7),
        ~(ONE << (unsigned char) 8),
        ~(ONE << (unsigned char) 9),
        ~(ONE << (unsigned char) 10),
        ~(ONE << (unsigned char) 11),
        ~(ONE << (unsigned char) 12),
        ~(ONE << (unsigned char) 13),
        ~(ONE << (unsigned char) 14),
        ~(ONE << (unsigned char) 15),
        ~(ONE << (unsigned char) 16),
        ~(ONE << (unsigned char) 17),
        ~(ONE << (unsigned char) 18),
        ~(ONE << (unsigned char) 19),
        ~(ONE << (unsigned char) 20),
        ~(ONE << (unsigned char) 21),
        ~(ONE << (unsigned char) 22),
        ~(ONE << (unsigned char) 23),
        ~(ONE << (unsigned char) 24),
        ~(ONE << (unsigned char) 25),
        ~(ONE << (unsigned char) 26),
        ~(ONE << (unsigned char) 27),
        ~(ONE << (unsigned char) 28),
        ~(ONE << (unsigned char) 29),
        ~(ONE << (unsigned char) 30),
        ~(ONE << (unsigned char) 31),
        ~(ONE << (unsigned char) 32),
        ~(ONE << (unsigned char) 33),
        ~(ONE << (unsigned char) 34),
        ~(ONE << (unsigned char) 35),
        ~(ONE << (unsigned char) 36),
        ~(ONE << (unsigned char) 37),
        ~(ONE << (unsigned char) 38),
        ~(ONE << (unsigned char) 39),
        ~(ONE << (unsigned char) 40),
        ~(ONE << (unsigned char) 41),
        ~(ONE << (unsigned char) 42),
        ~(ONE << (unsigned char) 43),
        ~(ONE << (unsigned char) 44),
        ~(ONE << (unsigned char) 45),
        ~(ONE << (unsigned char) 46),
        ~(ONE << (unsigned char) 47),
        ~(ONE << (unsigned char) 48),
        ~(ONE << (unsigned char) 49),
        ~(ONE << (unsigned char) 50),
        ~(ONE << (unsigned char) 51),
        ~(ONE << (unsigned char) 52),
        ~(ONE << (unsigned char) 53),
        ~(ONE << (unsigned char) 54),
        ~(ONE << (unsigned char) 55),
        ~(ONE << (unsigned char) 56),
        ~(ONE << (unsigned char) 57),
        ~(ONE << (unsigned char) 58),
        ~(ONE << (unsigned char) 59),
        ~(ONE << (unsigned char) 60),
        ~(ONE << (unsigned char) 61),
        ~(ONE << (unsigned char) 62),
        ~(ONE << (unsigned char) 63)
};

class BitSet {
public:
    unsigned long long word;

    BitSet() : word(0LL) {
    }

    inline explicit BitSet(const unsigned long long word) : word(word) {
    }

    void inline set(const unsigned char bitIndex) {
        word |= (SHIFTED_ONES[bitIndex]);
    }

    void inline set(const unsigned char bitIndex, const bool value) {
//        long int t1 = TIME::getTime();
        if (value) {
            set(bitIndex);
        } else {
            clear(bitIndex);
        }
//        long int t2 = TIME::getTime();
//        TIME::bsSetTime += (t2 - t1);
    }

    void inline clear(const unsigned char bitIndex) {
        word &= INVERTED_SHIFTED_ONES[bitIndex];
    }

    bool inline get(const unsigned char bitIndex) const {
//        long int t1 = TIME::getTime();
//        const bool result = (word & (ONE << bitIndex)) != 0;
        const bool result = (word & (SHIFTED_ONES[bitIndex])) != 0;
//        long int t2 = TIME::getTime();
//        TIME::bsGetTime += (t2 - t1);
        return result;
    }

    BitSet inline clone() const {
        return BitSet(word);
    }
};

#endif //OTHELLO_BITSET_H
