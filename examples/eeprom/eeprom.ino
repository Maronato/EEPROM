// Adapted from http://tronixstuff.com/2010/10/29/tutorial-arduino-and-the-i2c-bus-part-two/

#include "eeprom.h"  // for I2C
#define chip1 0x50 // device address for left-hand chip on our breadboard

// always have your values in variables
unsigned int pointer = 69; // we need this to be unsigned, as you may have an address > 32767
byte d=0; // example variable to handle data going in and out of EERPROMS

void setup()
{
    Serial.begin(9600); // for screen output
    eeprom_start();
}

void loop()
{
    EEPROM ee = EEPROM(chip1);
    byte d;
    Serial.println("Writing data...");
    for (int a=0; a<20; a++)
    {
        ee.write_byte(a, a);
        d = ee.read_byte(a);
        Serial.println(d);
    }
    Serial.println("Reading data...");
    for (int a=0; a<20; a++)
    {
        Serial.print("chip1 pointer ");
        Serial.print(a);
        Serial.print(" holds ");
        d = ee.read_byte(a);
        Serial.println(d);
    }
}
