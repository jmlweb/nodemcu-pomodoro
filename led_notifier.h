#ifndef LED_NOTIFIER_H
#define LED_NOTIFIER_H
#include <Arduino.h>
#include "led.h"

class LedNotifier {
  private:
    Led red_led;
    Led green_led;

  public:
    LedNotifier(byte red_led_pin, byte green_led_pin);

    void init();

    void resolve(String mode);
};

#endif
