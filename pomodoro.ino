#include "modes.h"

int started_time;
int remaining_time;
Modes modes;

void start() {
  if (modes.is_waiting()) {
    modes.advance();
    started_time = millis();
  }
}

void stop() {
  if (modes.is_working()) {
    modes.set_current(2);
  } else if (modes.is_waiting_for_relax()) {
    modes.set_current(0);
  } else {
    modes.advance();
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Modes *modes;
  start();
}

void loop() {
  if (!modes.is_waiting()) {
    int current_time = millis();
    remaining_time = 25 * 60 * 1000 - (current_time - started_time);
    Serial.println(round(remaining_time / 1000));
    if (remaining_time <= 0) {
      modes.advance();
    }
  };
  delay(100);
}
