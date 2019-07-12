
#ifndef OTHELLO_BITSET_H
#define OTHELLO_BITSET_H

#include "Debug.h"

static const unsigned long long LONG_LONG_ONE = 1LL;
static const unsigned long long SHIFTED_ONES[64] = {
        LONG_LONG_ONE << (uint8_t) 0,
        LONG_LONG_ONE << (uint8_t) 1,
        LONG_LONG_ONE << (uint8_t) 2,
        LONG_LONG_ONE << (uint8_t) 3,
        LONG_LONG_ONE << (uint8_t) 4,
        LONG_LONG_ONE << (uint8_t) 5,
        LONG_LONG_ONE << (uint8_t) 6,
        LONG_LONG_ONE << (uint8_t) 7,
        LONG_LONG_ONE << (uint8_t) 8,
        LONG_LONG_ONE << (uint8_t) 9,
        LONG_LONG_ONE << (uint8_t) 10,
        LONG_LONG_ONE << (uint8_t) 11,
        LONG_LONG_ONE << (uint8_t) 12,
        LONG_LONG_ONE << (uint8_t) 13,
        LONG_LONG_ONE << (uint8_t) 14,
        LONG_LONG_ONE << (uint8_t) 15,
        LONG_LONG_ONE << (uint8_t) 16,
        LONG_LONG_ONE << (uint8_t) 17,
        LONG_LONG_ONE << (uint8_t) 18,
        LONG_LONG_ONE << (uint8_t) 19,
        LONG_LONG_ONE << (uint8_t) 20,
        LONG_LONG_ONE << (uint8_t) 21,
        LONG_LONG_ONE << (uint8_t) 22,
        LONG_LONG_ONE << (uint8_t) 23,
        LONG_LONG_ONE << (uint8_t) 24,
        LONG_LONG_ONE << (uint8_t) 25,
        LONG_LONG_ONE << (uint8_t) 26,
        LONG_LONG_ONE << (uint8_t) 27,
        LONG_LONG_ONE << (uint8_t) 28,
        LONG_LONG_ONE << (uint8_t) 29,
        LONG_LONG_ONE << (uint8_t) 30,
        LONG_LONG_ONE << (uint8_t) 31,
        LONG_LONG_ONE << (uint8_t) 32,
        LONG_LONG_ONE << (uint8_t) 33,
        LONG_LONG_ONE << (uint8_t) 34,
        LONG_LONG_ONE << (uint8_t) 35,
        LONG_LONG_ONE << (uint8_t) 36,
        LONG_LONG_ONE << (uint8_t) 37,
        LONG_LONG_ONE << (uint8_t) 38,
        LONG_LONG_ONE << (uint8_t) 39,
        LONG_LONG_ONE << (uint8_t) 40,
        LONG_LONG_ONE << (uint8_t) 41,
        LONG_LONG_ONE << (uint8_t) 42,
        LONG_LONG_ONE << (uint8_t) 43,
        LONG_LONG_ONE << (uint8_t) 44,
        LONG_LONG_ONE << (uint8_t) 45,
        LONG_LONG_ONE << (uint8_t) 46,
        LONG_LONG_ONE << (uint8_t) 47,
        LONG_LONG_ONE << (uint8_t) 48,
        LONG_LONG_ONE << (uint8_t) 49,
        LONG_LONG_ONE << (uint8_t) 50,
        LONG_LONG_ONE << (uint8_t) 51,
        LONG_LONG_ONE << (uint8_t) 52,
        LONG_LONG_ONE << (uint8_t) 53,
        LONG_LONG_ONE << (uint8_t) 54,
        LONG_LONG_ONE << (uint8_t) 55,
        LONG_LONG_ONE << (uint8_t) 56,
        LONG_LONG_ONE << (uint8_t) 57,
        LONG_LONG_ONE << (uint8_t) 58,
        LONG_LONG_ONE << (uint8_t) 59,
        LONG_LONG_ONE << (uint8_t) 60,
        LONG_LONG_ONE << (uint8_t) 61,
        LONG_LONG_ONE << (uint8_t) 62,
        LONG_LONG_ONE << (uint8_t) 63
};

