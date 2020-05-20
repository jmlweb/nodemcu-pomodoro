#include "led_notifier.h"

LedNotifier::LedNotifier(byte red_led_pin, byte green_led_pin) {
  this->red_led = Led(red_led_pin);
  this->green_led = Led(green_led_pin);
}

void LedNotifier::init() {
  this->red_led.config();
  this->green_led.config();
}

void LedNotifier::resolve(String mode) {
  if (mode == "waitingForWork" || mode == "relaxing") {
    red_led.off();
  } else {
    green_led.off();
  }

  if (mode == "waitingForWork") {
    green_led.blink();
  }
  if (mode == "working") {
    red_led.on();
  }
  if (mode == "waitingForRelax") {
    red_led.blink();
  }
  if (mode == "relaxing") {
    green_led.on();
  }
}
