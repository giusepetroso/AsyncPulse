/*
  AsyncPulse.h - Library for getting a pulse with custom period.
  Created by Giuse Petroso, 2020.
  Released into the public domain.
*/
#ifndef AsyncPulse_h
#define AsyncPulse_h

#include "Arduino.h"

class AsyncPulse
{
public:
  AsyncPulse(int timeOn, int timeOff);
  int get();

private:
  int _state, _timeOn, _timeOff, _countOn, _countOff;
};

#endif