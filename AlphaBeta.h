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

static const int8_t NEG_INFINITY = -127;
static const int8_t POS_INFINITY = 127;

static const uint8_t DIVIDE_8_TABLE[64] = {
        0,0,0,0,0,0,0,0,
        1,1,1,1,1,1,1,1,
        2,2,2,2,2,2,2,2,
        3,3,3,3,3,3,3,3,
        4,4,4,4,4,4,4,4,
        5,5,5,5,5,5,5,5,
        6,6,6,6,6,6,6,6,
        7,7,7,7,7,7,7,7
};

static const uint8_t MOD_8_TABLE[64] = {
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
    const uint8_t maxDepth;
    const bool side;
    const bool oppSide;

    AlphaBeta(uint8_t maxDepth, bool side) :
            maxDepth(maxDepth), side(side), oppSide(!side) {
    }

    inline Action alpha_beta_search(State &state) const {
        Action *f = max_value_initial(state);
        return *f;
    }


    static inline bool terminal_test(const State state) {
        return !state.NOT_ORd_board.word;
    }

    int8_t inline eval(const State state) const {
        return (side*2 - 1) * (state.numBlack - state.numWhite);

//        if (side) { // side == Piece::BLACK
//            return state.numBlack - state.numWhite;
//        } else {
//            return state.numWhite - state.numBlack;
//        }
    }

    inline Action *max_value_initial(const State &state) const {
        if (terminal_test(state)) {
            return new Action(false, 100, 100);
        }
        int8_t v = NEG_INFINITY;
        Action *best_action = nullptr;
        for (uint8_t i = 0; i < 64; ++i) {
//        for (uint8_t i = __builtin_clzll(state.NOT_ORd_board.word); i >= 0; --i) {
            if (state.isEmpty(i)) {
//                const uint8_t x = i / 8;
//                const uint8_t y = i % 8;
                const uint8_t x = DIVIDE_8_TABLE[i];
                const uint8_t y = MOD_8_TABLE[i];
                const uint8_t info = Util::getSurroundInfo(state, x, y, oppSide);
                if (info) {
                    const State s = Util::applyAction(state, x, y, side, info, i);
                    const int8_t min_val = min_value(s, NEG_INFINITY, POS_INFINITY, 0);
                    if (min_val >= v) {
                        v = min_val;
                        best_action = new Action(side, x, y);
                    }
                }
            }
        }
        return best_action;
    }

    int8_t inline
    max_value(const State state, int8_t alpha, const int8_t beta, const uint8_t depth) const {
        TIME::positions_searched++;
        if (terminal_test(state) || depth >= maxDepth) {
            return eval(state);
        }

        int8_t v = NEG_INFINITY;
        bool hasValidActions = false;
        for (uint8_t i = 0; i < 64; ++i) {
//        for (uint8_t i = __builtin_clzll(state.NOT_ORd_board.word); i >= 0; --i) {
            if (state.isEmpty(i)) {
//                const uint8_t x = i / 8;
//                const uint8_t y = i % 8;
                const uint8_t x = DIVIDE_8_TABLE[i];
                const uint8_t y = MOD_8_TABLE[i];
                const uint8_t info = Util::getSurroundInfo(state, x, y, oppSide);
                if (info) {
                    const State s = Util::applyAction(state, x, y, side, info, i);
                    v = Util::max(v, min_value(s, alpha, beta, depth + 1));
                    if (v >= beta) {
                        return v;
                    }
                    alpha = Util::max(v, alpha);
                    hasValidActions = true;
                }
            }
        }
        if (!hasValidActions) {
            return eval(state);
        }
        return v;
    }

    int8_t inline
    min_value(const State state, const int8_t alpha, int8_t beta, const uint8_t depth) const {
        TIME::positions_searched++;
//        state.print();
//        exit(0);
        if (terminal_test(state) || depth >= maxDepth) {
            return eval(state);
        }

        bool hasValidActions = false;
        int8_t v = POS_INFINITY;
        for (uint8_t i = 0; i < 64; ++i) {
//        for (uint8_t i = __builtin_clzll(state.NOT_ORd_board.word); i >= 0; --i) {
            if (state.isEmpty(i)) {
//                const uint8_t x = i / 8;
//                const uint8_t y = i % 8;
                const uint8_t x = DIVIDE_8_TABLE[i];
                const uint8_t y = MOD_8_TABLE[i];
                const uint8_t info = Util::getSurroundInfo(state, x, y, side);
                if (info) {
                    const State s = Util::applyAction(state, x, y, oppSide, info, i);
                    v = Util::min(v, max_value(s, alpha, beta, depth + 1));
                    if (v <= alpha) {
                        return v;
                    }
                    beta = Util::min(v, beta);
                    hasValidActions = true;
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
