#ifndef MODE_H
#define MODE_H
#include <Arduino.h>

class Mode {
  public:
    String name;
    String type;
    String stage;
    byte time_limit;
    Mode* next;
    Mode(String name, String type, String state, byte time_limit);
    void set_next(Mode* next);
};

#endif
