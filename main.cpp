#include <iostream>
#include <fstream>

using namespace std;

#include "AlphaBeta.h"
#include "BitSet.h"
#include "State.h"
#include "Piece.h"

double toMs(long x) {
    return (x / 1000.0) / 1000.0;
}

// try -O2
int main(int argc, char *argv[]) {
//    unsigned long long blackPieces = _atoi64(argv[1]);
//    unsigned long long whitePieces = _atoi64(argv[2]);
//    unsigned char depth = atol(argv[3]);
//    unsigned int side = atol(argv[4]);
//
//    bool sideBool;
//    if(side == 1){
//        sideBool = Piece::BLACK;
//    } else {
//        sideBool = Piece::WHITE;
//    }
    bool sideBool = Piece::BLACK;
    unsigned char depth = 10;
    AlphaBeta alphaBeta(depth, sideBool);
    unsigned long long blackPieces = 2342794498872380161LL;
    unsigned long long whitePieces = 1115969461956412422LL;
    cout << blackPieces << endl;
    cout << whitePieces << endl;
    State* startingBoard = Helpers2::getBoard(blackPieces, whitePieces);

    startingBoard->print();

//    cout << ((int) alphaBeta.min_value(startingBoard, -100, 100, 0)) << endl;
    alphaBeta.alpha_beta_search(*startingBoard).print();

    cout << "Apply Time : " << TIME::applyTime / 1000.0 << endl;
    cout << "Action Get Time : " << TIME::getActionTime / 1000.0 << endl;
    cout << "BS Set Time : " << TIME::bsSetTime / 1000.0 << endl;
    cout << "BS Get Time : " << TIME::bsGetTime / 1000.0 << endl;
    cout << "Positions searched : " << TIME::positions_searched << endl;
}



