#include "button.h"

#define DEBOUNCE_DELAY 50

Button::Button(byte pin) {
  this->pin = pin;
  this->last_state = NULL;
}

void Button::config() {
  pinMode(pin, INPUT_PULLUP);
  last_state = digitalRead(pin);
}

bool Button::is_active() {
  byte current_state = digitalRead(pin);
  if (current_state == LOW && last_state == HIGH) {
    last_state = current_state;
    return true;
  }
  last_state = current_state;
  return false;
};
