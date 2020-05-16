#ifndef MY_LED_H
#define MY_LED_H
#include <Arduino.h>

class Modes {
  private:
    byte current;

  public:
    Modes();

    void set_current(byte mode);

    void advance();

    byte get_current();

    bool is_waiting_for_work();

    bool is_waiting_for_relax();

    bool is_waiting();

    bool is_working();

    bool is_relaxing();
};

#endif
