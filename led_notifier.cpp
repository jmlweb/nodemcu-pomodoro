#include "led_notifier.h"

LedNotifier::LedNotifier() {
  this->modes;
  this->green_led;
  this->red_led;
}

void LedNotifier::init(Modes *modes, Led *red_led, Led *green_led) {
  this->modes = modes;
  this->red_led = red_led;
  this->green_led = green_led;
}

void LedNotifier::update() {
  if (modes->is_waiting_for_work() || modes->is_relaxing()) {
    red_led->off();
  }
  if (modes->is_working() || modes->is_waiting_for_relax()) {
    green_led->off();
  }
  if (modes->is_waiting_for_work()) {
    green_led->blink();
  }
  if (modes->is_working()) {
    red_led->on();
  }
  if (modes->is_waiting_for_relax()) {
    red_led->blink();
  }
  if (modes->is_relaxing()) {
    green_led->on();
  }
}
