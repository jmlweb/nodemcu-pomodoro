/*
  Mode.h
*/
#ifndef Mode_h
#define Mode_h

#include "Arduino.h";

class Mode
{
  public:
    Mode();
    Mode(int minutes);
    int getMinutes();

  private:
    int _minutes;
};

Mode::Mode()
{
  _minutes = 0;
};

Mode::Mode(int minutes)
{
  _minutes = minutes;
};

int Mode::getMinutes()
{
  return _minutes;
}

#endif
