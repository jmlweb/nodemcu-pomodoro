#ifndef MODES_H
#define MODES_H
#include <Arduino.h>

class Modes {
  private:
    byte current;

  public:
    Modes();

    void set_current(byte mode);

    void advance();

    void go_to_waiting_for_relax();

    void go_to_waiting_for_work();

    byte get_current();

    bool is_waiting_for_work();

    bool is_waiting_for_relax();

    bool is_waiting();

    bool is_working();

    bool is_relaxing();
};

#endif
