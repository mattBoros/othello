#include <iostream>
#include <fstream>

using namespace std;

#include "AlphaBeta.h"
#include "BitSet.h"
#include "State.h"
#include "Piece.h"
#include "Tests.h"

int main(int argc, char *argv[]) {
//    test();
//    exit(0);

//    unsigned long long blackPieces = _atoi64(argv[1]);
//    unsigned long long whitePieces = _atoi64(argv[2]);
//    unsigned char depth = atol(argv[3]);
//    unsigned int side = atol(argv[4]);

//    const bool sideBool = sideBool ? Piece::BLACK : Piece::WHITE;
//    if(side == 1){
//        sideBool = Piece::BLACK;
//    } else {
//        sideBool = Piece::WHITE;
//    }
    const bool sideBool = Piece::BLACK;
    const AlphaBeta<12, sideBool> alphaBeta;
    unsigned long long blackPieces = 2300281674010624LL;
    unsigned long long whitePieces = 168693248LL;
    cout << blackPieces << endl;
    cout << whitePieces << endl;
    State startingBoard = Helpers2::getBoard(blackPieces, whitePieces);

    startingBoard.print();

//    cout << ((int) alphaBeta.min_value(startingBoard, -100, 100, 0)) << endl;
    struct timeval tp;
    gettimeofday(&tp, NULL);
    long int t1 = tp.tv_sec * 1000 + tp.tv_usec / 1000;

    alphaBeta.alpha_beta_search(startingBoard).print();

    gettimeofday(&tp, NULL);
    long int t2 = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    double time = (t2 - t1) / 1000.0;
    cout << "Time taken : " << time << endl;

    cout << "Apply Time : " << TIME::applyTime / 1000.0 << endl;
    cout << "Action Get Time : " << TIME::getActionTime / 1000.0 << endl;
    cout << "BS Set Time : " << TIME::bsSetTime / 1000.0 << endl;
    cout << "BS Get Time : " << TIME::bsGetTime / 1000.0 << endl;
    cout << "Positions searched : " << TIME::positions_searched << endl;
    cout << "Positions per second : " << TIME::positions_searched / time << endl;
}



