
#ifndef OTHELLO_UTIL_H
#define OTHELLO_UTIL_H

#include "AlphaBeta.h"
#include "Debug.h"
#include "State.h"

namespace Util {

    static inline bool hasUpSurround(const State &state, const unsigned char startX, const unsigned char startY,
                                    const bool opposite_piece) {
        unsigned char y = startY+1;
        while (y < 8 && state.isPiece(startX, y, opposite_piece)) {
            ++y;
        }
        if (y >= 8 || state.isEmpty(startX, y)) {
            return false;
        }
        const char streak = y - startY - 1;
        return streak != 0;
    }

    static inline bool hasDownSurround(const State &state, const unsigned char startX, const unsigned char startY,
                                      const bool opposite_piece) {
        char y = startY-1;
        while (y >= 0 && state.isPiece(startX, y, opposite_piece)) {
            --y;
        }
        if (y < 0 || state.isEmpty(startX, y)) {
            return false;
        }
        const char streak = startY - y - 1;
        return streak != 0;
    }

    static  inline bool hasLeftSurround(const State &state, const unsigned char startX, const unsigned char startY,
                                      const bool opposite_piece) {
        char x = startX-1;
        while (x >= 0 && state.isPiece(x, startY, opposite_piece)) {
            --x;
        }
        if (x < 0 || state.isEmpty(x, startY)) {
            return false;
        }
        const char streak = startX - x - 1;
        return streak != 0;
    }

    static inline bool hasRightSurround(const State &state, const unsigned char startX, const unsigned char startY,
                                       const bool opposite_piece) {
        unsigned char x = startX+1;
        while (x < 8 && state.isPiece(x, startY, opposite_piece)) {
            ++x;
        }
        if (x >= 8 || state.isEmpty(x, startY)) {
            return false;
        }
        const char streak = x - startX - 1;
        return streak != 0;
    }

    static inline bool hasUpRightSurround(const State &state, const unsigned char startX, const unsigned char startY,
                                         const bool opposite_piece) {
        unsigned char x = startX+1;
        unsigned char y = startY+1;
        while (x < 8 && y < 8 && state.isPiece(x, y, opposite_piece)) {
            ++x;
            ++y;
        }
        if (y >= 8 || x >= 8 || state.isEmpty(x, y)) {
            return false;
        }
        const char streak = y - startY - 1;
        return streak != 0;
    }

    static inline bool hasUpLeftSurround(const State &state, const unsigned char startX, const unsigned char startY,
                                        const bool opposite_piece) {
        char x = startX-1;
        unsigned char y = startY+1;
        while (x >= 0 && y < 8 && state.isPiece(x, y, opposite_piece)) {
            --x;
            ++y;
        }
        if (y >= 8 || x < 0 || state.isEmpty(x, y)) {
            return false;
        }
        const char streak = y - startY - 1;
        return streak != 0;
    }

    static inline bool hasDownRightSurround(const State &state, const unsigned char startX, const unsigned char startY,
                                           const bool opposite_piece) {
        unsigned char x = startX+1;
        char y = startY-1;
        while (x < 8 && y >= 0 && state.isPiece(x, y, opposite_piece)) {
            ++x;
            --y;
        }
        if (y < 0 || x >= 8 || state.isEmpty(x, y)) {
            return false;
        }
        const char streak = startY - y - 1;
        return streak != 0;
    }

    static inline bool hasDownLeftSurround(const State &state,
                                          const unsigned char startX,
                                          const unsigned char startY,
                                          const bool opposite_piece) {
        char x = startX-1;
        char y = startY-1;
        while (x >= 0 && y >= 0 && state.isPiece(x, y, opposite_piece)) {
            --x;
            --y;
        }
        if (x < 0 || y < 0 || state.isEmpty(x, y)) {
            return false;
        }
        const char streak = startY - y - 1;
        return streak != 0;
    }

