/*
 First toy class:
 It allows the easy use of I2C real time clocks such as those 
 based on the DS1307 chip - including the Duinotech RTC board.

 There are other libraries out there that do similar things,
 but I've found that their way of handing time/date information
 to be a pain in the arse. 

 I've defined a nice little dateTime struct that's easier to
 pass to other functions.

 Copyright (c) Me. Given that it's a toy, you're free to play
 with it - just don't expect to survive if it breaks or explodes.
 
*/

#include "Arduino.h"
#include <Wire.h>

#ifndef __RTC_H__
#define __RTC_H__


// Working with a dateTime structure is a lot more
// Friendly than working with discrete variables

typedef struct dateTime_s
{
    byte second;
    byte minute; 
    byte hour; 
    byte dayOfWeek;
    byte dayOfMonth; 
    byte month; 
    byte year;
  
} dateTime;


class RTC {
  public:
    RTC();
    // RTC(dateTime);
    void setDateTime(dateTime dt);
    void setDateTime(byte second, byte minute, byte hour, byte dayOfWeek, byte
                   dayOfMonth, byte month, byte year);
    dateTime getDateTime();
  private:
    int _addr;
    byte decToBcd(byte val);
    byte bcdToDec(byte val);
};

#endif
