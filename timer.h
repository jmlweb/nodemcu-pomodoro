#ifndef TIMER_H
#define TIMER_H
#include <Arduino.h>

class Timer {
  private:
    int started_time;
    int time_limit;

  public:
    bool has_started;

    Timer(byte minutes);

    void init();

    int get_ellapsed_time();

    int get_remaining_time();

    bool has_finished();

    void reset();
};

#endif
