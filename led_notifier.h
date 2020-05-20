#ifndef LED_NOTIFIER_H
#define LED_NOTIFIER_H
#include <Arduino.h>
#include "modes.h"
#include "led.h"

class LedNotifier {
  private:
    Modes *modes;
    Led *red_led;
    Led *green_led;

  public:
    LedNotifier();

    void init(Modes *modes, Led *red_led, Led *green_led);

    void update();
};

#endif
