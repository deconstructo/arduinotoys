/*

 A class to drive MCP41XX/MCP42XX digitial potentiometers

 At present, only the:
        MCP 415X (single channel)
        MCP 425X (dual channel) 

 chips are supported.

 At the present, only setting a value is supported
 
 TODO: 
        implement a function to read the level

 Copyright (c) Me. Given that it's a toy, you're free to play
 with it - just don't expect to survive if it breaks or explodes.

*/

#include "MCP4X5Y_POT.h"


MCP4X5Y_POT::MCP4X5Y_POT(int type, int ss) {
  switch (type) {
    case MCP413X:
      _numChannels = 1;
      _maxval = 128;
      break;

    case MCP423X:
      _numChannels = 2;
      _maxval = 128;
      break;

    case MCP414X:
      _numChannels = 1;
      _maxval = 128;
      break;

    case MCP424X:
      _numChannels = 2;
      _maxval = 128;
      break;
   
    case MCP415X:
      _numChannels = 1;
      _maxval = 256;
      break;

    case MCP425X:
      _numChannels = 2;
      _maxval = 256;
      break;

    case MCP416X:
      _numChannels = 1;
      _maxval = 256;
      break;

    case MCP426X:
      _numChannels = 2;
      _maxval = 256;
      break; 

  }
   pinMode(ss, OUTPUT);
  _ss = ss;
}

MCP4X5Y_POT::set(int value) {
  if ((value >= 0) && (value <= _maxval)) {
    digitalPotWrite(0, value);
    return 1;
  } else return EVAL;
}

MCP4X5Y_POT::set(int channel, int value) {

  if (channel < (_numChannels - 1))
    if ((value >= 0) && (value <= _maxval)) {
      digitalPotWrite(channel, value);
      return 1;
    } else return EVAL;

  else
    return ECHAN;
}

void MCP4X5Y_POT::digitalPotWrite(int channel, int value) {
  // take the SS pin low to select the chip:
  digitalWrite(_ss, LOW);
  //  send in the address and value via SPI:
  SPI.transfer(channel);
  SPI.transfer(value);
  // take the SS pin high to de-select the chip:
  digitalWrite(_ss, HIGH);
}
