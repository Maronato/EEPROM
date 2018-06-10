/*
  *  Adapted from hkhijhe's sketch at eeprom.ino
  *
  *  Author: maronato
  *  Date: 06/9/2018
  *
  */
#include <Arduino.h>
#include <Wire.h>
#include "eeprom.h"

void eeprom_start(void) {
    Wire.begin();
}

EEPROM::EEPROM(int id) {
    _id = id;
}

void EEPROM::write_byte(unsigned int addr, byte data) {
    Wire.beginTransmission(_id);
    Wire.write((int)(addr >> 8)); // MSB
    Wire.write((int)(addr & 0xFF)); // LSB
    Wire.write(data);
    Wire.endTransmission();
    delay(10);
}

byte EEPROM::read_byte(unsigned int addr) {
    byte rdata = 0xFF;
    Wire.beginTransmission(_id);
    Wire.write((int)(addr >> 8)); // MSB
    Wire.write((int)(addr >> 8)); // LSB
    Wire.endTransmission();
    delay(10);
    Wire.requestFrom(_id, 1);
    if (Wire.available()) {
        rdata = Wire.read();
    }
    return rdata;
}

void EEPROM::read_buffer(unsigned int addr, byte *buffer, int length) {
    int i = 0;
    Wire.beginTransmission(_id);
    Wire.write((int)(addr >> 8)); // MSB
    Wire.write((int)(addr & 0xFF)); // LSB
    Wire.endTransmission();
    delay(10);
    Wire.requestFrom(_id, length);
    for ( i = 0; i < length; i++ )
        if (Wire.available())
            buffer[i] = Wire.read();
}

