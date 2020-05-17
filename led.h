#ifndef LED_H
#define LED_H
#include <Arduino.h>

class Led {
  private:
    int started_time;
    byte pin;

  public:
    Led();
    Led(byte pin);

    void config();

    void on();

    void off();

    void blink();

    void stop_blink();
};

#endif
