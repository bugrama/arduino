#include "eepromManager.h"
#include <EEPROM.h>

int eepromManager::readIntFromEEPROM(int address)
{
    int val;
    val = EEPROM.read(address);
    val |= EEPROM.read(address + 1) << 8;
    return val;
}

void eepromManager::writeIntToEEPROM(int address, int value)
{
    EEPROM.update(address, value & 0xff);
    EEPROM.update(address + 1, value >> 8);
}

int eepromManager::getXGyroOffset()
{
    return readIntFromEEPROM(AddrxGyroE);
}

int eepromManager::getYGyroOffset()
{
    return readIntFromEEPROM(AddryGyroE);
}

int eepromManager::getZGyroOffset()
{
    return readIntFromEEPROM(AddrzGyroE);
}

int eepromManager::getXAccelOffset()
{
    return readIntFromEEPROM(AddrxAccelE);
}

int eepromManager::getYAccelOffset()
{
    return readIntFromEEPROM(AddryAccelE);
}

int eepromManager::getZAccelOffset()
{
    return readIntFromEEPROM(AddrzAccelE);
}

void eepromManager::setXGyroOffset(int os)
{
    writeIntToEEPROM(AddrxGyroE, os);
}

void eepromManager::setYGyroOffset(int os)
{
    writeIntToEEPROM(AddryGyroE, os);
}

void eepromManager::setZGyroOffset(int os)
{
    writeIntToEEPROM(AddrzGyroE, os);
}

void eepromManager::setXAccelOffset(int os)
{
    writeIntToEEPROM(AddrxAccelE, os);
}

void eepromManager::setYAccelOffset(int os)
{
    writeIntToEEPROM(AddryAccelE, os);
}

void eepromManager::setZAccelOffset(int os)
{
    writeIntToEEPROM(AddrzAccelE, os);
}

bool eepromManager::getCalibFlag()
{
    return(readIntFromEEPROM(CalibFlagAddr) == CalibFlagTrue);
}

void eepromManager::setCalibFlag()
{
    writeIntToEEPROM(CalibFlagAddr, CalibFlagTrue);
}

void eepromManager::resetCalibFlag()
{
    writeIntToEEPROM(CalibFlagAddr, CalibFlagFalse);
}