    static bool inline
    hasAnySurround(const State &state, const unsigned char startX, const unsigned char startY, const bool opp) {
        const bool x1 = startX <= 1;
        const bool y1 = startY <= 1;

        if (x1 && y1) {
            return
                    hasUpRightSurround(state, startX, startY, opp) ||
                    hasUpLeftSurround(state, startX, startY, opp) ||
                    hasDownRightSurround(state, startX, startY, opp) ||
                    hasUpSurround(state, startX, startY, opp) ||
                    hasRightSurround(state, startX, startY, opp);
        }
        const bool y6 = startY >= 6;
        if (x1 && y6) {
            return
                    hasUpRightSurround(state, startX, startY, opp) ||
                    hasDownRightSurround(state, startX, startY, opp) ||
                    hasDownLeftSurround(state, startX, startY, opp) ||
                    hasDownSurround(state, startX, startY, opp) ||
                    hasRightSurround(state, startX, startY, opp);
        }
        const bool x6 = startX >= 6;
        if (x6 && y6) {
            return
                    hasUpRightSurround(state, startX, startY, opp) ||
                    hasUpLeftSurround(state, startX, startY, opp) ||
                    hasDownLeftSurround(state, startX, startY, opp) ||
                    hasDownSurround(state, startX, startY, opp) ||
                    hasLeftSurround(state, startX, startY, opp);
        }
        if (x6 && y1) {
            return
                    hasUpLeftSurround(state, startX, startY, opp) ||
                    hasDownRightSurround(state, startX, startY, opp) ||
                    hasDownLeftSurround(state, startX, startY, opp) ||
                    hasUpSurround(state, startX, startY, opp) ||
                    hasLeftSurround(state, startX, startY, opp);
        }
        if (x1) {
            return
                    hasUpRightSurround(state, startX, startY, opp) ||
                    hasUpLeftSurround(state, startX, startY, opp) ||
                    hasDownRightSurround(state, startX, startY, opp) ||
                    hasDownLeftSurround(state, startX, startY, opp) ||
                    hasUpSurround(state, startX, startY, opp) ||
                    hasDownSurround(state, startX, startY, opp) ||
                    hasRightSurround(state, startX, startY, opp);
        }
        if (y1) {
            return
                    hasUpRightSurround(state, startX, startY, opp) ||
                    hasUpLeftSurround(state, startX, startY, opp) ||
                    hasDownRightSurround(state, startX, startY, opp) ||
                    hasDownLeftSurround(state, startX, startY, opp) ||
                    hasUpSurround(state, startX, startY, opp) ||
                    hasLeftSurround(state, startX, startY, opp) ||
                    hasRightSurround(state, startX, startY, opp);
        }
        if (x6) {
            return
                    hasUpRightSurround(state, startX, startY, opp) ||
                    hasUpLeftSurround(state, startX, startY, opp) ||
                    hasDownRightSurround(state, startX, startY, opp) ||
                    hasDownLeftSurround(state, startX, startY, opp) ||
                    hasUpSurround(state, startX, startY, opp) ||
                    hasDownSurround(state, startX, startY, opp) ||
                    hasLeftSurround(state, startX, startY, opp);
        }
        if (y6) {
            return
                    hasUpRightSurround(state, startX, startY, opp) ||
                    hasUpLeftSurround(state, startX, startY, opp) ||
                    hasDownRightSurround(state, startX, startY, opp) ||
                    hasDownLeftSurround(state, startX, startY, opp) ||
                    hasDownSurround(state, startX, startY, opp) ||
                    hasLeftSurround(state, startX, startY, opp) ||
                    hasRightSurround(state, startX, startY, opp);
        }
        return
                hasUpRightSurround(state, startX, startY, opp) ||
                hasUpLeftSurround(state, startX, startY, opp) ||
                hasDownRightSurround(state, startX, startY, opp) ||
                hasDownLeftSurround(state, startX, startY, opp) ||
                hasUpSurround(state, startX, startY, opp) ||
                hasDownSurround(state, startX, startY, opp) ||
                hasLeftSurround(state, startX, startY, opp) ||
                hasRightSurround(state, startX, startY, opp);
    }

    static bool inline
    isColor(const unsigned char x, const unsigned char y, const BitSet& blackPieces, const BitSet& whitePieces, const bool color) {
        if (color == Piece::BLACK) {
            return Helpers::getFromBoard(x, y, blackPieces);
        } else {
            return Helpers::getFromBoard(x, y, whitePieces);
        }
    }

