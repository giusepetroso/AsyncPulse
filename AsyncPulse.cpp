/*
  AsyncPulse.h - Library for getting a pulse with custom period.
  Created by Giuse Petroso, 2020.
  Released into the public domain.
*/
#include "Arduino.h"
#include "AsyncPulse.h"

AsyncPulse::AsyncPulse(int timeOn, int timeOff);
{
  _state = 1;
  _lastState = 0;
  _timeOn = timeOn;
  _timeOff = timeOff;
  _countOn = 0;
  _countOff = 0;
}

int AsyncPulse::get()
{
  // state rising edge
  bool risingEdge = _state == 1 && _lastState == 0;
  if (risingEdge)
    _countOn = millis();

  // state falling edge
  bool fallingEdge = _state == 0 && _lastState == 1;
  if (fallingEdge)
    _countOff = millis();

  if (_state == 1 && !risingEdge)
  {
    if (millis() - _countOn >= _timeOn)
      _state = 0;
  }

  if (_state == 0 && !fallingEdge)
  {
    if (millis() - _countOff >= _timeOff)
      _state = 1;
  }

  // return the state
  return _state;
}