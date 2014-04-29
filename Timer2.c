#include <avr/interrupt.h>
#include <avr/io.h>
#include <inttypes.h>
#include "Clock.h"

static volatile uint8_t count; 
static volatile uint8_t Flag;

void Timer2_Ini( uint8_t baseT ){
/* Inicializar Timer2             */

	TIMSK2 = 0x00;  /* deshabilitar interrupciones del Timer2*/
	ASSR  = 0x20;  /* Seleccionar modo as�ncrono para uso del Xtal 32.768KHz  */
	TCCR2A = 0x02; 
	TCCR2B = 0x07;  /* Seleccionar modo de operaci�n del Timer2 y prescale  */
	/* Modo: CTC (Clear Timer on Compare Match)      */

	TCNT2 = 0x00;  /* borrar Timer2                */
	TIFR2 = 0x07;  /* borrar banderas de sobreflujo y comparaci�n      */
	OCR2A = (32*baseT)-1;  /* Escribir valor adecuado en OCR2A para generar       */
	/* sobreflujo cada segundo            */
	TIMSK2 = 0x02;  /* habilitar interrupci�n por Output-Compare del Timer2   */
	sei();     /* habilitar interrupciones (global)        */
}


void Timer2_OneSecIni( void ){
	/* Inicializar Timer2             */
	TIMSK2 = 0x00;  /* deshabilitar interrupciones del Timer2      */
	ASSR  = 0x20;  /* Seleccionar modo as�ncrono para uso del Xtal 32.768KHz  */
	TCCR2A = 0x02;
	TCCR2B = 0x07;  /* Seleccionar modo de operaci�n del Timer2 y prescale  */
	/* Modo: CTC (Clear Timer on Compare Match)      */
	/* Prescalar a: XXXX            */
 	TCNT2 = 0x00;  /* borrar Timer2                */
	TIFR2 = 0x07;  /* borrar banderas de sobreflujo y comparaci�n      */
	OCR2A = 0x7D;  /* Escribir valor adecuado en OCR2A para generar       */
	/* sobreflujo cada segundo            */
	TIMSK2 = 0x02;  /* habilitar interrupci�n por Output-Compare del Timer2   */
	sei();     /* habilitar interrupciones (global)        */
}

uint8_t Timer2_Flag ( void ){
	uint8_t tmp = Flag;
	if(tmp)Flag=0;
	return tmp;
}

/* Rutina de Servicio de Interrupci�n        */
/* para atender la interrupci�n por         */
/* Comparaci�n del Timer2 (TCNT2 y OCR2 son iguales)    */

ISR(TIMER2_COMPA_vect){
	count++;
	if(count>=125){ 
	count=0;  
	Flag = 1;
	}  /* Activa Bandera para indicar los 1 segundos */
//	Clock_Update();
}   /* fin de la rutina de servicio de Interrupci�n (RSI) */
