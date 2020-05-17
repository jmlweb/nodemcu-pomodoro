#ifndef BUTTON_H
#define BUTTON_H
#include <Arduino.h>

class Button {
  private:
    byte pin;
    byte last_state;

  public:
    Button(byte pin);

    void config();

    bool is_active();
};

#endif
