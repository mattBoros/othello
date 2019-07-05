
#ifndef OTHELLO_TIMERWIDGET_H
#define OTHELLO_TIMERWIDGET_H

#include <chrono>

class TimerWidget {
    long* _counter;
    std::chrono::time_point<std::chrono::steady_clock> _start;

    TimerWidget(long* counter) :_counter(counter), _start(std::chrono::steady_clock::now()) {

    }

    ~TimerWidget() {
//        *_counter += std::chrono::steady_clock::now() - _start;
    }
};

#endif //OTHELLO_TIMERWIDGET_H
