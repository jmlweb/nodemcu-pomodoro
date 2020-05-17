#include "modes.h"
#include "timer.h";
#include "led.h";
#include "button.h";

Modes modes;
Timer work_timer(25);
Timer relax_timer(5);
Led red_led(D2);
Led green_led(D1);
Button start_button(D4);
Button stop_button(D3);

void start() {
  if (modes.is_waiting()) {
    modes.advance();
    Timer timer = get_proper_timer();
    timer.init();
  }
}

void stop() {
  Serial.println(modes.get_current());
  Timer timer = get_proper_timer();
  timer.reset();
  if (modes.is_working() || modes.is_waiting_for_work()) {
    modes.go_to_waiting_for_relax();
  } else {
    modes.go_to_waiting_for_work();
  }
}

Timer get_proper_timer() {
  if (modes.is_working()) {
    return work_timer;
  }
  return relax_timer;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Timer *work_timer;
  Timer *relax_timer;
  red_led.config();
  green_led.config();
  start_button.config();
  stop_button.config();
}

void loop() {
  if (modes.is_waiting_for_work()) {
    Serial.println("waiting_for_work");
    red_led.stop_blink();
    red_led.off();
    green_led.blink();
  }
  if (modes.is_working()) {
    Serial.println("working");
    red_led.on();
    red_led.stop_blink();
    green_led.stop_blink();
    green_led.off();
  }
  if (modes.is_waiting_for_relax()) {
    Serial.println("waiting_for_relax");
    red_led.blink();
    green_led.stop_blink();
    green_led.off();
  }
  if (modes.is_relaxing()) {
    Serial.println("relaxing");
    red_led.off();
    red_led.stop_blink();
    green_led.stop_blink();
    green_led.on();
  }
  if (!modes.is_waiting()) {
    Timer timer = get_proper_timer();
    if (timer.has_finished()) {
      timer.reset();
      modes.advance();
    }
  };
  if (start_button.is_active()) {
    start();
  } else if (stop_button.is_active()) {
    stop();
  }
}
