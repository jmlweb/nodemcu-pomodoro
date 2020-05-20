#include "timer.h"

Timer::Timer() {
  this->time_limit = 0;
  this->has_started = false;
  this->started_time;
}

Timer::Timer(byte minutes) {
  this->time_limit = minutes * 60 * 1000;
  this->has_started = true;
  this->started_time = millis();
}

int Timer::get_ellapsed_time() {
  return millis() - this->started_time;
}

int Timer::get_remaining_time() {
  return this->time_limit - this->get_ellapsed_time();
}

bool Timer::has_finished() {
  return this->get_remaining_time() <= 0;
}

void Timer::reset() {
  has_started = false;
  started_time = NULL;
}
