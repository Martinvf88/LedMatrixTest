#include <avr/interrupt.h>
#include <avr/io.h>
#include <inttypes.h>
#include "MatrixGraphs.h"
static volatile uint8_t Flag;

void Timer1_Ini(){
/* Inicializar Timer2             */

  TCCR1A |= (1<<WGM11); // Mode 14 (fast PWM), OC1A off
  TCCR1B |= (1<<WGM13) | (1<<WGM12) | (1<<CS10); // Mode 14, no prescale
  ICR1    = 100;
  TIMSK1 |= (1<<TOIE1); // Enable Timer1 interrupt
  sei();

}

uint8_t Timer1_Flag ( void ){
 if( Flag ){
 	Flag=0;
	PORTB |= (1<<3); //SCLK OFF
	return 1;
 }
 else return 0;
}

ISR(TIMER1_OVF_vect, ISR_BLOCK){

	Display();	
	TIFR1 |= TOV1;
	
}

