
#ifndef OTHELLO_BITSET_H
#define OTHELLO_BITSET_H

#include "Debug.h"

static const unsigned long long LONG_LONG_ONE = 1LL;
static const unsigned long long SHIFTED_ONES[64] = {
        LONG_LONG_ONE << (unsigned char) 0,
        LONG_LONG_ONE << (unsigned char) 1,
        LONG_LONG_ONE << (unsigned char) 2,
        LONG_LONG_ONE << (unsigned char) 3,
        LONG_LONG_ONE << (unsigned char) 4,
        LONG_LONG_ONE << (unsigned char) 5,
        LONG_LONG_ONE << (unsigned char) 6,
        LONG_LONG_ONE << (unsigned char) 7,
        LONG_LONG_ONE << (unsigned char) 8,
        LONG_LONG_ONE << (unsigned char) 9,
        LONG_LONG_ONE << (unsigned char) 10,
        LONG_LONG_ONE << (unsigned char) 11,
        LONG_LONG_ONE << (unsigned char) 12,
        LONG_LONG_ONE << (unsigned char) 13,
        LONG_LONG_ONE << (unsigned char) 14,
        LONG_LONG_ONE << (unsigned char) 15,
        LONG_LONG_ONE << (unsigned char) 16,
        LONG_LONG_ONE << (unsigned char) 17,
        LONG_LONG_ONE << (unsigned char) 18,
        LONG_LONG_ONE << (unsigned char) 19,
        LONG_LONG_ONE << (unsigned char) 20,
        LONG_LONG_ONE << (unsigned char) 21,
        LONG_LONG_ONE << (unsigned char) 22,
        LONG_LONG_ONE << (unsigned char) 23,
        LONG_LONG_ONE << (unsigned char) 24,
        LONG_LONG_ONE << (unsigned char) 25,
        LONG_LONG_ONE << (unsigned char) 26,
        LONG_LONG_ONE << (unsigned char) 27,
        LONG_LONG_ONE << (unsigned char) 28,
        LONG_LONG_ONE << (unsigned char) 29,
        LONG_LONG_ONE << (unsigned char) 30,
        LONG_LONG_ONE << (unsigned char) 31,
        LONG_LONG_ONE << (unsigned char) 32,
        LONG_LONG_ONE << (unsigned char) 33,
        LONG_LONG_ONE << (unsigned char) 34,
        LONG_LONG_ONE << (unsigned char) 35,
        LONG_LONG_ONE << (unsigned char) 36,
        LONG_LONG_ONE << (unsigned char) 37,
        LONG_LONG_ONE << (unsigned char) 38,
        LONG_LONG_ONE << (unsigned char) 39,
        LONG_LONG_ONE << (unsigned char) 40,
        LONG_LONG_ONE << (unsigned char) 41,
        LONG_LONG_ONE << (unsigned char) 42,
        LONG_LONG_ONE << (unsigned char) 43,
        LONG_LONG_ONE << (unsigned char) 44,
        LONG_LONG_ONE << (unsigned char) 45,
        LONG_LONG_ONE << (unsigned char) 46,
        LONG_LONG_ONE << (unsigned char) 47,
        LONG_LONG_ONE << (unsigned char) 48,
        LONG_LONG_ONE << (unsigned char) 49,
        LONG_LONG_ONE << (unsigned char) 50,
        LONG_LONG_ONE << (unsigned char) 51,
        LONG_LONG_ONE << (unsigned char) 52,
        LONG_LONG_ONE << (unsigned char) 53,
        LONG_LONG_ONE << (unsigned char) 54,
        LONG_LONG_ONE << (unsigned char) 55,
        LONG_LONG_ONE << (unsigned char) 56,
        LONG_LONG_ONE << (unsigned char) 57,
        LONG_LONG_ONE << (unsigned char) 58,
        LONG_LONG_ONE << (unsigned char) 59,
        LONG_LONG_ONE << (unsigned char) 60,
        LONG_LONG_ONE << (unsigned char) 61,
        LONG_LONG_ONE << (unsigned char) 62,
        LONG_LONG_ONE << (unsigned char) 63
};

