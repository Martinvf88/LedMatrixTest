#ifndef _EEPROM_H
#define _EEPROM_H

#include <inttypes.h>

void EEPROM_Ini(void);
void EEPROM_Write(uint16_t dir, uint8_t dato);
uint8_t EEPROM_Read(uint16_t dir);
#endif  
