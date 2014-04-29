#include <avr/io.h>
#include <inttypes.h>
#include <math.h>
#include "MatrixColor.h"
#include "MatrixGraphs.h"
#include "Timer2.h"
#include "Timer1.h"
#include "Delay20.h"
#include "Clock.h"
#include "Configuration.h"

#define CIRCLEX0 19	
#define CIRCLEY0 7
#define CIRCLER 7


extern void UART0_Init (char modo);
extern char UART0_kbhit (void);
extern char UART0_getch (void);
extern void UART0_putchar(char dato);
extern void UART0_puts(const char *str);
extern void putByteHex(char dato);
extern void putWordHex (char *str);

void cleanLatch(uint8_t x);
void SecondPassed(uint8_t x, uint8_t y);

static volatile uint8_t min1, min2, min3, min4, min5, min6, min7, min8, min9, min10, min11, min12 =0;
static volatile uint8_t hr1, hr2, hr3, hr4, hr5, hr6, hr7, hr8, hr9, hr10, hr11, hr12 =0;
static volatile uint8_t min, hora ,i, m5,mLED1,mLED2,mLED3,mLED4, retardo,teclazo =0;
static volatile uint16_t sec =0;

uint8_t C = CIRCLEX0;
uint8_t O = CIRCLEY0;
uint8_t L = CIRCLER;

uint8_t clockMinuteHandMatrix[12][12] = {{3,8,8,8,8,8,8,8,8,8,8,8},
								 	     {8,3,8,8,8,8,8,8,8,8,8,8},
								   		 {8,8,3,8,8,8,8,8,8,8,8,8},
								  		 {8,8,8,3,8,8,8,8,8,8,8,8},
								  		 {8,8,8,8,3,8,8,8,8,8,8,8},
								  		 {8,8,8,8,8,3,8,8,8,8,8,8},
								  		 {8,8,8,8,8,8,3,8,8,8,8,8},
								  		 {8,8,8,8,8,8,8,3,8,8,8,8},
								  		 {8,8,8,8,8,8,8,8,3,8,8,8},
								  		 {8,8,8,8,8,8,8,8,8,3,8,8},
								  		 {8,8,8,8,8,8,8,8,8,8,3,8},
								  		 {8,8,8,8,8,8,8,8,8,8,8,3}};

uint8_t minuteLEDMatrix[5][5] = {{8,8,8,8,8},
								 {4,8,8,8,8},
								 {4,4,8,8,8},
								 {4,4,4,8,8},
								 {4,4,4,4,8}};

uint8_t clockHourHandMatrix[12][12] = {{2,8,8,8,8,8,8,8,8,8,8,8},
									   {8,2,8,8,8,8,8,8,8,8,8,8},
									   {8,8,2,8,8,8,8,8,8,8,8,8},
									   {8,8,8,2,8,8,8,8,8,8,8,8},
									   {8,8,8,8,2,8,8,8,8,8,8,8},
									   {8,8,8,8,8,2,8,8,8,8,8,8},
								  	   {8,8,8,8,8,8,2,8,8,8,8,8},
								       {8,8,8,8,8,8,8,2,8,8,8,8},
								       {8,8,8,8,8,8,8,8,2,8,8,8},
								       {8,8,8,8,8,8,8,8,8,2,8,8},
								       {8,8,8,8,8,8,8,8,8,8,2,8},
									   {8,8,8,8,8,8,8,8,8,8,8,2}};



void cleanLatch(uint8_t x){

	PORTD &= ~(1<<2); //R0
	PORTD &= ~(1<<3); //G0
	PORTD &= ~(1<<4); //B0
	PORTD &= ~(1<<5); //R1
	PORTD &= ~(1<<6); //G1
	PORTD &= ~(1<<7); //B1

	for(i = 0; i<x; i++)
	{
		PORTB &= ~(1<<3); //SCLK OFF
		PORTB |= (1<<3); //SCLK OFF
	}
}


