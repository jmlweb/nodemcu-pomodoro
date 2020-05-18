#include "led_notifier.h"

LedNotifier::LedNotifier() {
  this->modes;
}

void LedNotifier::init(Modes *modes) {
  this->modes = modes;
}

void LedNotifier::info() {
  Serial.println(modes->get_current());
}
