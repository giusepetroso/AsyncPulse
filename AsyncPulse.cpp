/*
  AsyncPulse.h - Library for getting a pulse with custom period.
  Created by Giuse Petroso, 2020.
  Released into the public domain.
*/
#include "Arduino.h"
#include "AsyncPulse.h"

AsyncPulse::AsyncPulse(int timeOn, int timeOff)
{
  _state = 1;
  _timeOn = timeOn;
  _timeOff = timeOff;
  _countOn = 0;
  _countOff = 0;
}

int AsyncPulse::get()
{
  if (_state == 1)
  {
    if (millis() - _countOn >= _timeOn)
    {
      _state = 0;
      _countOff = millis();
    }
  }

  if (_state == 0)
  {
    if (millis() - _countOff >= _timeOff)
    {
      _state = 1;
      _countOn = millis();
    }
  }

  // Serial.print("STATE: ");
  // Serial.print(_state);
  // Serial.print(" | LAST STATE: ");
  // Serial.print(_lastState);
  // Serial.print(" | TON: ");
  // Serial.print(millis() - _countOn);
  // Serial.print(" / ");
  // Serial.print(_timeOn);
  // Serial.print(" | FOFF: ");
  // Serial.print(millis() - _countOff);
  // Serial.print(" / ");
  // Serial.print(_timeOff);
  // Serial.println("");

  // return the state
  return _state;
}