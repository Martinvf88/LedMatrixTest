#include <avr/io.h>
#include <inttypes.h>

void EEPROM_Ini()
{
	EECR &= ~(1<<EEPM1);
	EECR &= ~(1<<EEPM0); // Borrar y Escribir en una sola operación
	EECR &= ~(1<<EERIE); // Deshabitilar la Interrupción de EEPROM Ready

	//EECR |= (1<<EEMPE);
	//EECR |= (1<<EEPE);
	//EECR |= (1<<EERE);
}

void EEPROM_Write(uint16_t dir, uint8_t dato)
{
/* Wait for completion of previous write*/
while(EECR & (1<<EEPE));
/* Set up address and Data Registers */
EEAR = dir;
EEDR = dato;
/* Write logical one to EEMPE */
EECR |= (1<<EEMPE);
/* Start eeprom write by setting EEPE */
EECR |= (1<<EEPE);
}

uint8_t EEPROM_Read(uint16_t dir)
{
/* Wait for completion of previous write */
while(EECR & (1<<EEPE));
/* Set up address register */
EEAR = dir;
/* Start eeprom read by writing EERE */
EECR |= (1<<EERE);
/* Return data from Data Register */
return EEDR;
}
