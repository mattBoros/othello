
#ifndef OTHELLO_UTIL_H
#define OTHELLO_UTIL_H

#include "AlphaBeta.h"
#include "Debug.h"
#include "State.h"


static const uint8_t ONE_UINT8 = (uint8_t) 1;
static const uint8_t ZERO_UINT8 = (uint8_t) 0;

static const uint8_t SHIFTED_UINT8_ONES[8] = {
        ONE_UINT8 << 0u,
        ONE_UINT8 << 1u,
        ONE_UINT8 << 2u,
        ONE_UINT8 << 3u,
        ONE_UINT8 << 4u,
        ONE_UINT8 << 5u,
        ONE_UINT8 << 6u,
        ONE_UINT8 << 7u
};

namespace Util {

    static inline bool hasUpSurround(const State &state, const unsigned char startX, const unsigned char startY,
                                     const bool opposite_piece) {
        unsigned char y = startY + 1;
        while (y < 8 && state.isPiece(startX, y, opposite_piece)) {
            ++y;
        }
//        return !(y >= 8 || state.isEmpty(startX, y)) && y - startY - 1 != 0;
        if (y >= 8 || state.isEmpty(startX, y)) {
            return false;
        }
        const unsigned char streak = y - startY - 1;
        return streak;// != 0;
    }

    static inline bool hasDownSurround(const State &state, const unsigned char startX, const unsigned char startY,
                                       const bool opposite_piece) {
        signed char y = startY - 1;
        while (y >= 0 && state.isPiece(startX, y, opposite_piece)) {
            --y;
        }
//        return !(y < 0 || state.isEmpty(startX, y)) && startY - y - 1 != 0;
        if (y < 0 || state.isEmpty(startX, y)) {
            return false;
        }
        const signed char streak = startY - y - 1;
        return streak;// != 0;
    }

    static inline bool hasLeftSurround(const State &state, const unsigned char startX, const unsigned char startY,
                                       const bool opposite_piece) {
        signed char x = startX - 1;
        while (x >= 0 && state.isPiece(x, startY, opposite_piece)) {
            --x;
        }
//        return !(x < 0 || state.isEmpty(x, startY)) && startX - x - 1 != 0;
        if (x < 0 || state.isEmpty(x, startY)) {
            return false;
        }
        const signed char streak = startX - x - 1;
        return streak;// != 0;
    }

    static inline bool hasRightSurround(const State &state, const unsigned char startX, const unsigned char startY,
                                        const bool opposite_piece) {
        unsigned char x = startX + 1;
        while (x < 8 && state.isPiece(x, startY, opposite_piece)) {
            ++x;
        }
//        return !(x >= 8 || state.isEmpty(x, startY)) && x - startX - 1 != 0;
        if (x >= 8 || state.isEmpty(x, startY)) {
            return false;
        }
        const signed char streak = x - startX - 1;
        return streak;// != 0;
    }

    static inline bool hasUpRightSurround(const State &state, const unsigned char startX, const unsigned char startY,
                                          const bool opposite_piece) {
        unsigned char x = startX + 1;
        unsigned char y = startY + 1;
        while (x < 8 && y < 8 && state.isPiece(x, y, opposite_piece)) {
            ++x;
            ++y;
        }
//        return !(y >= 8 || x >= 8 || state.isEmpty(x, y)) && y - startY - 1 != 0;
        if (y >= 8 || x >= 8 || state.isEmpty(x, y)) {
            return false;
        }
        const signed char streak = y - startY - 1;
        return streak;// != 0;
    }

    static inline bool hasUpLeftSurround(const State &state, const unsigned char startX, const unsigned char startY,
                                         const bool opposite_piece) {
        signed char x = startX - 1;
        unsigned char y = startY + 1;
        while (x >= 0 && y < 8 && state.isPiece(x, y, opposite_piece)) {
            --x;
            ++y;
        }
//        return !(y >= 8 || x < 0 || state.isEmpty(x, y)) && y - startY - 1 != 0;
        if (y >= 8 || x < 0 || state.isEmpty(x, y)) {
            return false;
        }
        const signed char streak = y - startY - 1;
        return streak;// != 0;
    }

    static inline bool hasDownRightSurround(const State &state, const unsigned char startX, const unsigned char startY,
                                            const bool opposite_piece) {
        unsigned char x = startX + 1;
        signed char y = startY - 1;
        while (x < 8 && y >= 0 && state.isPiece(x, y, opposite_piece)) {
            ++x;
            --y;
        }
//        return !(y < 0 || x >= 8 || state.isEmpty(x, y)) && startY - y - 1 != 0;
        if (y < 0 || x >= 8 || state.isEmpty(x, y)) {
            return false;
        }
        const signed char streak = startY - y - 1;
        return streak;// != 0;
    }

