/*
 A class to drive MCP4X5Y digitial potentiometers

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

#include "Arduino.h"
#include <SPI.h>

#ifndef __MCP4X5Y_POT_H__
#define __MCP4X5Y_POT_H__

#define MCP413X  1
#define MCP423X  2

#define MCP414X  3
#define MCP424X  4

#define MCP415X  5
#define MCP425X  6

#define MCP416X  7
#define MCP426X  8

#define ECHAN   -1
#define EVAL    -2


class MCP4X5Y_POT
{
  public:
    MCP4X5Y_POT(int type, int ss);

    int set(int value);
    int set(int channel, int value);

  private:
    void digitalPotWrite(int address, int value);
    int _type;
    int _numChannels;
    int _ss;
    int _maxval;

};

#endif
