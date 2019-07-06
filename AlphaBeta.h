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
#include "ThreadPool.h"

static const char NEG_INFINITY = -127;
static const char POS_INFINITY = 127;

int tempFn(State s) {
    return 5;
}

namespace {
struct Result {
    Action action;
    char value;
};

struct Input {
    State state;
    unsigned int x;
    unsigned int y;

    const bool side;
    const bool oppSide;
    const unsigned char maxDepth;
};

    Result compute(Input) {
        
    }
    

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

        ThreadPool<int, State> threadPool(8);
        auto future = threadPool.scheduleWork(tempFn, state);
        threadPool.join();

        Action* f = max_value_initial(state);

        gettimeofday(&tp, NULL);
        long int t2 = tp.tv_sec * 1000 + tp.tv_usec / 1000;
        double time = (t2 - t1) / 1000.0;
        cout << "Time taken : " << time << endl;

        return *f;
    }

    static inline bool is_possible_move(const State &state,
                                 const unsigned char xIndex,
                                 const unsigned char yIndex,
                                 const bool oppPiece) {
        const bool r = state.isEmpty(xIndex, yIndex) && Util::hasAnySurround(state, xIndex, yIndex, oppPiece);
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

    Action* max_value_initial(const State &state) const {
        if (terminal_test(state)) {
            return new Action(false, 100, 100);
        }
        char max = NEG_INFINITY;
        Action* best_action = nullptr;
        for (unsigned char i = 0; i < 8; ++i) {
            for (unsigned char j = 0; j < 8; ++j) {
                if (is_possible_move(state, i, j, oppSide)) {
                    const State s = Util::applyAction(state, i, j, side);
                    const char min_val = min_value(s, NEG_INFINITY, POS_INFINITY, 0);
                    if (min_val >= max) {
                        max = min_val;
                        best_action = new Action(side, i, j);
                    }
                }
            }
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
        for (unsigned char i = 0; i < 8; ++i) {
            for (unsigned char j = 0; j < 8; ++j) {
                if (is_possible_move(state, i, j, oppSide)) {
                    const State s = Util::applyAction(state, i, j, side);
                    v = max(v,
                            min_value(s, alpha, beta, depth + 1));
                    if (v >= beta) {
                        return v;
                    }
                    alpha = max(v, alpha);
                    ++validActions;
                }
            }
        }
        if (validActions == 0) {
            return eval(state);
        }
        return v;
    }

    char min_value(const State &state, const char alpha, char beta, const unsigned char depth) const {
        TIME::positions_searched++;
//        state.print();
//        exit(0);
        if (terminal_test(state) || depth >= maxDepth) {
            return eval(state);
        }

        unsigned char validActions = 0;
        char v = POS_INFINITY;
        for (unsigned char i = 0; i < 8; ++i) {
            for (unsigned char j = 0; j < 8; ++j) {
                if (is_possible_move(state, i, j, side)) {
                    const State s = Util::applyAction(state, i, j, oppSide);
                    v = min(v, max_value(s, alpha, beta, depth + 1));
                    if (v <= alpha) {
                        return v;
                    }
                    beta = min(v, beta);
                    ++validActions;
                }
            }
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