    static inline bool hasDownLeftSurround(const State &state,
                                           const unsigned char startX,
                                           const unsigned char startY,
                                           const bool opposite_piece) {
        signed char x = startX - 1;
        signed char y = startY - 1;
        while (x >= 0 && y >= 0 && state.isPiece(x, y, opposite_piece)) {
            --x;
            --y;
        }
//        return !(x < 0 || y < 0 || state.isEmpty(x, y)) && startY - y - 1 != 0;
        if (x < 0 || y < 0 || state.isEmpty(x, y)) {
            return false;
        }
        const signed char streak = startY - y - 1;
        return streak;// != 0;
    }

    static inline uint8_t boolToUnsigned8BitInt(const bool b) {
        return b ? ONE_UINT8 : ZERO_UINT8;
    }

    static inline uint8_t
    getSurroundInfo(const State &state, const unsigned char startX, const unsigned char startY, const bool opp) {
//        return boolToUnsigned8BitInt(hasUpRightSurround(state, startX, startY, opp)) |
//               (boolToUnsigned8BitInt(hasUpLeftSurround(state, startX, startY, opp)) << 1u) |
//               (boolToUnsigned8BitInt(hasDownRightSurround(state, startX, startY, opp)) << 2u) |
//               (boolToUnsigned8BitInt(hasDownLeftSurround(state, startX, startY, opp)) << 3u) |
//               (boolToUnsigned8BitInt(hasUpSurround(state, startX, startY, opp)) << 4u) |
//               (boolToUnsigned8BitInt(hasDownSurround(state, startX, startY, opp)) << 5u) |
//               (boolToUnsigned8BitInt(hasLeftSurround(state, startX, startY, opp)) << 6u) |
//               (boolToUnsigned8BitInt(hasRightSurround(state, startX, startY, opp)) << 7u);
        const bool x1 = startX <= 1;
        const bool y1 = startY <= 1;

        if (x1 && y1) {
            return boolToUnsigned8BitInt(hasUpRightSurround(state, startX, startY, opp)) |
                   (boolToUnsigned8BitInt(hasUpLeftSurround(state, startX, startY, opp)) << 1u) |
                   (boolToUnsigned8BitInt(hasDownRightSurround(state, startX, startY, opp)) << 2u) |
                   (boolToUnsigned8BitInt(hasUpSurround(state, startX, startY, opp)) << 4u) |
                   (boolToUnsigned8BitInt(hasRightSurround(state, startX, startY, opp)) << 7u);
        }
        const bool y6 = startY >= 6;
        if (x1 && y6) {
            return boolToUnsigned8BitInt(hasUpRightSurround(state, startX, startY, opp)) |
                   (boolToUnsigned8BitInt(hasDownRightSurround(state, startX, startY, opp)) << 2u) |
                   (boolToUnsigned8BitInt(hasDownLeftSurround(state, startX, startY, opp)) << 3u) |
                   (boolToUnsigned8BitInt(hasDownSurround(state, startX, startY, opp)) << 5u) |
                   (boolToUnsigned8BitInt(hasRightSurround(state, startX, startY, opp)) << 7u);
        }
        const bool x6 = startX >= 6;
        if (x6 && y6) {
            return
                    boolToUnsigned8BitInt(hasUpRightSurround(state, startX, startY, opp)) |
                    (boolToUnsigned8BitInt(hasUpLeftSurround(state, startX, startY, opp)) << 1u) |
                    (boolToUnsigned8BitInt(hasDownLeftSurround(state, startX, startY, opp)) << 3u) |
                    (boolToUnsigned8BitInt(hasDownSurround(state, startX, startY, opp)) << 5u) |
                    (boolToUnsigned8BitInt(hasLeftSurround(state, startX, startY, opp)) << 6u);
        }
        if (x6 && y1) {
            return
                    boolToUnsigned8BitInt(hasUpLeftSurround(state, startX, startY, opp) << 1u) |
                    (boolToUnsigned8BitInt(hasDownRightSurround(state, startX, startY, opp)) << 2u) |
                    (boolToUnsigned8BitInt(hasDownLeftSurround(state, startX, startY, opp)) << 3u) |
                    (boolToUnsigned8BitInt(hasUpSurround(state, startX, startY, opp)) << 4u) |
                    (boolToUnsigned8BitInt(hasLeftSurround(state, startX, startY, opp)) << 6u);
        }
        if (x1) {
            return
                    boolToUnsigned8BitInt(hasUpRightSurround(state, startX, startY, opp)) |
                    (boolToUnsigned8BitInt(hasUpLeftSurround(state, startX, startY, opp)) << 1u) |
                    (boolToUnsigned8BitInt(hasDownRightSurround(state, startX, startY, opp)) << 2u) |
                    (boolToUnsigned8BitInt(hasDownLeftSurround(state, startX, startY, opp)) << 3u) |
                    (boolToUnsigned8BitInt(hasUpSurround(state, startX, startY, opp)) << 4u) |
                    (boolToUnsigned8BitInt(hasDownSurround(state, startX, startY, opp)) << 5u) |
                    (boolToUnsigned8BitInt(hasRightSurround(state, startX, startY, opp)) << 7u);
        }
        if (y1) {
            return
                    boolToUnsigned8BitInt(hasUpRightSurround(state, startX, startY, opp)) |
                    (boolToUnsigned8BitInt(hasUpLeftSurround(state, startX, startY, opp)) << 1u) |
                    (boolToUnsigned8BitInt(hasDownRightSurround(state, startX, startY, opp)) << 2u) |
                    (boolToUnsigned8BitInt(hasDownLeftSurround(state, startX, startY, opp)) << 3u) |
                    (boolToUnsigned8BitInt(hasUpSurround(state, startX, startY, opp)) << 4u) |
                    (boolToUnsigned8BitInt(hasLeftSurround(state, startX, startY, opp)) << 6u) |
                    (boolToUnsigned8BitInt(hasRightSurround(state, startX, startY, opp)) << 7u);
        }
        if (x6) {
            return
                    boolToUnsigned8BitInt(hasUpRightSurround(state, startX, startY, opp)) |
                    (boolToUnsigned8BitInt(hasUpLeftSurround(state, startX, startY, opp)) << 1u) |
                    (boolToUnsigned8BitInt(hasDownRightSurround(state, startX, startY, opp)) << 2u) |
                    (boolToUnsigned8BitInt(hasDownLeftSurround(state, startX, startY, opp)) << 3u) |
                    (boolToUnsigned8BitInt(hasUpSurround(state, startX, startY, opp)) << 4u) |
                    (boolToUnsigned8BitInt(hasDownSurround(state, startX, startY, opp)) << 5u) |
                    (boolToUnsigned8BitInt(hasLeftSurround(state, startX, startY, opp)) << 6u);
        }
        if (y6) {
            return
                    boolToUnsigned8BitInt(hasUpRightSurround(state, startX, startY, opp)) |
                    (boolToUnsigned8BitInt(hasUpLeftSurround(state, startX, startY, opp)) << 1u) |
                    (boolToUnsigned8BitInt(hasDownRightSurround(state, startX, startY, opp)) << 2u) |
                    (boolToUnsigned8BitInt(hasDownLeftSurround(state, startX, startY, opp)) << 3u) |
                    (boolToUnsigned8BitInt(hasDownSurround(state, startX, startY, opp)) << 5u) |
                    (boolToUnsigned8BitInt(hasLeftSurround(state, startX, startY, opp)) << 6u) |
                    (boolToUnsigned8BitInt(hasRightSurround(state, startX, startY, opp)) << 7u);
        }
        return
                boolToUnsigned8BitInt(hasUpRightSurround(state, startX, startY, opp)) |
                (boolToUnsigned8BitInt(hasUpLeftSurround(state, startX, startY, opp)) << 1u) |
                (boolToUnsigned8BitInt(hasDownRightSurround(state, startX, startY, opp)) << 2u) |
                (boolToUnsigned8BitInt(hasDownLeftSurround(state, startX, startY, opp)) << 3u) |
                (boolToUnsigned8BitInt(hasUpSurround(state, startX, startY, opp)) << 4u) |
                (boolToUnsigned8BitInt(hasDownSurround(state, startX, startY, opp)) << 5u) |
                (boolToUnsigned8BitInt(hasLeftSurround(state, startX, startY, opp)) << 6u) |
                (boolToUnsigned8BitInt(hasRightSurround(state, startX, startY, opp)) << 7u);
    }

