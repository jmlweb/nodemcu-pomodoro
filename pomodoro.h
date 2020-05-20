#ifndef POMODORO_H
#define POMODORO_H
#include <Arduino.h>
#include "modes.h";
#include "timer.h";

class Pomodoro {
  private:
    Modes modes;
    Timer timer;
    boolean pristine;
    boolean active;
  public:
    Pomodoro();
    void start();
    void stop();
    void process();
    boolean is_pristine();
    String current_mode();
};

#endif
