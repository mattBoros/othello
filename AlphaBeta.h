#include <iostream>

using namespace std;

#include <chrono>
#include <sys/time.h>
#include <cassert>

using namespace std::chrono;

#ifndef OTHELLO_ALPHABETA_H
#define OTHELLO_ALPHABETA_H

#include "Action.h"
#include "State.h"
#include "Piece.h"
#include "Util.h"
#include "TimerWidget.h"

static const char NEG_INFINITY = -127;
static const char POS_INFINITY = 127;

static inline char nextEmptyPosition(const State& state, char currentPosition) {
    for (char i = currentPosition; i < 64; i++) {
        //std::cout << "checking pos " << (int)i << endl;
        if (!state.ORd_board.get(i)) {
            return i;
        }
    }

    return -1;
}



class AlphaBeta {
public:
    const unsigned char maxDepth;
    const bool side;
    const bool oppSide;

    AlphaBeta(unsigned char maxDepth, bool side) :
            maxDepth(maxDepth), side(side), oppSide(!side) {
    }

    Action alpha_beta_search(State &state) const {

        struct timeval tp;
        gettimeofday(&tp, NULL);
        long int t1 = tp.tv_sec * 1000 + tp.tv_usec / 1000;

        Action f = max_value_initial(state);

        gettimeofday(&tp, NULL);
        long int t2 = tp.tv_sec * 1000 + tp.tv_usec / 1000;
        double time = (t2 - t1) / 1000.0;
        cout << "Time taken : " << time << endl;

        return f;
    }

    static inline bool is_possible_move(const State &state,
                                 const unsigned char xIndex,
                                 const unsigned char yIndex,
                                 const bool oppPiece) {
        const bool r = Util::hasAnySurround(state, xIndex, yIndex, oppPiece);
        return r;
    }

    static inline bool terminal_test(const State &state) {
        return state.numEmptySpots == 0;
    }

    char inline eval(const State &state) const {
        if (side == Piece::BLACK) {
            return state.numBlack - state.numWhite;
        } else {
            return state.numWhite - state.numBlack;
        }
    }

    Action max_value_initial(const State &state) const {
        if (terminal_test(state)) {
            return Action(false, 100, 100);
        }
        char v = NEG_INFINITY;
        Action best_action(0, 0, 0);

        char bitIndex = 0;
        while (bitIndex < 64) {
            char nextPos = nextEmptyPosition(state, bitIndex);
            if (nextPos == -1) {
                break;
            }
            
            const char x = nextPos / 8;
            const char y = nextPos % 8;
            //assert(state.isEmpty(x, y));
            
            if (is_possible_move(state, x, y, oppSide)) {
                // TODO: Don't construct a unless necessary
                const State s = Util::applyAction(state, x, y, side);
                const char min_val = min_value(s, NEG_INFINITY, POS_INFINITY, 0);
                if (min_val >= v) {
                    v = min_val;
                    best_action = Action(side, x, y);
                }
            }

            bitIndex = nextPos + 1;
        }

        return best_action;
    }

    char max_value(const State &state, char alpha, const char beta, const unsigned char depth) const {
        TIME::positions_searched++;
        if (terminal_test(state) || depth >= maxDepth) {
            return eval(state);
        }

        char v = NEG_INFINITY;
        unsigned char validActions = 0;

        char bitIndex = 0;
        while (bitIndex < 64) {
            char nextPos = nextEmptyPosition(state, bitIndex);
            if (nextPos == -1) {
                break;
            }

            const char x = nextPos / 8;
            const char y = nextPos % 8;
            //assert(state.isEmpty(x, y));

            if (is_possible_move(state, x, y, oppSide)) {
                const State s = Util::applyAction(state, x, y, side);
                v = max(v,
                        min_value(s, alpha, beta, depth + 1));
                if (v >= beta) {
                    return v;
                }
                alpha = max(v, alpha);
                ++validActions;
            }

            bitIndex = nextPos + 1;
        }

        if (validActions == 0) {
            return eval(state);
        }
        return v;
    }

    char min_value(const State &state, const char alpha, char beta, const unsigned char depth) const {
        TIME::positions_searched++;
        if (terminal_test(state) || depth >= maxDepth) {
            return eval(state);
        }

        unsigned char validActions = 0;
        char v = POS_INFINITY;

        char bitIndex = 0;
        while (bitIndex < 64) {
            char nextPos = nextEmptyPosition(state, bitIndex);
            if (nextPos == -1) {
                break;
            }

            const char x = nextPos / 8;
            const char y = nextPos % 8;
            //assert(state.isEmpty(x, y));

            if (is_possible_move(state, x, y, side)) {
                const State s = Util::applyAction(state, x, y, oppSide);
                v = min(v, max_value(s, alpha, beta, depth + 1));
                if (v <= alpha) {
                    return v;
                }
                beta = min(v, beta);
                ++validActions;
            }

            bitIndex = nextPos + 1;
        }

        if (validActions == 0) {
            return eval(state);
        }
        return v;
    }

    static inline char min(const char f1, const char f2) {
        return f2 < f1 ? f2 : f1;
    }

    static inline char max(const char f1, const char f2) {
        return f2 > f1 ? f2 : f1;
    }

};

#endif //OTHELLO_ALPHABETA_H
