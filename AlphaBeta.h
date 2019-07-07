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


class AlphaBeta {
public:
    const unsigned char maxDepth;
    const bool side;
    const bool oppSide;

    AlphaBeta(unsigned char maxDepth, bool side) :
            maxDepth(maxDepth), side(side), oppSide(!side) {
    }

    inline Action alpha_beta_search(State &state) const {


        Action* f = max_value_initial(state);



        return *f;
    }




    static inline bool terminal_test(const State &state) {
        return state.getNumEmptySpots() == 0;
    }

    signed char inline eval(const State &state) const {
        if (side) { // side == Piece::BLACK
            return state.numBlack - state.numWhite;
        } else {
            return state.numWhite - state.numBlack;
        }
    }

    inline Action* max_value_initial(const State &state) const {
        if (terminal_test(state)) {
            return new Action(false, 100, 100);
        }
        signed char v = NEG_INFINITY;
        Action* best_action = nullptr;
        for (unsigned char i = 0; i < 8; ++i) {
            for (unsigned char j = 0; j < 8; ++j) {
                if (state.isEmpty(i, j)) {
                    const ActionInfo info = Util::getSurroundInfo(state, i, j, oppSide);
                    if(info.hasAnySurround()){
                        const State s = Util::applyAction(state, i, j, side, info);
                        const signed char min_val = min_value(s, NEG_INFINITY, POS_INFINITY, 0);
                        if (min_val >= v) {
                            v = min_val;
                            best_action = new Action(side, i, j);
                        }
                    }
                }
            }
        }
        return best_action;
    }

    signed char inline max_value(const State state, signed char alpha, const signed char beta, const unsigned char depth) const {
        TIME::positions_searched++;
        if (terminal_test(state) || depth >= maxDepth) {
            return eval(state);
        }

        signed char v = NEG_INFINITY;
        bool hasValidActions = false;
        for (unsigned char i = 0; i < 8; ++i) {
            for (unsigned char j = 0; j < 8; ++j) {
                if (state.isEmpty(i, j)) {
                    const ActionInfo info = Util::getSurroundInfo(state, i, j, oppSide);
                    if(info.hasAnySurround()){
                        const State s = Util::applyAction(state, i, j, side, info);
                        v = Util::max(v, min_value(s, alpha, beta, depth + 1));
                        if (v >= beta) {
                            return v;
                        }
                        alpha = Util::max(v, alpha);
                        if(!hasValidActions){
                            hasValidActions = true;
                        }
                    }
                }
            }
        }
        if (!hasValidActions) {
            return eval(state);
        }
        return v;
    }

    signed char inline min_value(const State state, const signed char alpha, signed char beta, const unsigned char depth) const {
        TIME::positions_searched++;
//        state.print();
//        exit(0);
        if (terminal_test(state) || depth >= maxDepth) {
            return eval(state);
        }

        bool hasValidActions = false;
        signed char v = POS_INFINITY;
        for (unsigned char i = 0; i < 8; ++i) {
            for (unsigned char j = 0; j < 8; ++j) {
                if (state.isEmpty(i, j)) {
                    const ActionInfo info = Util::getSurroundInfo(state, i, j, side);
                    if(info.hasAnySurround()){
                        const State s = Util::applyAction(state, i, j, oppSide, info);
                        v = Util::min(v, max_value(s, alpha, beta, depth + 1));
                        if (v <= alpha) {
                            return v;
                        }
                        beta = Util::min(v, beta);
                        if(!hasValidActions){
                            hasValidActions = true;
                        }
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
