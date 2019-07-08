
#ifndef OTHELLO_UTIL_H
#define OTHELLO_UTIL_H

#include "AlphaBeta.h"
#include "Debug.h"
#include "State.h"


static const uint8_t ONE_UINT8 = (uint8_t) 1;
static const uint8_t ZERO_UINT8 = (uint8_t) 0;

//boolToUnsigned8BitInt(hasUpRightSurround(state, startX, startY, opp)) |
//(boolToUnsigned8BitInt(hasUpLeftSurround(state, startX, startY, opp)) << 1u) |
//(boolToUnsigned8BitInt(hasDownRightSurround(state, startX, startY, opp)) << 2u) |
//(boolToUnsigned8BitInt(hasDownLeftSurround(state, startX, startY, opp)) << 3u) |
//(boolToUnsigned8BitInt(hasUpSurround(state, startX, startY, opp)) << 4u) |
//(boolToUnsigned8BitInt(hasDownSurround(state, startX, startY, opp)) << 5u) |
//(boolToUnsigned8BitInt(hasLeftSurround(state, startX, startY, opp)) << 6u) |
//(boolToUnsigned8BitInt(hasRightSurround(state, startX, startY, opp)) << 7u);

static const uint8_t HAS_UP_RIGHT_SURROUND = ONE_UINT8 << 0u;
static const uint8_t HAS_UP_LEFT_SURROUND = ONE_UINT8 << 1u;
static const uint8_t HAS_DOWN_RIGHT_SURROUND = ONE_UINT8 << 2u;
static const uint8_t HAS_DOWN_LEFT_SURROUND = ONE_UINT8 << 3u;
static const uint8_t HAS_UP_SURROUND = ONE_UINT8 << 4u;
static const uint8_t HAS_DOWN_SURROUND = ONE_UINT8 << 5u;
static const uint8_t HAS_LEFT_SURROUND = ONE_UINT8 << 6u;
static const uint8_t HAS_RIGHT_SURROUND = ONE_UINT8 << 7u;


namespace Util {

    static inline bool hasUpSurround(const State &state, const uint8_t startX, const uint8_t startY,
                                     const bool opposite_piece) {
        uint8_t y = startY + 1;
        while (y < 8 && state.isPiece(startX, y, opposite_piece)) {
            ++y;
        }
//        return !(y >= 8 || state.isEmpty(startX, y)) && y - startY - 1 != 0;
        if (y >= 8 || state.isEmpty(startX, y)) {
            return false;
        }
        const uint8_t streak = y - startY - 1;
        return streak;// != 0;
    }

    static inline bool hasDownSurround(const State &state, const uint8_t startX, const uint8_t startY,
                                       const bool opposite_piece) {
        int8_t y = startY - 1;
        while (y >= 0 && state.isPiece(startX, y, opposite_piece)) {
            --y;
        }
//        return !(y < 0 || state.isEmpty(startX, y)) && startY - y - 1 != 0;
        if (y < 0 || state.isEmpty(startX, y)) {
            return false;
        }
        const int8_t streak = startY - y - 1;
        return streak;// != 0;
    }

    static inline bool hasLeftSurround(const State &state, const uint8_t startX, const uint8_t startY,
                                       const bool opposite_piece) {
        int8_t x = startX - 1;
        while (x >= 0 && state.isPiece(x, startY, opposite_piece)) {
            --x;
        }
//        return !(x < 0 || state.isEmpty(x, startY)) && startX - x - 1 != 0;
        if (x < 0 || state.isEmpty(x, startY)) {
            return false;
        }
        const int8_t streak = startX - x - 1;
        return streak;// != 0;
    }

    static inline bool hasRightSurround(const State &state, const uint8_t startX, const uint8_t startY,
                                        const bool opposite_piece) {
        uint8_t x = startX + 1;
        while (x < 8 && state.isPiece(x, startY, opposite_piece)) {
            ++x;
        }
//        return !(x >= 8 || state.isEmpty(x, startY)) && x - startX - 1 != 0;
        if (x >= 8 || state.isEmpty(x, startY)) {
            return false;
        }
        const int8_t streak = x - startX - 1;
        return streak;// != 0;
    }

