#include <iostream>

using namespace std;

#include <chrono>
#include <sys/time.h>
#include <climits>

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
        0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 1, 1, 1, 1,
        2, 2, 2, 2, 2, 2, 2, 2,
        3, 3, 3, 3, 3, 3, 3, 3,
        4, 4, 4, 4, 4, 4, 4, 4,
        5, 5, 5, 5, 5, 5, 5, 5,
        6, 6, 6, 6, 6, 6, 6, 6,
        7, 7, 7, 7, 7, 7, 7, 7
};

static const uint8_t MOD_8_TABLE[64] = {
        0, 1, 2, 3, 4, 5, 6, 7,
        0, 1, 2, 3, 4, 5, 6, 7,
        0, 1, 2, 3, 4, 5, 6, 7,
        0, 1, 2, 3, 4, 5, 6, 7,
        0, 1, 2, 3, 4, 5, 6, 7,
        0, 1, 2, 3, 4, 5, 6, 7,
        0, 1, 2, 3, 4, 5, 6, 7,
        0, 1, 2, 3, 4, 5, 6, 7
};


static const uint8_t ORDER[64] = {
    37, 29, 21, 20, 19, 18, 26, 34, 42, 43, 44, 45, 46, 38, 30, 22, 14, 13, 12, 11, 10, 9, 17, 25, 33, 41, 49, 50, 51, 52, 53, 54, 0, 1, 2, 3, 4, 5, 6, 7, 15, 23, 31, 39, 47, 55, 63, 62, 61, 60, 59, 58, 57, 56, 48, 40, 32, 24, 16, 8, 28, 27, 35, 36
};

static const unsigned long long MAX_BOARD = ULLONG_MAX;

template<const uint8_t maxDepth,
        const bool side>
class AlphaBeta {
public:
    uint8_t *killer_moves;

    inline explicit AlphaBeta() {
        killer_moves = new uint8_t[maxDepth];
        for (int i = 0; i < maxDepth; ++i) {
            killer_moves[i] = UINT8_MAX;
        }
    };

    inline const Action alpha_beta_search(const State &state) const {
        Action *f = max_value_initial(state);
        return *f;
    }

    static inline bool terminal_test(const State state) {
        return state.ORd_board.word == MAX_BOARD;
    }

    inline uint8_t get_move(const uint8_t index, const uint8_t depth) const {
        return depth == 0 ? ORDER[index] : index;
    }

    int8_t inline eval(const State state) const {
//        return side * (state.numBlack - state.numWhite) + oppSide * (state.numWhite - state.numBlack);

//        return (side - oppSide) * (state.numBlack - state.numWhite);
//        return (side*2 - 1) * (state.numBlack - state.numWhite);

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
        int8_t v = NEG_INFINITY;
        Action *best_action = nullptr;
        for (uint8_t i = 0; i < 64; ++i) {
            if (state.isEmpty(i)) {
                const uint8_t x = DIVIDE_8_TABLE[i];
                const uint8_t y = MOD_8_TABLE[i];
                const State newState = Util::applyAction<side>(state, x, y, i);
                if (newState.numBlack != NULL_BOARD_NUM_PIECES) {
                    const int8_t min_val = min_value(newState, NEG_INFINITY, POS_INFINITY, 0);
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

        const uint8_t km_index = killer_moves[depth];
        if (km_index != UINT8_MAX && state.isEmpty(km_index)) {
            const uint8_t x = DIVIDE_8_TABLE[km_index];
            const uint8_t y = MOD_8_TABLE[km_index];
            const State newState = Util::applyAction<side>(state, x, y, km_index);
            if (newState.numBlack != NULL_BOARD_NUM_PIECES) {
                v = Util::max(v, min_value(newState, alpha, beta, depth + 1));
                if (v >= beta) {
                    return v;
                }
                alpha = Util::max(v, alpha);
                hasValidActions = true;
            }
        }

        for (uint8_t index = 0; index < 64; ++index) {
//            const uint8_t current_move = ORDER[index];
            const uint8_t current_move = get_move(index, depth);
//            const uint8_t current_move = index;
            if (current_move != 27 && current_move != 28 && current_move != 35 && current_move != 36 &&
                current_move != km_index && state.isEmpty(current_move)) {
                const uint8_t x = DIVIDE_8_TABLE[current_move];
                const uint8_t y = MOD_8_TABLE[current_move];
                const State newState = Util::applyAction<side>(state, x, y, current_move);
                if (newState.numBlack != NULL_BOARD_NUM_PIECES) {
                    v = Util::max(v, min_value(newState, alpha, beta, depth + 1));
                    if (v >= beta) {
                        killer_moves[depth] = current_move;
                        return v;
                    }
                    alpha = Util::max(v, alpha);
                    hasValidActions = true;
                }
            }
        }
        return hasValidActions ? v : eval(state);
//        if (!hasValidActions) {
//            return eval(state);
//        }
//        return v;
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

        const uint8_t km_index = killer_moves[depth];
        if (km_index != UINT8_MAX && state.isEmpty(km_index)) {
            const uint8_t x = DIVIDE_8_TABLE[km_index];
            const uint8_t y = MOD_8_TABLE[km_index];
            const State newState = Util::applyAction<!side>(state, x, y, km_index);
            if (newState.numBlack != NULL_BOARD_NUM_PIECES) {
                v = Util::min(v, max_value(newState, alpha, beta, depth + 1));
                if (v <= alpha) {
                    return v;
                }
                beta = Util::min(v, beta);
                hasValidActions = true;
            }
        }

        for (uint8_t index = 0; index < 64; ++index) {
//            const uint8_t current_move = ORDER[index];
            const uint8_t current_move = get_move(index, depth);
//            const uint8_t current_move = index;
            if (current_move != 27 && current_move != 28 && current_move != 35 && current_move != 36 &&
                current_move != km_index && state.isEmpty(current_move)) {
                const uint8_t x = DIVIDE_8_TABLE[current_move];
                const uint8_t y = MOD_8_TABLE[current_move];
                const State newState = Util::applyAction<!side>(state, x, y, current_move);
                if (newState.numBlack != NULL_BOARD_NUM_PIECES) {
                    v = Util::min(v, max_value(newState, alpha, beta, depth + 1));
                    if (v <= alpha) {
                        killer_moves[depth] = current_move;
                        return v;
                    }
                    beta = Util::min(v, beta);
                    hasValidActions = true;
                }
            }
        }
        return hasValidActions ? v : eval(state);
//        if (!hasValidActions) {
//            return eval(state);
//        }
//        return v;
    }

};

#endif //OTHELLO_ALPHABETA_H
