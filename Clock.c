#include <avr/io.h>
#include <inttypes.h>

#include "Clock.h"
#include "MatrixGraphs.h"
static volatile char hrs, min, seg, numero, aux1, aux2;
extern void putByteHex(char dato);
extern void UART0_putchar(char dato);

void Clock_Ini(char hora, char minuto, char segundo){
	hrs = hora;
	min = minuto;
	seg = segundo;
}

void Clock_Update(){
	seg++;
	if( seg > 59 ){
		seg = 0;
		min++;
	//	paintPixel(min,5,1);
		if( min > 59 ){
			min = 0;
			hrs++;
			if( hrs > 11 ){
				hrs = 0;
			}
		}
	}
}


void Clock_Display(){
//Escribe horas
	tiempoT_t hora_BDC = BCD_Time();

	putByteHex(hora_BDC.hora);
	UART0_putchar(':');

	//Escribe minutos
	
	putByteHex(hora_BDC.minu);
	UART0_putchar(':');

	//Escribe segundos
	
	putByteHex(hora_BDC.segu);

}

uint8_t BCD_Value(char valor)
{
	numero = valor;
	aux1 = numero/10;
	if(aux1 <=9){
	aux2 = numero %10;
	aux1 = aux1*16;
	numero = aux1+aux2;
	}
	//else{numero =0xEE;}
	return numero;
}

tiempoT_t BCD_Time(){
	tiempoT_t tiempoStruc;
	tiempoStruc.hora = BCD_Value(hrs);
	tiempoStruc.minu = BCD_Value(min);
	tiempoStruc.segu = BCD_Value(seg);
	return tiempoStruc;
}
tiempoT_t CurrentTime(){
	tiempoT_t tiempoStruc;
	tiempoStruc.hora = hrs;
	tiempoStruc.minu = min;
	tiempoStruc.segu = seg;
	return tiempoStruc;
}