    static inline bool hasUpRightSurround(const State &state, const uint8_t startX, const uint8_t startY,
                                          const bool opposite_piece) {
        uint8_t x = startX + 1;
        uint8_t y = startY + 1;
        while (x < 8 && y < 8 && state.isPiece(x, y, opposite_piece)) {
            ++x;
            ++y;
        }
//        return !(y >= 8 || x >= 8 || state.isEmpty(x, y)) && y - startY - 1 != 0;
        if (y >= 8 || x >= 8 || state.isEmpty(x, y)) {
            return false;
        }
        const int8_t streak = y - startY - 1;
        return streak;// != 0;
    }

    static inline bool hasUpLeftSurround(const State &state, const uint8_t startX, const uint8_t startY,
                                         const bool opposite_piece) {
        int8_t x = startX - 1;
        uint8_t y = startY + 1;
        while (x >= 0 && y < 8 && state.isPiece(x, y, opposite_piece)) {
            --x;
            ++y;
        }
//        return !(y >= 8 || x < 0 || state.isEmpty(x, y)) && y - startY - 1 != 0;
        if (y >= 8 || x < 0 || state.isEmpty(x, y)) {
            return false;
        }
        const int8_t streak = y - startY - 1;
        return streak;// != 0;
    }

    static inline bool hasDownRightSurround(const State &state, const uint8_t startX, const uint8_t startY,
                                            const bool opposite_piece) {
        uint8_t x = startX + 1;
        int8_t y = startY - 1;
        while (x < 8 && y >= 0 && state.isPiece(x, y, opposite_piece)) {
            ++x;
            --y;
        }
//        return !(y < 0 || x >= 8 || state.isEmpty(x, y)) && startY - y - 1 != 0;
        if (y < 0 || x >= 8 || state.isEmpty(x, y)) {
            return false;
        }
        const int8_t streak = startY - y - 1;
        return streak;// != 0;
    }

    static inline bool hasDownLeftSurround(const State &state,
                                           const uint8_t startX,
                                           const uint8_t startY,
                                           const bool opposite_piece) {
        int8_t x = startX - 1;
        int8_t y = startY - 1;
        while (x >= 0 && y >= 0 && state.isPiece(x, y, opposite_piece)) {
            --x;
            --y;
        }
//        return !(x < 0 || y < 0 || state.isEmpty(x, y)) && startY - y - 1 != 0;
        if (x < 0 || y < 0 || state.isEmpty(x, y)) {
            return false;
        }
        const int8_t streak = startY - y - 1;
        return streak;// != 0;
    }

    static inline uint8_t boolToUnsigned8BitInt(const bool b) {
        return static_cast<uint8_t>(b);
    }