    static bool inline
    isColor(const unsigned char x, const unsigned char y, const BitSet &blackPieces, const BitSet &whitePieces,
            const bool color) {
        if (color) { // color == Piece::BLACK
            return Helpers::getFromBoard(x, y, blackPieces);
        } else {
            return Helpers::getFromBoard(x, y, whitePieces);
        }
    }

    static inline void flipColor(const unsigned char x, const unsigned char y, BitSet &blackPieces, BitSet &whitePieces,
                                 const bool piece) {
        if (piece) { // piece == Piece::BLACK
            Helpers::setOnBoard(x, y, blackPieces, true);
            Helpers::setOnBoard(x, y, whitePieces, false);
        } else {
            Helpers::setOnBoard(x, y, whitePieces, true);
            Helpers::setOnBoard(x, y, blackPieces, false);
        }
    }


    const inline State applyAction(const State &state,
                                   const unsigned char xIndex,
                                   const unsigned char yIndex,
                                   const bool piece,
                                   const uint8_t info,
                                   const unsigned char i) {
//        long int t1 = TIME::getTime();

        BitSet blackPieces = state.blackPieces.clone();
        BitSet whitePieces = state.whitePieces.clone();

        if (piece) { // piece == Piece::BLACK
            Helpers::setOnBoard(i, blackPieces, true);
        } else {
            Helpers::setOnBoard(i, whitePieces, true);
        }

        const bool opposite_piece = !piece;

        unsigned char numFlipped = 0;
        unsigned char x;
        unsigned char y;

//        boolToUnsigned8BitInt(hasUpRightSurround(state, startX, startY, opp)) |
//        (boolToUnsigned8BitInt(hasUpLeftSurround(state, startX, startY, opp)) << 1u) |
//        (boolToUnsigned8BitInt(hasDownRightSurround(state, startX, startY, opp)) << 2u) |
//        (boolToUnsigned8BitInt(hasDownLeftSurround(state, startX, startY, opp)) << 3u) |
//        (boolToUnsigned8BitInt(hasUpSurround(state, startX, startY, opp)) << 4u) |
//        (boolToUnsigned8BitInt(hasDownSurround(state, startX, startY, opp)) << 5u) |
//        (boolToUnsigned8BitInt(hasLeftSurround(state, startX, startY, opp)) << 6u) |
//        (boolToUnsigned8BitInt(hasRightSurround(state, startX, startY, opp)) << 7u)

        if (info & SHIFTED_UINT8_ONES[4]) {
            y = yIndex + 1;
            while (isColor(xIndex, y, blackPieces, whitePieces, opposite_piece)) {
                flipColor(xIndex, y, blackPieces, whitePieces, piece);
                ++y;
                ++numFlipped;
            }
        }
        if (info & SHIFTED_UINT8_ONES[5]) {
            y = yIndex - 1;
            while (isColor(xIndex, y, blackPieces, whitePieces, opposite_piece)) {
                flipColor(xIndex, y, blackPieces, whitePieces, piece);
                --y;
                ++numFlipped;
            }
        }
        if (info & SHIFTED_UINT8_ONES[6]) {
            x = xIndex - 1;
            while (isColor(x, yIndex, blackPieces, whitePieces, opposite_piece)) {
                flipColor(x, yIndex, blackPieces, whitePieces, piece);
                --x;
                ++numFlipped;
            }
        }
        if (info & SHIFTED_UINT8_ONES[7]) {
            x = xIndex + 1;
            while (isColor(x, yIndex, blackPieces, whitePieces, opposite_piece)) {
                flipColor(x, yIndex, blackPieces, whitePieces, piece);
                ++x;
                ++numFlipped;
            }
        }
        if (info & SHIFTED_UINT8_ONES[0]) {
            x = xIndex + 1;
            y = yIndex + 1;
            while (isColor(x, y, blackPieces, whitePieces, opposite_piece)) {
                flipColor(x, y, blackPieces, whitePieces, piece);
                ++x;
                ++y;
                ++numFlipped;
            }
        }
        if (info & SHIFTED_UINT8_ONES[1]) {
            x = xIndex - 1;
            y = yIndex + 1;
            while (isColor(x, y, blackPieces, whitePieces, opposite_piece)) {
                flipColor(x, y, blackPieces, whitePieces, piece);
                --x;
                ++y;
                ++numFlipped;
            }
        }
        if (info & SHIFTED_UINT8_ONES[2]) {
            x = xIndex + 1;
            y = yIndex - 1;
            while (isColor(x, y, blackPieces, whitePieces, opposite_piece)) {
                flipColor(x, y, blackPieces, whitePieces, piece);
                ++x;
                --y;
                ++numFlipped;
            }
        }
        if (info & SHIFTED_UINT8_ONES[3]) {
            x = xIndex - 1;
            y = yIndex - 1;
            while (isColor(x, y, blackPieces, whitePieces, opposite_piece)) {
                flipColor(x, y, blackPieces, whitePieces, piece);
                --x;
                --y;
                ++numFlipped;
            }
        }

        unsigned char num_black = state.numBlack;
        unsigned char num_white = state.numWhite;
        if (piece) { // piece == Piece::BLACK
            num_black += 1 + numFlipped;
            num_white -= numFlipped;
        } else {
            num_white += 1 + numFlipped;
            num_black -= numFlipped;
        }



//        long int t2 = TIME::getTime();
//        TIME::applyTime += (t2 - t1);
        return State(blackPieces,
                     whitePieces,
                     num_black,
                     num_white);
    }


    static inline signed char min(const signed char f1, const signed char f2) {
        return f2 < f1 ? f2 : f1;
    }

    static inline signed char max(const signed char f1, const signed char f2) {
        return f2 > f1 ? f2 : f1;
    }

}


#endif //OTHELLO_UTIL_H
