#include "modes.h"

Mode waitingForWork("waitingForWork", "wait", "work", 0);
Mode working("working", "action", "work", 25);
Mode waitingForRelax("waitingForRelax", "wait", "relax", 0);
Mode relaxing("relaxing", "action", "relax", 5);

Modes::Modes() {
  waitingForWork.set_next(&working);
  working.set_next(&waitingForRelax);
  waitingForRelax.set_next(&relaxing);
  relaxing.set_next(&waitingForWork);
  this->current = &waitingForWork;
}

void Modes::advance() {
  current = current->next;
}

void Modes::set_current(String mode_name) {
  while(current->name != mode_name) {
    advance();
  }
}

String Modes::get_name() {
  return current->name;
}

long Modes::get_time_limit() {
  return current->time_limit;
}

boolean Modes::is_action_type() {
  return current->type == "action";
}

boolean Modes::is_work_stage() {
  return current->stage == "work";
}
