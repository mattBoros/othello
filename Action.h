
#include <iostream>
#include "Piece.h"

using namespace std;

#ifndef OTHELLO_ACTION_H
#define OTHELLO_ACTION_H

class Action {
public:
    const bool piece;
    const uint8_t xIndex;
    const uint8_t yIndex;

    Action(const bool piece, const uint8_t xIndex, const uint8_t yIndex)
            : piece(piece), xIndex(xIndex), yIndex(yIndex) {
    }

    bool inline getOppositePiece() const {
        return !piece;
    }

    void print() const {
//        if (piece == Piece::BLACK){
//            cout << "Black to ";
//        } else {
//            cout << "White to ";
//        }
//        cout << "x=" << (int) xIndex << " y=" << (int) yIndex << endl;
        cout << (int) xIndex << " " << (int) yIndex << endl;
    }

};



#endif //OTHELLO_ACTION_H