    static inline void flipColor(const unsigned char x, const unsigned char y, BitSet& blackPieces, BitSet& whitePieces, const bool piece) {
        if (piece == Piece::BLACK) {
            Helpers::setOnBoard(x, y, blackPieces, true);
            Helpers::setOnBoard(x, y, whitePieces, false);
        } else {
            Helpers::setOnBoard(x, y, whitePieces, true);
            Helpers::setOnBoard(x, y, blackPieces, false);
        }
    }


    const inline State applyAction(const State &state,
            const unsigned char xIndex, const unsigned char yIndex,
            const bool piece) {
//        long int t1 = TIME::getTime();

        BitSet blackPieces = state.blackPieces.clone();
        BitSet whitePieces = state.whitePieces.clone();

        if (piece == Piece::BLACK) {
            Helpers::setOnBoard(xIndex, yIndex, blackPieces, true);
        } else {
            Helpers::setOnBoard(xIndex, yIndex, whitePieces, true);
        }

        const bool opposite_piece = !piece;

        unsigned char numFlipped = 0;
        unsigned char x;
        unsigned char y;

        if (hasUpSurround(state, xIndex, yIndex, opposite_piece)) {
            x = xIndex;
            y = yIndex+1;
            while (isColor(x, y, blackPieces, whitePieces, opposite_piece)) {
                flipColor(x, y, blackPieces, whitePieces, piece);
                ++y;
                ++numFlipped;
            }
        }
        if (hasDownSurround(state, xIndex, yIndex, opposite_piece)) {
            x = xIndex;
            y = yIndex-1;
            while (isColor(x, y, blackPieces, whitePieces, opposite_piece)) {
                flipColor(x, y, blackPieces, whitePieces, piece);
                --y;
                ++numFlipped;
            }
        }
        if (hasLeftSurround(state, xIndex, yIndex, opposite_piece)) {
            x = xIndex-1;
            y = yIndex;
            while (isColor(x, y, blackPieces, whitePieces, opposite_piece)) {
                flipColor(x, y, blackPieces, whitePieces, piece);
                --x;
                ++numFlipped;
            }
        }
        if (hasRightSurround(state, xIndex, yIndex, opposite_piece)) {
            x = xIndex+1;
            y = yIndex;
            while (isColor(x, y, blackPieces, whitePieces, opposite_piece)) {
                flipColor(x, y, blackPieces, whitePieces, piece);
                ++x;
                ++numFlipped;
            }
        }
        if (hasUpRightSurround(state, xIndex, yIndex, opposite_piece)) {
            x = xIndex+1;
            y = yIndex+1;
            while (isColor(x, y, blackPieces, whitePieces, opposite_piece)) {
                flipColor(x, y, blackPieces, whitePieces, piece);
                ++x;
                ++y;
                ++numFlipped;
            }
        }
        if (hasUpLeftSurround(state, xIndex, yIndex, opposite_piece)) {
            x = xIndex-1;
            y = yIndex+1;
            while (isColor(x, y, blackPieces, whitePieces, opposite_piece)) {
                flipColor(x, y, blackPieces, whitePieces, piece);
                --x;
                ++y;
                ++numFlipped;
            }
        }
        if (hasDownRightSurround(state, xIndex, yIndex, opposite_piece)) {
            x = xIndex+1;
            y = yIndex-1;
            while (isColor(x, y, blackPieces, whitePieces, opposite_piece)) {
                flipColor(x, y, blackPieces, whitePieces, piece);
                ++x;
                --y;
                ++numFlipped;
            }
        }
        if (hasDownLeftSurround(state, xIndex, yIndex, opposite_piece)) {
            x = xIndex-1;
            y = yIndex-1;
            while (isColor(x, y, blackPieces, whitePieces, opposite_piece)) {
                flipColor(x, y, blackPieces, whitePieces, piece);
                --x;
                --y;
                ++numFlipped;
            }
        }

        unsigned char num_black = state.numBlack;
        unsigned char num_white = state.numWhite;
        if (piece == Piece::WHITE) {
            num_white += 1 + numFlipped;
            num_black -= numFlipped;
        } else {
            num_black += 1 + numFlipped;
            num_white -= numFlipped;
        }



//        long int t2 = TIME::getTime();
//        TIME::applyTime += (t2 - t1);
        return State(blackPieces,
                     whitePieces,
                     state.numEmptySpots-1,
                     num_black,
                     num_white);
    }

}


#endif //OTHELLO_UTIL_H