static const unsigned long long INVERTED_SHIFTED_ONES[64] = {
        ~(LONG_LONG_ONE << (unsigned char) 0),
        ~(LONG_LONG_ONE << (unsigned char) 1),
        ~(LONG_LONG_ONE << (unsigned char) 2),
        ~(LONG_LONG_ONE << (unsigned char) 3),
        ~(LONG_LONG_ONE << (unsigned char) 4),
        ~(LONG_LONG_ONE << (unsigned char) 5),
        ~(LONG_LONG_ONE << (unsigned char) 6),
        ~(LONG_LONG_ONE << (unsigned char) 7),
        ~(LONG_LONG_ONE << (unsigned char) 8),
        ~(LONG_LONG_ONE << (unsigned char) 9),
        ~(LONG_LONG_ONE << (unsigned char) 10),
        ~(LONG_LONG_ONE << (unsigned char) 11),
        ~(LONG_LONG_ONE << (unsigned char) 12),
        ~(LONG_LONG_ONE << (unsigned char) 13),
        ~(LONG_LONG_ONE << (unsigned char) 14),
        ~(LONG_LONG_ONE << (unsigned char) 15),
        ~(LONG_LONG_ONE << (unsigned char) 16),
        ~(LONG_LONG_ONE << (unsigned char) 17),
        ~(LONG_LONG_ONE << (unsigned char) 18),
        ~(LONG_LONG_ONE << (unsigned char) 19),
        ~(LONG_LONG_ONE << (unsigned char) 20),
        ~(LONG_LONG_ONE << (unsigned char) 21),
        ~(LONG_LONG_ONE << (unsigned char) 22),
        ~(LONG_LONG_ONE << (unsigned char) 23),
        ~(LONG_LONG_ONE << (unsigned char) 24),
        ~(LONG_LONG_ONE << (unsigned char) 25),
        ~(LONG_LONG_ONE << (unsigned char) 26),
        ~(LONG_LONG_ONE << (unsigned char) 27),
        ~(LONG_LONG_ONE << (unsigned char) 28),
        ~(LONG_LONG_ONE << (unsigned char) 29),
        ~(LONG_LONG_ONE << (unsigned char) 30),
        ~(LONG_LONG_ONE << (unsigned char) 31),
        ~(LONG_LONG_ONE << (unsigned char) 32),
        ~(LONG_LONG_ONE << (unsigned char) 33),
        ~(LONG_LONG_ONE << (unsigned char) 34),
        ~(LONG_LONG_ONE << (unsigned char) 35),
        ~(LONG_LONG_ONE << (unsigned char) 36),
        ~(LONG_LONG_ONE << (unsigned char) 37),
        ~(LONG_LONG_ONE << (unsigned char) 38),
        ~(LONG_LONG_ONE << (unsigned char) 39),
        ~(LONG_LONG_ONE << (unsigned char) 40),
        ~(LONG_LONG_ONE << (unsigned char) 41),
        ~(LONG_LONG_ONE << (unsigned char) 42),
        ~(LONG_LONG_ONE << (unsigned char) 43),
        ~(LONG_LONG_ONE << (unsigned char) 44),
        ~(LONG_LONG_ONE << (unsigned char) 45),
        ~(LONG_LONG_ONE << (unsigned char) 46),
        ~(LONG_LONG_ONE << (unsigned char) 47),
        ~(LONG_LONG_ONE << (unsigned char) 48),
        ~(LONG_LONG_ONE << (unsigned char) 49),
        ~(LONG_LONG_ONE << (unsigned char) 50),
        ~(LONG_LONG_ONE << (unsigned char) 51),
        ~(LONG_LONG_ONE << (unsigned char) 52),
        ~(LONG_LONG_ONE << (unsigned char) 53),
        ~(LONG_LONG_ONE << (unsigned char) 54),
        ~(LONG_LONG_ONE << (unsigned char) 55),
        ~(LONG_LONG_ONE << (unsigned char) 56),
        ~(LONG_LONG_ONE << (unsigned char) 57),
        ~(LONG_LONG_ONE << (unsigned char) 58),
        ~(LONG_LONG_ONE << (unsigned char) 59),
        ~(LONG_LONG_ONE << (unsigned char) 60),
        ~(LONG_LONG_ONE << (unsigned char) 61),
        ~(LONG_LONG_ONE << (unsigned char) 62),
        ~(LONG_LONG_ONE << (unsigned char) 63)
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

//        if(value){
//            set(bitIndex);
//        } else {
//            clear(bitIndex);
//        }

        word = (word & INVERTED_SHIFTED_ONES[bitIndex]) | (static_cast<unsigned long long>(value) << bitIndex);

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
