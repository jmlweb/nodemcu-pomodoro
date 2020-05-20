#include "button.h";
#include "led_notifier.h";
#include "pomodoro.h";

Button start_button(D4);
Button stop_button(D3);
LedNotifier led_notifier(D2, D1);
Pomodoro pomodoro;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  start_button.config();
  stop_button.config();
  led_notifier.init();
}

void loop() {
  pomodoro.process();
  if (!pomodoro.is_pristine()) {
    led_notifier.resolve(pomodoro.current_mode());
  }
  if (start_button.is_active()) {
    pomodoro.start();
  } else if (stop_button.is_active()) {
    pomodoro.stop();
  }
}
