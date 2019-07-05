
#ifndef OTHELLO_TIMERWIDGET_H
#define OTHELLO_TIMERWIDGET_H

#include <chrono>

class TimerWidget {
  long *_counter;
  std::chrono::time_point<std::chrono::steady_clock> _start;
public:
  TimerWidget(long *counter)
      : _counter(counter), _start(std::chrono::steady_clock::now()) {}

  ~TimerWidget() {
#ifdef DEBUG
    *_counter += std::chrono::duration_cast<chrono::nanoseconds>(
        std::chrono::steady_clock::now() - _start).count();
#endif
  }
};

#endif // OTHELLO_TIMERWIDGET_H
