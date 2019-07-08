
#ifndef OTHELLO_STATE_H
#define OTHELLO_STATE_H


#include "BitSet.h"
#include "Piece.h"
#include "Debug.h"

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

namespace Helpers {
    static inline bool getFromBoard(const uint8_t x, const uint8_t y, const BitSet& bitSet) {
        return bitSet.get(INDEX_LOOKUP_TABLE[x][y]);
    }

    static inline void setOnBoard(const uint8_t x, const uint8_t y, BitSet &bitSet, const bool b) {
        bitSet.set(INDEX_LOOKUP_TABLE[x][y], b);
    }

    static inline void clearOnBoard(const uint8_t x, const uint8_t y, BitSet &bitSet) {
        bitSet.clear(INDEX_LOOKUP_TABLE[x][y]);
    }

    static inline void setOnBoard(const uint8_t x, const uint8_t y, BitSet &bitSet) {
        bitSet.set(INDEX_LOOKUP_TABLE[x][y]);
    }

    static inline bool getFromBoard(const uint8_t i, const BitSet &bitSet) {
        return bitSet.get(i);
    }

    static inline void setOnBoard(const uint8_t i, BitSet &bitSet, const bool b) {
        bitSet.set(i, b);
    }

    static inline void setOnBoard(const uint8_t i, BitSet &bitSet) {
        bitSet.set(i);
    }

}

class State {
public:
    const BitSet blackPieces;
    const BitSet whitePieces;
    const BitSet NOT_ORd_board;
    const uint8_t numBlack;
    const uint8_t numWhite;

    static inline BitSet NOT_OR_Bitsets(const BitSet b1, const BitSet b2){
        return BitSet(~(b1.word | b2.word));
//        BitSet newBS;
//        for (uint8_t i = 0; i < 64; ++i) {
//            newBS.set(i, b1.get(i) || b2.get(i));
//        }
//        return newBS;
    }

    inline State(
            const BitSet& blackPieces,
            const BitSet& whitePieces,
            const uint8_t numBlack,
            const uint8_t numWhite
            ) :
            blackPieces(blackPieces),
            whitePieces(whitePieces),
            NOT_ORd_board(NOT_OR_Bitsets(blackPieces, whitePieces)),
            numBlack(numBlack),
            numWhite(numWhite) {

    }

    bool inline isBlack(const uint8_t x, const uint8_t y) const {
        return Helpers::getFromBoard(x, y, blackPieces);
    }

    bool inline isWhite(const uint8_t x, const uint8_t y) const {
        return Helpers::getFromBoard(x, y, whitePieces);
    }

    bool inline isEmpty(const uint8_t x, const uint8_t y) const {
        return NOT_ORd_board.get(INDEX_LOOKUP_TABLE[x][y]);
    }

    bool inline isEmpty(const uint8_t i) const {
        return NOT_ORd_board.get(i);
    }

    bool inline isPiece(const uint8_t x, const uint8_t y, const bool piece) const {
        if (piece) { // piece == Piece::BLACK
            return isBlack(x, y);
        } else {
            return isWhite(x, y);
        }
    }

    char get_char(int i, int j) const {
        if (Helpers::getFromBoard(i, j, blackPieces)) {
            return 'B';
        }
        if (Helpers::getFromBoard(i, j, whitePieces)) {
            return 'W';
        }
        return '_';
    }

    void print() const {
        for (int j = 0; j < 8; ++j) {
            for (int i = 0; i < 8; ++i) {
                cout << get_char(i, j);
            }
            cout << endl;
        }
    }


};

namespace Helpers2 {
    static State *getStartingBoard() {
        BitSet &blackPieces = *(new BitSet());
        BitSet &whitePieces = *(new BitSet());

        Helpers::setOnBoard(3, 3, whitePieces, true);
        Helpers::setOnBoard(4, 4, whitePieces, true);
        Helpers::setOnBoard(3, 4, blackPieces, true);
        Helpers::setOnBoard(4, 3, blackPieces, true);

        return new State(blackPieces,
                whitePieces,
                2,
                2
                );
    }

    static State *getBoard(const unsigned long long blackPieces, const unsigned long long whitePieces) {
        const BitSet &blackPiecesBS = *(new BitSet(blackPieces));
        const BitSet &whitePiecesBS = *(new BitSet(whitePieces));
        uint8_t numBlack = 0;
        uint8_t numWhite = 0;

        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (Helpers::getFromBoard(i, j, blackPiecesBS)) {
                    ++numBlack;
                }
                if (Helpers::getFromBoard(i, j, whitePiecesBS)) {
                    ++numWhite;
                }

            }
        }

        return new State(blackPiecesBS,
                whitePiecesBS,
                numBlack,
                numWhite
                );
    }
}

#endif //OTHELLO_STATE_H
