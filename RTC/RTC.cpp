/*
 Copyright (c) Me. Given that it's a toy, you're free to play
 with it - just don't expect to survive if it breaks or explodes.
*/

#include "RTC.h"

#define I2C_ADDR 0x68


// Convert normal decimal numbers to binary coded decimal
byte RTC::decToBcd(byte val)
{
  return ( (val / 10 * 16) + (val % 10) );
}
byte RTC::bcdToDec(byte val)
{
  return ( (val / 16 * 10) + (val % 16) );
}

RTC::RTC() 
{
    _addr = I2C_ADDR;
}

RTC::RTC(dateTime dt) 
{
    _addr = I2C_ADDR;
    setDateTime(dt);
} 

void RTC::setDateTime(dateTime dt){
  Wire.beginTransmission(_addr);
  Wire.write(0); // set next input to start at the seconds register
  Wire.write(decToBcd(dt.second)); // set seconds
  Wire.write(decToBcd(dt.minute)); // set minutes
  Wire.write(decToBcd(dt.hour)); // set hours
  Wire.write(decToBcd(dt.dayOfWeek)); // set day of week (1=Sunday, 7=Saturday)
  Wire.write(decToBcd(dt.dayOfMonth)); // set date (1 to 31)
  Wire.write(decToBcd(dt.month)); // set month
  Wire.write(decToBcd(dt.year)); // set year (0 to 99)
  Wire.endTransmission();
                   
}

void RTC::setDateTime(byte second, byte minute, byte hour, byte dayOfWeek, byte
                   dayOfMonth, byte month, byte year){
  Wire.beginTransmission(_addr);
  Wire.write(0); // set next input to start at the seconds register
  Wire.write(decToBcd(second)); // set seconds
  Wire.write(decToBcd(minute)); // set minutes
  Wire.write(decToBcd(hour)); // set hours
  Wire.write(decToBcd(dayOfWeek)); // set day of week (1=Sunday, 7=Saturday)
  Wire.write(decToBcd(dayOfMonth)); // set date (1 to 31)
  Wire.write(decToBcd(month)); // set month
  Wire.write(decToBcd(year)); // set year (0 to 99)
  Wire.endTransmission();
                   
}

dateTime RTC::getDateTime(){
  dateTime dt;

  Wire.beginTransmission(_addr);
  Wire.write(0); // set DS3231 register pointer to 00h
  Wire.endTransmission();
  Wire.requestFrom(_addr, 7);
  // request seven bytes of data from DS3231 starting from register 00h
  dt.second = bcdToDec(Wire.read() & 0x7f);
  dt.minute = bcdToDec(Wire.read());
  dt.hour = bcdToDec(Wire.read() & 0x3f);
  dt.dayOfWeek = bcdToDec(Wire.read());
  dt.dayOfMonth = bcdToDec(Wire.read());
  dt.month = bcdToDec(Wire.read());
  dt.year = bcdToDec(Wire.read());

  return dt;
}


