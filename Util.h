
#ifndef OTHELLO_UTIL_H
#define OTHELLO_UTIL_H

#include "AlphaBeta.h"
#include "Debug.h"
#include "State.h"


static const uint8_t ONE_UINT8 = (uint8_t) 1;
static const uint8_t ZERO_UINT8 = (uint8_t) 0;

static const uint8_t HAS_UP_RIGHT_SURROUND = ONE_UINT8 << 0u;
static const uint8_t HAS_UP_LEFT_SURROUND = ONE_UINT8 << 1u;
static const uint8_t HAS_DOWN_RIGHT_SURROUND = ONE_UINT8 << 2u;
static const uint8_t HAS_DOWN_LEFT_SURROUND = ONE_UINT8 << 3u;
static const uint8_t HAS_UP_SURROUND = ONE_UINT8 << 4u;
static const uint8_t HAS_DOWN_SURROUND = ONE_UINT8 << 5u;
static const uint8_t HAS_LEFT_SURROUND = ONE_UINT8 << 6u;
static const uint8_t HAS_RIGHT_SURROUND = ONE_UINT8 << 7u;

static const uint8_t NULL_BOARD_NUM_PIECES = UINT8_MAX;

static const BitSet NULL_BITSET(0);

static const State NULL_STATE(NULL_BITSET,
                              NULL_BITSET,
                              NULL_BOARD_NUM_PIECES,
                              NULL_BOARD_NUM_PIECES);

namespace Util {

    static bool inline
    isColor(const uint8_t x, const uint8_t y,
            const BitSet &blackPieces, const BitSet &whitePieces,
            const bool color) {
        return (color && blackPieces.get(x, y)) ||
                (!color && whitePieces.get(x, y));
//        if (color) { // color == Piece::BLACK
//            return blackPieces.get(x, y);
//        } else {
//            return whitePieces.get(x, y);
//        }
    }

    static inline void flipColor(const uint8_t x, const uint8_t y, BitSet &blackPieces, BitSet &whitePieces
            ,const bool piece
            ) {
        if (piece) { // piece == Piece::BLACK
            blackPieces.setXY(x, y);
            whitePieces.clear(x, y);
        } else {
            whitePieces.setXY(x, y);
            blackPieces.clear(x, y);
        }
    }

    template <const bool piece>
    const inline bool isPieceSafe(const State state, const int8_t x, const int8_t y){
        if(x < 0 || y < 0 || x > 7 || y > 7){
            return false;
        }
        return state.isPiece<piece>(x, y);
    }

