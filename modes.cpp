#include "modes.h"

byte const TOTAL_MODES = 4;
byte const WAIT_WORK = 0;
byte const WORK = 1;
byte const WAIT_RELAX = 2;
byte const RELAX = 3;

Modes::Modes() {
  this->current = 0;
};

void Modes::set_current(byte mode) {
  current = mode;
};

void Modes::advance() {
  current++;
  if (current >= TOTAL_MODES) {
    current = 0;
  }
};

byte Modes::get_current() {
  return current;
};

bool Modes::is_waiting_for_work() {
  return current == WAIT_WORK;
};

bool Modes::is_waiting_for_relax() {
  return current == WAIT_RELAX;
}

bool Modes::is_waiting() {
  return is_waiting_for_work() || is_waiting_for_relax();
}

bool Modes::is_working() {
  return current == WORK;
}

bool Modes::is_relaxing() {
  return current == RELAX;
}