int main( void ){

	DDRB = 0x0E;      /* configura de salida los bits 1 al 3 el PORTB  DDRB= 00001110      */ 
	PORTB = 0x0A;     /* presentar valor inicial en puerto  PORTB= 00000010      */

	DDRC = 0x0F;      /* configura de salida los bits 0 al 3 el PORTC DDRC= 00001111      */ 
	PORTC = 0x00;     /* presentar valor inicial en puerto PORTC= 00000000      */
	
	DDRD = 0xFC;      /* configura de salida los bits 2 al 7 el PORTD DDRD= 11111100      */
	PORTD = 0x00;     /* presentar valor inicial en puerto PORTD= 00000000 */

	UART0_Init(0x01);
	min = 6;
	hora = 3;
	Timer2_OneSecIni();

	while(1){
		
		PORTB &= ~(1<<1);
		drawCircle(C, O, 1, L);
//		drawLetter(32, 19, 'F', 0, 7);
/*
		paintPixel(2, 2, 1);
		paintPixel(27, 16, 2);
		paintPixel(12, 12, 7);
*/

/*

		drawLetter(32, 19, 'F', 0, 7);
		drawLetter(28, 19, 'U', 0, 7);
		drawLetter(24, 19, 'I', 0, 7);
		drawLetter(19, 19, 'X', 0, 7);

		
		drawLetter(32, 25, 'C', 0, 7);
		drawLetter(28, 25, 'A', 0, 7);
		drawLetter(24, 25, 'F', 0, 7);
		drawLetter(20, 25, 'E', 0, 7);

*/
		
		drawVerticalLine(C, O-5, min12, L-2); // 12
		drawDiagonal2(C-3, O-5, min1, L-3); //1
		drawDiagonal3(C-5, O-3, min2, L-3);//2
		drawHorizontalLine(C-5, O, min3, L-2);// 3
		drawCounterDiagonal3(C, O, min4, L-2);//4
		drawCounterDiagonal2(C, O, min5, L-2); //5
		drawVerticalLine(C, O+2, min6, L-2); // 6
		drawDiagonal2(C, O, min7, L-2);//7
		drawDiagonal3(C, O, min8, L-2);//8
		drawHorizontalLine(C+2, O, min9, L-2);//9
		drawCounterDiagonal3(C+5, O-3, min10, L-3);//10
		drawCounterDiagonal2(C+3, O-5, min11, L-3); //11
		
		drawHorizontalLine(16, 30, mLED1, 1);
		drawHorizontalLine(16, 30, mLED2, 2);
		drawHorizontalLine(16, 30, mLED3, 3);
		drawHorizontalLine(16, 30, mLED4, 4);
		
		drawVerticalLine(C, O-5, hr12, L-4); // 12
		drawDiagonal2(C-3, O-5, hr1, L-5); //1
		drawDiagonal3(C-2, O-2, hr2, L-5);//2
		drawHorizontalLine(C-5, O, hr3, L-4);// 3
		drawCounterDiagonal3(C, O, hr4, L-4);//4
		drawCounterDiagonal2(C, O, hr5, L-4); //5
		drawVerticalLine(C, O+2, hr6, L-4); // 6
		drawDiagonal2(C, O, hr7, L-4);//7
		drawDiagonal3(C, O, hr8, L-4);//8
		drawHorizontalLine(C+2, O, hr9, L-4);//9
		drawCounterDiagonal3(C+5, O-3, hr10, L-5);//10
		drawCounterDiagonal2(C+3, O-5, hr11, L-5); //11		

		min12 = clockMinuteHandMatrix[min][0];
		hr12 = clockHourHandMatrix[hora][0];
		
		if(Timer2_Flag()){
			//Display();
			SecondPassed(C, O);
			Clock_Update();
			sec++;
			i++;
			if (sec == 60){
				m5++;
				
				sec=1;
			}
			if(i == 8){
				
				i=1;
			}
			if(m5 == 5){
				min++;
				m5=0;
			}
		}
		
		mLED1 = minuteLEDMatrix[m5][0];
		mLED2 = minuteLEDMatrix[m5][1];
		mLED3 = minuteLEDMatrix[m5][2];
		mLED4 = minuteLEDMatrix[m5][3];

		min1 = clockMinuteHandMatrix[min][1];
		min2 = clockMinuteHandMatrix[min][2];
		min3 = clockMinuteHandMatrix[min][3];
		min4 = clockMinuteHandMatrix[min][4];
		min5 = clockMinuteHandMatrix[min][5];
		min6 = clockMinuteHandMatrix[min][6];
		min7 = clockMinuteHandMatrix[min][7];
		min8 = clockMinuteHandMatrix[min][8];
		min9 = clockMinuteHandMatrix[min][9];
		min10 = clockMinuteHandMatrix[min][10];
		min11 = clockMinuteHandMatrix[min][11];
		min12 = clockMinuteHandMatrix[min][0];

		if(min==12)
		{
			hora++;
			min=0;
		}

		hr1 = clockHourHandMatrix[hora][1];
		hr2 = clockHourHandMatrix[hora][2];
		hr3 = clockHourHandMatrix[hora][3];
		hr4 = clockHourHandMatrix[hora][4];
		hr5 = clockHourHandMatrix[hora][5];
		hr6 = clockHourHandMatrix[hora][6];
		hr7 = clockHourHandMatrix[hora][7];
		hr8 = clockHourHandMatrix[hora][8];
		hr9 = clockHourHandMatrix[hora][9];
		hr10 = clockHourHandMatrix[hora][10];
		hr11 = clockHourHandMatrix[hora][11];
		hr12 = clockHourHandMatrix[hora][0];

		if(hora==12)
		{
			hora=0;
		}		
	
	}
	return 0; 
}

void SecondPassed(uint8_t x, uint8_t y){
		
		PORTB |= (1<<2);
		paintPixel(x, y, 7);
		PORTB &= ~(1<<2);
	 	
		Delay_20mS();
		
		PORTB |= (1<<2);
		paintPixel(x, y, 8);
		PORTB &= ~(1<<2);
}
