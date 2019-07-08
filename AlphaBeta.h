#include <iostream>

using namespace std;

#include <chrono>
#include <sys/time.h>

using namespace std::chrono;

#ifndef OTHELLO_ALPHABETA_H
#define OTHELLO_ALPHABETA_H

#include "Action.h"
#include "State.h"
#include "Piece.h"
#include "Util.h"
#include "TimerWidget.h"

static const signed char NEG_INFINITY = -127;
static const signed char POS_INFINITY = 127;

static const unsigned char DIVIDE_8_TABLE[64] = {
        0,0,0,0,0,0,0,0,
        1,1,1,1,1,1,1,1,
        2,2,2,2,2,2,2,2,
        3,3,3,3,3,3,3,3,
        4,4,4,4,4,4,4,4,
        5,5,5,5,5,5,5,5,
        6,6,6,6,6,6,6,6,
        7,7,7,7,7,7,7,7
};

static const unsigned char MOD_8_TABLE[64] = {
    0,1,2,3,4,5,6,7,
    0,1,2,3,4,5,6,7,
    0,1,2,3,4,5,6,7,
    0,1,2,3,4,5,6,7,
    0,1,2,3,4,5,6,7,
    0,1,2,3,4,5,6,7,
    0,1,2,3,4,5,6,7,
    0,1,2,3,4,5,6,7
};

class AlphaBeta {
public:
    const unsigned char maxDepth;
    const bool side;
    const bool oppSide;

    AlphaBeta(unsigned char maxDepth, bool side) :
            maxDepth(maxDepth), side(side), oppSide(!side) {
    }

    inline Action alpha_beta_search(State &state) const {


        Action *f = max_value_initial(state);


        return *f;
    }


    static inline bool terminal_test(const State &state) {
        return !state.NOT_ORd_board.word;
    }

    signed char inline eval(const State &state) const {
        if (side) { // side == Piece::BLACK
            return state.numBlack - state.numWhite;
        } else {
            return state.numWhite - state.numBlack;
        }
    }

    inline Action *max_value_initial(const State &state) const {
        if (terminal_test(state)) {
            return new Action(false, 100, 100);
        }
        signed char v = NEG_INFINITY;
        Action *best_action = nullptr;
        for (unsigned char i = 0; i < 64; ++i) {
//        for (unsigned char i = __builtin_clzll(state.NOT_ORd_board.word); i >= 0; --i) {
            if (state.isEmpty(i)) {
//                const unsigned char x = i / 8;
//                const unsigned char y = i % 8;
                const unsigned char x = DIVIDE_8_TABLE[i];
                const unsigned char y = MOD_8_TABLE[i];
                const uint8_t info = Util::getSurroundInfo(state, x, y, oppSide);
                if (info) {
                    const State s = Util::applyAction(state, x, y, side, info, i);
                    const signed char min_val = min_value(s, NEG_INFINITY, POS_INFINITY, 0);
                    if (min_val >= v) {
                        v = min_val;
                        best_action = new Action(side, x, y);
                    }
                }
            }
        }
        return best_action;
    }

    signed char inline
    max_value(const State state, signed char alpha, const signed char beta, const unsigned char depth) const {
        TIME::positions_searched++;
        if (terminal_test(state) || depth >= maxDepth) {
            return eval(state);
        }

        signed char v = NEG_INFINITY;
        bool hasValidActions = false;
        for (unsigned char i = 0; i < 64; ++i) {
//        for (unsigned char i = __builtin_clzll(state.NOT_ORd_board.word); i >= 0; --i) {
            if (state.isEmpty(i)) {
//                const unsigned char x = i / 8;
//                const unsigned char y = i % 8;
                const unsigned char x = DIVIDE_8_TABLE[i];
                const unsigned char y = MOD_8_TABLE[i];
                const uint8_t info = Util::getSurroundInfo(state, x, y, oppSide);
                if (info) {
                    const State s = Util::applyAction(state, x, y, side, info, i);
                    v = Util::max(v, min_value(s, alpha, beta, depth + 1));
                    if (v >= beta) {
                        return v;
                    }
                    alpha = Util::max(v, alpha);
                    if (!hasValidActions) {
                        hasValidActions = true;
                    }
                }
            }
        }
        if (!hasValidActions) {
            return eval(state);
        }
        return v;
    }

    signed char inline
    min_value(const State state, const signed char alpha, signed char beta, const unsigned char depth) const {
        TIME::positions_searched++;
//        state.print();
//        exit(0);
        if (terminal_test(state) || depth >= maxDepth) {
            return eval(state);
        }

        bool hasValidActions = false;
        signed char v = POS_INFINITY;
        for (unsigned char i = 0; i < 64; ++i) {
//        for (unsigned char i = __builtin_clzll(state.NOT_ORd_board.word); i >= 0; --i) {
            if (state.isEmpty(i)) {
//                const unsigned char x = i / 8;
//                const unsigned char y = i % 8;
                const unsigned char x = DIVIDE_8_TABLE[i];
                const unsigned char y = MOD_8_TABLE[i];
                const uint8_t info = Util::getSurroundInfo(state, x, y, side);
                if (info) {
                    const State s = Util::applyAction(state, x, y, oppSide, info, i);
                    v = Util::min(v, max_value(s, alpha, beta, depth + 1));
                    if (v <= alpha) {
                        return v;
                    }
                    beta = Util::min(v, beta);
                    if (!hasValidActions) {
                        hasValidActions = true;
                    }
                }
            }
        }
        if (!hasValidActions) {
            return eval(state);
        }
        return v;
    }

};

#endif //OTHELLO_ALPHABETA_H
