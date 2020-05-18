#ifndef LED_NOTIFIER_H
#define LED_NOTIFIER_H
#include <Arduino.h>
#include "modes.h"

class LedNotifier {
  private:
    Modes *modes;

  public:
    LedNotifier();

    void init(Modes *modes);

    void info();
};

#endif
