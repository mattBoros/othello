#include <iostream>

using namespace std;

#include <chrono>
#include <sys/time.h>
#include <fstream>

using namespace std::chrono;

#ifndef OTHELLO_DEBUG_H
#define OTHELLO_DEBUG_H

namespace TIME {
    static long positions_searched = 0;

    static long int isPossibleMove = 0;

    static long int applyTime = 0;
    static long int getActionTime = 0;
    static long int bsSetTime = 0;
    static long int bsGetTime = 0;

    static long int getTime() {
//        return 0;
        struct timeval tp;
        gettimeofday(&tp, NULL);
        return tp.tv_sec * 1000 + tp.tv_usec / 1000;
    }
}


#endif