static const unsigned long long INVERTED_SHIFTED_ONES[64] = {
        ~(LONG_LONG_ONE << (uint8_t) 0),
        ~(LONG_LONG_ONE << (uint8_t) 1),
        ~(LONG_LONG_ONE << (uint8_t) 2),
        ~(LONG_LONG_ONE << (uint8_t) 3),
        ~(LONG_LONG_ONE << (uint8_t) 4),
        ~(LONG_LONG_ONE << (uint8_t) 5),
        ~(LONG_LONG_ONE << (uint8_t) 6),
        ~(LONG_LONG_ONE << (uint8_t) 7),
        ~(LONG_LONG_ONE << (uint8_t) 8),
        ~(LONG_LONG_ONE << (uint8_t) 9),
        ~(LONG_LONG_ONE << (uint8_t) 10),
        ~(LONG_LONG_ONE << (uint8_t) 11),
        ~(LONG_LONG_ONE << (uint8_t) 12),
        ~(LONG_LONG_ONE << (uint8_t) 13),
        ~(LONG_LONG_ONE << (uint8_t) 14),
        ~(LONG_LONG_ONE << (uint8_t) 15),
        ~(LONG_LONG_ONE << (uint8_t) 16),
        ~(LONG_LONG_ONE << (uint8_t) 17),
        ~(LONG_LONG_ONE << (uint8_t) 18),
        ~(LONG_LONG_ONE << (uint8_t) 19),
        ~(LONG_LONG_ONE << (uint8_t) 20),
        ~(LONG_LONG_ONE << (uint8_t) 21),
        ~(LONG_LONG_ONE << (uint8_t) 22),
        ~(LONG_LONG_ONE << (uint8_t) 23),
        ~(LONG_LONG_ONE << (uint8_t) 24),
        ~(LONG_LONG_ONE << (uint8_t) 25),
        ~(LONG_LONG_ONE << (uint8_t) 26),
        ~(LONG_LONG_ONE << (uint8_t) 27),
        ~(LONG_LONG_ONE << (uint8_t) 28),
        ~(LONG_LONG_ONE << (uint8_t) 29),
        ~(LONG_LONG_ONE << (uint8_t) 30),
        ~(LONG_LONG_ONE << (uint8_t) 31),
        ~(LONG_LONG_ONE << (uint8_t) 32),
        ~(LONG_LONG_ONE << (uint8_t) 33),
        ~(LONG_LONG_ONE << (uint8_t) 34),
        ~(LONG_LONG_ONE << (uint8_t) 35),
        ~(LONG_LONG_ONE << (uint8_t) 36),
        ~(LONG_LONG_ONE << (uint8_t) 37),
        ~(LONG_LONG_ONE << (uint8_t) 38),
        ~(LONG_LONG_ONE << (uint8_t) 39),
        ~(LONG_LONG_ONE << (uint8_t) 40),
        ~(LONG_LONG_ONE << (uint8_t) 41),
        ~(LONG_LONG_ONE << (uint8_t) 42),
        ~(LONG_LONG_ONE << (uint8_t) 43),
        ~(LONG_LONG_ONE << (uint8_t) 44),
        ~(LONG_LONG_ONE << (uint8_t) 45),
        ~(LONG_LONG_ONE << (uint8_t) 46),
        ~(LONG_LONG_ONE << (uint8_t) 47),
        ~(LONG_LONG_ONE << (uint8_t) 48),
        ~(LONG_LONG_ONE << (uint8_t) 49),
        ~(LONG_LONG_ONE << (uint8_t) 50),
        ~(LONG_LONG_ONE << (uint8_t) 51),
        ~(LONG_LONG_ONE << (uint8_t) 52),
        ~(LONG_LONG_ONE << (uint8_t) 53),
        ~(LONG_LONG_ONE << (uint8_t) 54),
        ~(LONG_LONG_ONE << (uint8_t) 55),
        ~(LONG_LONG_ONE << (uint8_t) 56),
        ~(LONG_LONG_ONE << (uint8_t) 57),
        ~(LONG_LONG_ONE << (uint8_t) 58),
        ~(LONG_LONG_ONE << (uint8_t) 59),
        ~(LONG_LONG_ONE << (uint8_t) 60),
        ~(LONG_LONG_ONE << (uint8_t) 61),
        ~(LONG_LONG_ONE << (uint8_t) 62),
        ~(LONG_LONG_ONE << (uint8_t) 63)
};


static const uint8_t INDEX_LOOKUP_TABLE[8][8] = {
        {0, 1, 2, 3, 4, 5, 6, 7},
        {8, 9, 10, 11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20, 21, 22, 23},
        {24, 25, 26, 27, 28, 29, 30, 31},
        {32, 33, 34, 35, 36, 37, 38, 39},
        {40, 41, 42, 43, 44, 45, 46, 47},
        {48, 49, 50, 51, 52, 53, 54, 55},
        {56, 57, 58, 59, 60, 61, 62, 63},
};

class BitSet {
public:
    mutable unsigned long long word;

    BitSet() : word(0LL) {
    }

    inline explicit BitSet(const unsigned long long word) : word(word) {
    }

    void inline set(const uint8_t bitIndex) {
        word |= (SHIFTED_ONES[bitIndex]);
    }

    void inline set(const uint8_t bitIndex, const bool value) {
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

    void inline clear(const uint8_t bitIndex) {
        word &= INVERTED_SHIFTED_ONES[bitIndex];
    }

    inline bool get(const uint8_t x, const uint8_t y) const {
        return get(INDEX_LOOKUP_TABLE[x][y]);
    }

    bool inline get(const uint8_t bitIndex) const {
//        long int t1 = TIME::getTime();
//        const bool result = (word & (ONE << bitIndex)) != 0;
        const bool result = (word & (SHIFTED_ONES[bitIndex]));
//        long int t2 = TIME::getTime();
//        TIME::bsGetTime += (t2 - t1);
        return result;
    }

    inline void set(const uint8_t x, const uint8_t y, const bool b) {
        set(INDEX_LOOKUP_TABLE[x][y], b);
    }

    inline void clear(const uint8_t x, const uint8_t y) {
        clear(INDEX_LOOKUP_TABLE[x][y]);
    }

    inline void setXY(const uint8_t x, const uint8_t y) {
        set(INDEX_LOOKUP_TABLE[x][y]);
    }

    BitSet inline clone() const {
        return BitSet(word);
    }
};

#endif //OTHELLO_BITSET_H
