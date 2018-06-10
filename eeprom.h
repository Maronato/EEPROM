#ifndef eeprom_h
#define eeprom_h

class EEPROM {
public:
    EEPROM(int id);

    void write_byte(unsigned int address, byte data);

    byte read_byte(unsigned int address);

    // 32 bytes maximum!
    void read_buffer(unsigned int address, byte *buffer, int length);
private:
    int _id;
    void _access_memory(unsigned int address);
};

void eeprom_start(void);

#endif
