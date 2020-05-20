#ifndef MODES_H
#define MODES_H
#include <Arduino.h>
#include "mode.h"

class Modes {
  private:
    Mode* items[];
    Mode* current;
  public:
    Modes();
    void advance();
    void set_current(String mode_name);
    String get_name();
    long get_time_limit();
    boolean is_action_type();
    boolean is_work_stage();
};

#endif