    template <const bool piece>
    const inline State applyAction(const State &state,
                                   const uint8_t startX,
                                   const uint8_t startY,
                                   const uint8_t i) {
        const bool opposite_piece = !piece;

//        if(!isPieceSafe<opposite_piece>(state, startX-1, startY-1) &&
//                !isPieceSafe<opposite_piece>(state, startX+1, startY+1) &&
//                !isPieceSafe<opposite_piece>(state, startX-1, startY+1) &&
//                !isPieceSafe<opposite_piece>(state, startX+1, startY-1) &&
//                !isPieceSafe<opposite_piece>(state, startX, startY-1) &&
//                !isPieceSafe<opposite_piece>(state, startX, startY+1) &&
//                !isPieceSafe<opposite_piece>(state, startX-1, startY) &&
//                !isPieceSafe<opposite_piece>(state, startX+1, startY)
//                ){
//            return NULL_STATE;
//        }

//        long int t1 = TIME::getTime();

//        BitSet blackPieces = state.blackPieces.clone();
//        BitSet whitePieces = state.whitePieces.clone();
        BitSet blackPieces(state.blackPieces.word);
        BitSet whitePieces(state.whitePieces.word);

        uint8_t numFlipped = 0;
        int8_t x;
        int8_t y;

        // HAS UP SURROUND
        y = startY + 1;
        while (y < 8 && state.isPiece<opposite_piece>(startX, y)) {
            ++y;
        }
        if ((y - startY - 1) && y < 8 && !state.isEmpty(startX, y)) {
            y = startY + 1;
            while (isColor(startX, y, blackPieces, whitePieces, opposite_piece)) {
                flipColor(startX, y, blackPieces, whitePieces, piece);
                ++y;
                ++numFlipped;
            }
        }

        // HAS DOWN SURROUND
        y = startY - 1;
        while (y >= 0 && state.isPiece<opposite_piece>(startX, y)) {
            --y;
        }
        if ((startY - y - 1) && y >= 0 && !state.isEmpty(startX, y)) {
            y = startY - 1;
            while (isColor(startX, y, blackPieces, whitePieces, opposite_piece)) {
                flipColor(startX, y, blackPieces, whitePieces, piece);
                --y;
                ++numFlipped;
            }
        }

        // HAS LEFT SURROUND
        x = startX - 1;
        while (x >= 0 && state.isPiece<opposite_piece>(x, startY)) {
            --x;
        }
        if ((startX - x - 1) && x >= 0 && !state.isEmpty(x, startY)) {
            x = startX - 1;
            while (isColor(x, startY, blackPieces, whitePieces, opposite_piece)) {
                flipColor(x, startY, blackPieces, whitePieces, piece);
                --x;
                ++numFlipped;
            }
        }

        // HAS RIGHT SURROUND
        x = startX + 1;
        while (x < 8 && state.isPiece<opposite_piece>(x, startY)) {
            ++x;
        }
        if ((x - startX - 1) && x < 8 && !state.isEmpty(x, startY)) {
            x = startX + 1;
            while (isColor(x, startY, blackPieces, whitePieces, opposite_piece)) {
                flipColor(x, startY, blackPieces, whitePieces, piece);
                ++x;
                ++numFlipped;
            }
        }

        // HAS UP RIGHT SURROUND
        x = startX + 1;
        y = startY + 1;
        while (x < 8 && y < 8 && state.isPiece<opposite_piece>(x, y)) {
            ++x;
            ++y;
        }
        if ((y - startY - 1) && y < 8 && x < 8 && state.hasPiece(x, y)) {
            x = startX + 1;
            y = startY + 1;
            while (isColor(x, y, blackPieces, whitePieces, opposite_piece)) {
                flipColor(x, y, blackPieces, whitePieces, piece);
                ++x;
                ++y;
                ++numFlipped;
            }
        }

        // HAS UP LEFT SURROUND
        x = startX - 1;
        y = startY + 1;
        while (x >= 0 && y < 8 && state.isPiece<opposite_piece>(x, y)) {
            --x;
            ++y;
        }
        if ((y - startY - 1) && y < 8 && x >= 0 && state.hasPiece(x, y)) {
            x = startX - 1;
            y = startY + 1;
            while (isColor(x, y, blackPieces, whitePieces, opposite_piece)) {
                flipColor(x, y, blackPieces, whitePieces, piece);
                --x;
                ++y;
                ++numFlipped;
            }
        }

        // HAS DOWN RIGHT SURROUND
        x = startX + 1;
        y = startY - 1;
        while (x < 8 && y >= 0 && state.isPiece<opposite_piece>(x, y)) {
            ++x;
            --y;
        }
        if ((startY - y - 1) && y >= 0 && x < 8 && state.hasPiece(x, y)) {
            x = startX + 1;
            y = startY - 1;
            while (isColor(x, y, blackPieces, whitePieces, opposite_piece)) {
                flipColor(x, y, blackPieces, whitePieces, piece);
                ++x;
                --y;
                ++numFlipped;
            }
        }

        // HAS DOWN LEFT SURROUND
        x = startX - 1;
        y = startY - 1;
        while (x >= 0 && y >= 0 && state.isPiece<opposite_piece>(x, y)) {
            --x;
            --y;
        }
        if ((startY - y - 1) && x >= 0 && y >= 0 && state.hasPiece(x, y)) {
            x = startX - 1;
            y = startY - 1;
            while (isColor(x, y, blackPieces, whitePieces, opposite_piece)) {
                flipColor(x, y, blackPieces, whitePieces, piece);
                --x;
                --y;
                ++numFlipped;
            }
        }

        if(numFlipped){
            if (piece) { // piece == Piece::BLACK
                blackPieces.set(i);
            } else {
                whitePieces.set(i);
            }
            const BitSet new_ORd_board(state.ORd_board.word | SHIFTED_ONES[i]);
            return State(blackPieces,
                         whitePieces,
                         new_ORd_board,
                         piece * (state.numBlack + 1 + numFlipped) + opposite_piece * (state.numBlack - numFlipped),
                         piece * (state.numWhite - numFlipped) + opposite_piece * (state.numWhite + 1 + numFlipped));
        } else {
            return NULL_STATE;
        }
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
