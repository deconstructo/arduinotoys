/*
 Because I really hate looking at screens full of digitalWrite()s

 Copyright (c) Me. Given that it's a toy, you're free to play
 with it - just don't expect to survive if it breaks or explodes.
*/

#include "Relay.h"

Relay::Relay(int pin)
{
  pinMode(pin,OUTPUT);
  _pin = pin;
}

void Relay::on() 
{
  digitalWrite(_pin, HIGH);
}

void Relay::off() 
{
  digitalWrite(_pin, LOW);
}

int Relay::state() {
  return digitalRead(_pin);
}
