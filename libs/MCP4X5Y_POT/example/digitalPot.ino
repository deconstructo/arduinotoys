#include <SPI.h>
#include <MCP4X5Y_POT.h>

/***
 * for the MCP 4151
 *  MCP   : Ard : Function
 *  Pin 1 : D10 : CS - Chip Select
 *  Pin 2 : D13 : SCK - Clock
 *  Pin 3 : D11 : SDI/SDO  - SPI In / SPI Out
 *  Pin 4 : Vss :
 *  Pin 5 : Vss : POA -
 *  Pin 6 : Potentiometer Wiper
 *  Pin 7 : VDD : POB
 *  Pin 8 : VDD 
 */

const int slaveSelectPin = 10;

void setup() {
  SPI.begin();
}

MCP4X5Y_POT pot(MCP415X,slaveSelectPin);

void loop() {
  // go through the six channels of the digital pot:
  
  // change the resistance on this channel from min to max:
  for (int level = 0; level < 255; level++) {
    pot.set(level);
    delay(1);
  }
  // wait a second at the top:
  delay(100);
  // change the resistance on this channel from max to min:
  for (int level = 0; level < 255; level++) {
    pot.set(255-level);
    delay(1);
  }

}


