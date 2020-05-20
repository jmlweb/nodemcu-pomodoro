#include "mode.h"

Mode::Mode(String name, String type, String stage, byte time_limit) {
  this->name = name;
  this->type = type;
  this->stage = stage;
  this->time_limit = time_limit;
  this->next;
}

void Mode::set_next(Mode* next) {
  this->next = next;
}

