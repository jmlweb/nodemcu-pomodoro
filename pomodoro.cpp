#include "pomodoro.h"

Pomodoro::Pomodoro() {
  Modes modes;
  this->modes = modes;
  this->pristine = true;
  this->timer;
}

void Pomodoro::start() {
  if (!modes.is_action_type()) {
    modes.advance();
    if (pristine) {
      pristine = false;
    }
    timer = Timer(modes.get_time_limit());
  }
}

void Pomodoro::stop() {
  if (!pristine) {
    timer.reset();
    if (modes.is_work_stage()) {
      modes.set_current("waitingForRelax");
    } else {
      modes.set_current("waitingForWork");
    }
  }
}

void Pomodoro::process() {
  if (modes.is_action_type()) {
    // Serial.println(timer.get_remaining_time());
    if (timer.has_finished()) {
      timer.reset();
      modes.advance();
    }
  }
}

boolean Pomodoro::is_pristine() {
  return pristine;
}

String Pomodoro::current_mode() {
  return modes.get_name();
}
