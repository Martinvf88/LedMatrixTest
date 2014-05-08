#ifndef _CLOCK_H
#define _CLOCK_H

#include <inttypes.h>
#include <avr/io.h>

typedef struct {
uint8_t hora;   /* 1 byte          */
uint8_t minu;   /* 1 byte          */
uint8_t segu;   /* 1 byte incluye el edo. de la bat.  */
} tiempoT_t;

void Clock_Ini(char hora, char minuto, char segundo);
void Clock_Update(void);
void Clock_Display(void);
void ClockCheck(void);

uint8_t BCD_Value(char valor);
tiempoT_t BCD_Time(void);
tiempoT_t CurrentTime(void);
#endif
