#include "led.h"

unsigned int const BLINKING_TIME = 500;

Led::Led() {
  this->pin;
  this->started_time = NULL;
}

Led::Led(byte pin) {
  this->pin = pin;
  this->started_time = NULL;
}

void Led::config() {
  pinMode(pin, OUTPUT);
}

void Led::on() {
  digitalWrite(pin, HIGH);
  started_time = NULL;
}

void Led::off() {
  digitalWrite(pin, LOW);
  started_time = NULL;
}

void Led::blink() {
  if (!started_time) {
    started_time = millis();
  } else {
    if ((millis() - started_time) >= BLINKING_TIME) {
      started_time = millis();
      if (digitalRead(pin) == HIGH) {
        digitalWrite(pin, LOW);
      } else {
        digitalWrite(pin, HIGH);
      }
    }
  }
}

void Led::stop_blink() {
  started_time = NULL;
}
