#include <avr/io.h>
#include <inttypes.h>
#include "MatrixColor.h"

void setColorPixel(uint8_t color){ //1 Red, 2 Green, 3 Blue, 4 yellow-ish, 5 Purple-ish, 6 Light Blue, 7 White
	
	switch(color){
		case 1 :

       		PORTD |= (1<<2); //R0
			PORTD &= ~(1<<3); //G0
			PORTD &= ~(1<<4); //B0
		
			PORTD |= (1<<5); //R1
			PORTD &= ~(1<<6); //G1
			PORTD &= ~(1<<7); //B1

       		break;
		
		case 2 :

       		PORTD &= ~(1<<2); //R0
			PORTD |= (1<<3); //G0
			PORTD &= ~(1<<4); //B0
		
			PORTD &= ~(1<<5); //R1
			PORTD |= (1<<6); //G1
			PORTD &= ~(1<<7); //B1

       		break;

		case 3 :

       		PORTD &= ~(1<<2); //R0
			PORTD &= ~(1<<3); //G0
			PORTD |=(1<<4); //B0
		
			PORTD &= ~(1<<5); //R1
			PORTD &= ~(1<<6); //G1
			PORTD |=(1<<7); //B1

       		break;	 
		
		case 4 :

       		PORTD |= (1<<2); //R0
			PORTD |= (1<<3); //G0
			PORTD &= ~(1<<4); //B0
		
			PORTD |= (1<<5); //R1
			PORTD |= (1<<6); //G1
			PORTD &= ~(1<<7); //B1

       		break;
		
		case 5 :

       		PORTD |= (1<<2); //R0
			PORTD &= ~(1<<3); //G0
			PORTD |= (1<<4); //B0
		
			PORTD |= (1<<5); //R1
			PORTD &= ~(1<<6); //G1
			PORTD |= (1<<7); //B1

       		break;

		case 6 :

       		PORTD &= ~(1<<2); //R0
			PORTD |=(1<<3); //G0
			PORTD |=(1<<4); //B0
		
			PORTD &= ~(1<<5); //R1
			PORTD |=(1<<6); //G1
			PORTD |=(1<<7); //B1

       		break;	 
		
		case 7 :

       		PORTD |=(1<<2); //R0
			PORTD |=(1<<3); //G0
			PORTD |=(1<<4); //B0
		
			PORTD |=(1<<5); //R1
			PORTD |=(1<<6); //G1
			PORTD |=(1<<7); //B1

       		break;

		case 8 :

       		PORTD &=~ (1<<2); //R0
			PORTD &=~ (1<<3); //G0
			PORTD &=~ (1<<4); //B0
		
			PORTD &=~ (1<<5); //R1
			PORTD &=~ (1<<6); //G1
			PORTD &=~ (1<<7); //B1

       		break;

	}
}
