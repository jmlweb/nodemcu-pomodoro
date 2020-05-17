#include "button.h"

int const DEBOUNCE_DELAY = 50;

Button::Button(byte pin) {
  this->pin = pin;
  this->last_state = NULL;
}

void Button::config() {
  pinMode(pin, INPUT_PULLUP);
  last_state = digitalRead(pin);
  Serial.println(last_state);
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
