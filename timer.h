#ifndef TIMER_H
#define TIMER_H
#include <Arduino.h>

class Timer {
  private:
    unsigned int started_time;
    unsigned int time_limit;

  public:
    bool has_started;

    Timer();
    Timer(byte minutes);

    int get_ellapsed_time();

    int get_remaining_time();

    bool has_finished();

    void reset();
};

#endif
