
#ifndef OTHELLO_STATE_H
#define OTHELLO_STATE_H


#include "BitSet.h"
#include "Piece.h"
#include "Debug.h"


class State {
public:
    const BitSet blackPieces;
    const BitSet whitePieces;
    const BitSet ORd_board;
    const uint8_t numBlack;
    const uint8_t numWhite;

    inline State(
            const BitSet blackPieces,
            const BitSet whitePieces,
            const uint8_t numBlack,
            const uint8_t numWhite
            ) :
            blackPieces(blackPieces),
            whitePieces(whitePieces),
            ORd_board(BitSet(blackPieces.word | whitePieces.word)),
            numBlack(numBlack),
            numWhite(numWhite) {

    }

    inline State(
            const BitSet blackPieces,
            const BitSet whitePieces,
            const BitSet ORd_board,
            const uint8_t numBlack,
            const uint8_t numWhite
    ) :
            blackPieces(blackPieces),
            whitePieces(whitePieces),
            ORd_board(ORd_board),
            numBlack(numBlack),
            numWhite(numWhite) {

    }

    bool inline isBlack(const uint8_t x, const uint8_t y) const {
        return blackPieces.get(x, y);
    }

    bool inline isWhite(const uint8_t x, const uint8_t y) const {
        return whitePieces.get(x, y);
    }

    bool inline hasPiece(const uint8_t i) const {
        return ORd_board.get(i);
    }

    bool inline hasPiece(const uint8_t x, const uint8_t y) const {
        return ORd_board.get(INDEX_LOOKUP_TABLE[x][y]);
    }

    bool inline isEmpty(const uint8_t x, const uint8_t y) const {
        return !ORd_board.get(INDEX_LOOKUP_TABLE[x][y]);
    }

    bool inline isEmpty(const uint8_t i) const {
        return !ORd_board.get(i);
    }

    template <const bool piece>
    bool inline isPiece(const uint8_t x, const uint8_t y) const {
        if (piece) { // piece == Piece::BLACK
            return isBlack(x, y);
        } else {
            return isWhite(x, y);
        }
    }

    char get_char(int i, int j) const {
        if (blackPieces.get(i, j)) {
            return 'B';
        }
        if (whitePieces.get(i, j)) {
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

        whitePieces.setXY(3, 3);
        whitePieces.setXY(4, 4);
        blackPieces.setXY(3, 4);
        blackPieces.setXY(4, 3);

        return new State(blackPieces,
                whitePieces,
                2,
                2
                );
    }

    static const State getBoard(const unsigned long long blackPieces, const unsigned long long whitePieces) {
        const BitSet &blackPiecesBS = *(new BitSet(blackPieces));
        const BitSet &whitePiecesBS = *(new BitSet(whitePieces));
        uint8_t numBlack = 0;
        uint8_t numWhite = 0;

        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (blackPiecesBS.get(i, j)) {
                    ++numBlack;
                }
                if (whitePiecesBS.get(i, j)) {
                    ++numWhite;
                }

            }
        }

        return State(blackPiecesBS,
                whitePiecesBS,
                numBlack,
                numWhite
                );
    }
}

#endif //OTHELLO_STATE_H
