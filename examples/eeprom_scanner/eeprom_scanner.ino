#include "Wire.h"

byte start_address = 0;
byte end_address = 127;

void setup() {
    byte rc;
    Wire.begin();

    Serial.begin(9600);
    Serial.println("\nI2C Scanner");

    Serial.print("Scanning I2C bus from ");
    Serial.print(start_address,DEC);
    Serial.print(" to ");
    Serial.print(end_address,DEC);
    Serial.println("...");
    for(byte addr=start_address; addr <= end_address; addr++ ) {
        Wire.beginTransmission(addr);
        rc = Wire.endTransmission();
        if (addr<16)
            Serial.print("0");
        Serial.print(addr,HEX);
        if (rc==0) {
            Serial.print(" found!");
        } else {
            Serial.print(" "); Serial.print(rc); Serial.print("     ");
        }
        Serial.print( (addr%8)==7 ? "\n":" ");
    }

    Serial.println("\n-------------------------------\nPossible devices:");

    for(byte addr = start_address;
        addr <= end_address;
        addr++) {
        Wire.beginTransmission(addr);
    rc = Wire.endTransmission();
    if (rc == 0) {
        Serial.print(addr,HEX); Serial.print(" = ");
        switch (addr) {
            case 0x50: Serial.println("AT24C32/AT24C64 - EEPROM"); break;
            case 0x68: Serial.println("DS1307"); break;
            default: Serial.println("Unknown"); break;
        }
    }
}

Serial.println("\ndone");
}

// standard Arduino loop()
void loop()
{
// Nothing to do here, so we'll just blink the built-in LED
    digitalWrite(13,HIGH);
    delay(300);
    digitalWrite(13,LOW);
    delay(300);
}
