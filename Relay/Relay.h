/*
 Because I really hate looking at screens full of digitalWrite()s

 Copyright (c) Me. Given that it's a toy, you're free to play
 with it - just don't expect to survive if it breaks or explodes.
*/

#include "Arduino.h"

#ifndef __RELAY_H__
#define __RELAY_H__

class Relay
{
  public:
    Relay (int pin);
    void on();
    void off();
    int state();
  private:
    int _pin;
};

#endif
