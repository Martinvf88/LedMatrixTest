#include <avr/interrupt.h>
#include <avr/io.h>
#include <inttypes.h>

void Delay_20mS (){
	volatile uint8_t j,k;
	j=40;
	k=14;
	do{
		do{
			asm("nop\n"
				"nop\n");   
		  } while(--j); 
	}while(--k);
}