    static inline uint8_t
    getSurroundInfo(const State &state, const uint8_t startX, const uint8_t startY, const bool opp) {
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
    isColor(const uint8_t x, const uint8_t y, const BitSet &blackPieces, const BitSet &whitePieces,
            const bool color) {
        if (color) { // color == Piece::BLACK
            return Helpers::getFromBoard(x, y, blackPieces);
        } else {
            return Helpers::getFromBoard(x, y, whitePieces);
        }
    }

    static inline void flipColor(const uint8_t x, const uint8_t y, BitSet &blackPieces, BitSet &whitePieces,
                                 const bool piece) {
        if (piece) { // piece == Piece::BLACK
            Helpers::setOnBoard(x, y, blackPieces);
            Helpers::clearOnBoard(x, y, whitePieces);
        } else {
            Helpers::setOnBoard(x, y, whitePieces);
            Helpers::clearOnBoard(x, y, blackPieces);
        }
    }


    const inline State applyAction(const State &state,
                                   const uint8_t xIndex,
                                   const uint8_t yIndex,
                                   const bool piece,
                                   const uint8_t info,
                                   const uint8_t i) {
//        long int t1 = TIME::getTime();

        BitSet blackPieces = state.blackPieces.clone();
        BitSet whitePieces = state.whitePieces.clone();

        if (piece) { // piece == Piece::BLACK
            Helpers::setOnBoard(i, blackPieces);
        } else {
            Helpers::setOnBoard(i, whitePieces);
        }

        const bool opposite_piece = !piece;

        uint8_t numFlipped = 0;
        uint8_t x;
        uint8_t y;

        if (info & HAS_UP_SURROUND) {
            y = yIndex + 1;
            while (isColor(xIndex, y, blackPieces, whitePieces, opposite_piece)) {
                flipColor(xIndex, y, blackPieces, whitePieces, piece);
                ++y;
                ++numFlipped;
            }
        }
        if (info & HAS_DOWN_SURROUND) {
            y = yIndex - 1;
            while (isColor(xIndex, y, blackPieces, whitePieces, opposite_piece)) {
                flipColor(xIndex, y, blackPieces, whitePieces, piece);
                --y;
                ++numFlipped;
            }
        }
        if (info & HAS_LEFT_SURROUND) {
            x = xIndex - 1;
            while (isColor(x, yIndex, blackPieces, whitePieces, opposite_piece)) {
                flipColor(x, yIndex, blackPieces, whitePieces, piece);
                --x;
                ++numFlipped;
            }
        }
        if (info & HAS_RIGHT_SURROUND) {
            x = xIndex + 1;
            while (isColor(x, yIndex, blackPieces, whitePieces, opposite_piece)) {
                flipColor(x, yIndex, blackPieces, whitePieces, piece);
                ++x;
                ++numFlipped;
            }
        }
        if (info & HAS_UP_RIGHT_SURROUND) {
            x = xIndex + 1;
            y = yIndex + 1;
            while (isColor(x, y, blackPieces, whitePieces, opposite_piece)) {
                flipColor(x, y, blackPieces, whitePieces, piece);
                ++x;
                ++y;
                ++numFlipped;
            }
        }
        if (info & HAS_UP_LEFT_SURROUND) {
            x = xIndex - 1;
            y = yIndex + 1;
            while (isColor(x, y, blackPieces, whitePieces, opposite_piece)) {
                flipColor(x, y, blackPieces, whitePieces, piece);
                --x;
                ++y;
                ++numFlipped;
            }
        }
        if (info & HAS_DOWN_RIGHT_SURROUND) {
            x = xIndex + 1;
            y = yIndex - 1;
            while (isColor(x, y, blackPieces, whitePieces, opposite_piece)) {
                flipColor(x, y, blackPieces, whitePieces, piece);
                ++x;
                --y;
                ++numFlipped;
            }
        }
        if (info & HAS_DOWN_LEFT_SURROUND) {
            x = xIndex - 1;
            y = yIndex - 1;
            while (isColor(x, y, blackPieces, whitePieces, opposite_piece)) {
                flipColor(x, y, blackPieces, whitePieces, piece);
                --x;
                --y;
                ++numFlipped;
            }
        }

        return State(blackPieces,
                     whitePieces,
                     piece * (state.numBlack + 1 + numFlipped) + opposite_piece * (state.numBlack - numFlipped),
                     piece * (state.numWhite - numFlipped) + opposite_piece * (state.numWhite + 1 + numFlipped));

//        if(piece){
//            return State(blackPieces,
//                         whitePieces,
//                         state.numBlack + 1 + numFlipped,
//                         state.numWhite - numFlipped);
//        } else {
//            return State(blackPieces,
//                         whitePieces,
//                         state.numBlack - numFlipped,
//                         state.numWhite + 1 + numFlipped);
//        }
    }


    static inline int8_t min(const int8_t f1, const int8_t f2) {
        return f2 < f1 ? f2 : f1;
    }

    static inline int8_t max(const int8_t f1, const int8_t f2) {
        return f2 > f1 ? f2 : f1;
    }

}


#endif //OTHELLO_UTIL_H
