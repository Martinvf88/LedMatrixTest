#include <avr/io.h>
#include <inttypes.h>
#include "MatrixGraphs.h"
#include "ClockCoordinates.h"
#include "Timer2.h"
#include "Timer1.h"
#include "Configuration.h"
#include "Delay20.h"
#include "Clock.h"
#include "Menu.h"
#include "EEPROM.h"


extern void UART0_Init (char modo);
extern char UART0_kbhit (void);

void SecondPassed(uint8_t x, uint8_t y);
void Romans(uint8_t type);

int button_pressed(void);
int button_pressed2(void);
int button_pressed3(void);


static volatile uint8_t  count, advance, romanEnable, retardo,keyStroke, mode_flag, modes ,i=0;
static volatile uint16_t address =0;


uint8_t C = CIRCLEX0;
uint8_t O = CIRCLEY0;
uint8_t L = CIRCLER;

uint8_t O2 = CIRCLEY02;
uint8_t L2 = CIRCLER2;

uint8_t minutes5,seconds,secs,done;			 	   
tiempoT_t current ;

int main( void ){

	PortConfig();
	Timer2_OneSecIni();
	UART0_Init(51);

	while(retardo <5)
	{
		if( Timer2_Flag () )
		{
			retardo++;
		 	Delay_20mS();
			if(UART0_kbhit() != 0x00)
				{
					retardo = 5;
					keyStroke = 1;
				}
		}
	}
	
	clrscr();

	if (keyStroke == 1){
		menu();
	}

	else{
		Clock_Ini(0,0,0);
	}

	current = CurrentTime();
	Timer1_Ini();
	address = TEXT_ADDRESS;
	mode_flag =1;
	while(count <8){
		marquee[count] = EEPROM_Read(address);
		count++;
		address++;	
	}
	
	
	while(1){
	
		switch(modes){
		
			case 0:{
				if(button_pressed()){
				
					mode_flag++;
					switch(mode_flag){
						case 1:{
							CleanMatrix();
							break;
						}

						case 2:{
							CleanMatrix();
							advance=0;
							break;
						}
						case 3:{
							CleanMatrix();
							seconds = 0;
							secs = 0;
							minutes5 = 0;
							break;
						}
						default:{
							CleanMatrix();
							mode_flag =1;
							break;
						}

					}
				}
				
			if(button_pressed2()){
				if(romanEnable == 1){
					romanEnable =0;
				}
				else{
					romanEnable =1;
				}		
				CleanMatrix();
			}
				break;
			}
		
			case 1:{
				if(button_pressed()){
					
					Clock_Ini(current.hora+1,current.minu,current.segu);
					ClockCheck();
				}	

				if(button_pressed2()){
					
					Clock_Ini(current.hora,current.minu+1,current.segu);
					ClockCheck();
					
				}	
				break;		
			}
		}
	
	
		if(button_pressed3()){
			if(modes == 1){
				modes =0;
			}
			else{
				modes =1;
			}		
		}
	
		switch(mode_flag){

			case 1: {
		
				if(romanEnable == 1){
					Romans(1);
					drawCircle(C, O2, 1, L2);
				}
				else{
					for(i=0;i<12;i++){
						drawSquare(pgm_read_byte(&quadrantCoordinates2[i][0]), pgm_read_byte(&quadrantCoordinates2[i][1]), 1, 1);
					}
				}
				MinuteHand(C,O2,pgm_read_byte(&clockMinuteHandMatrix2[current.minu][0]),pgm_read_byte(&clockMinuteHandMatrix2[current.minu][1]), 2);
				HourHand(C,O2,pgm_read_byte(&clockHourHandMatrix2[current.hora][0]),pgm_read_byte(&clockHourHandMatrix2[current.hora][1]), 4);
				break;
			}
		
			case 2: {
				
				if(romanEnable == 1){
					Romans(2);
					drawCircle(C, O, 1, L);
				}
				else{
					for(i=0;i<12;i++){
				drawSquare(pgm_read_byte(&quadrantCoordinates[i][0]), pgm_read_byte(&quadrantCoordinates[i][1]), 1, 1);}
				
				}
			
				MinuteHand(C,O,pgm_read_byte(&clockMinuteHandMatrix[current.minu][0]),pgm_read_byte(&clockMinuteHandMatrix[current.minu][1]), 2);
				HourHand(C,O,pgm_read_byte(&clockHourHandMatrix[current.hora][0]),pgm_read_byte(&clockHourHandMatrix[current.hora][1]), 4);
				for(count=0;count<8;count++){		
					drawLetter(32+advance-4*count, 25, marquee[count], 6);
				}
				break;
		
			}	
		}
		
		if(Timer2_Flag()){
			if(mode_flag == 1){
				SecondPassed(C, O2);
			}
			else{
				SecondPassed(C, O);
			}	
			Clock_Update();
			gotoxy(6,10);
			Clock_Display();
			current = CurrentTime();
			
			advance++;
			if(advance ==32){
				CleanMessage();
				advance =0;
			}

			if(mode_flag == 3){
				seconds++;
				secs++;
		
				if(minutes5 == 0 && seconds <=30){
					for(count=0;count<8;count++){		
						drawLetter(31+seconds-4*count, 10, marquee[count], 6);
					}
				
				}
				
				if(seconds ==30){
					done =1;
					CleanMatrix();
				}

				if(secs == 60){
					minutes5++;	
					secs = 0;
				}
				
				if(minutes5 < 5 && seconds >=30 && done == 1){
					drawCircle(C, O, 1, L);
					if(romanEnable == 1){
						Romans(2);
					}
				
					MinuteHand(C,O,pgm_read_byte(&clockMinuteHandMatrix[current.minu][0]),pgm_read_byte(&clockMinuteHandMatrix[current.minu][1]), 2);
					HourHand(C,O,pgm_read_byte(&clockHourHandMatrix[current.hora][0]),pgm_read_byte(&clockHourHandMatrix[current.hora][1]), 4);
				}
				
				if(minutes5>=5){
					minutes5 =0;
					done =0;
					seconds = 0;
					CleanMatrix();
				}
			}

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

int button_pressed()
{
	return !(PINB & (1<<PORTB0));
	Delay_20mS();
	Delay_20mS();
//	Delay_20mS();
}

int button_pressed2()
{
	return !(PINB & (1<<PORTB4));
	Delay_20mS();
	Delay_20mS();
//	Delay_20mS();
}

int button_pressed3()
{
	return !(PINB & (1<<PORTB5));
	Delay_20mS();
	Delay_20mS();
	//Delay_20mS();
}

void Romans(uint8_t type){

	switch(type){
		
		case 1:{

			drawRoman(9, 5, 'I',6);				

			drawRoman(6, 9, 'I',5);			
			drawRoman(8, 9, 'I',5);			

			drawRoman(8, 14, 'I',7);
			drawRoman(6, 14, 'I',7);
			drawRoman(4, 14, 'I',7);
			
			drawRoman(8, O2+L2-11, 'I',5);				
			drawRoman(6, O2+L2-11, 'V',5);

			drawRoman(10, O2+L2-7, 'V',6);				

			drawRoman(17, O2+L2-3, 'V',7);
			drawRoman(14, O2+L2-3, 'I',7);

			drawRoman(24, O2+L2-7, 'V',6);
			drawRoman(21, O2+L2-7, 'I',6);
			drawRoman(19, O2+L2-7, 'I',6);
			
			drawRoman(27, O2+L2-11, 'V',5);
			drawRoman(24, O2+L2-11, 'I',5);
			drawRoman(22, O2+L2-11, 'I',5);
			drawRoman(20, O2+L2-11, 'I',5);

			drawRoman(28, 14, 'I',7);
			drawRoman(25, 14, 'X',7);
			
			drawRoman(26, 9, 'X',5);
	
			drawRoman(23, 5, 'X',6);
			drawRoman(20, 5, 'I',6);

			drawRoman(18, 2, 'X',7);
			drawRoman(15, 2, 'I',7);
			drawRoman(13, 2, 'I',7);

			break;
		}
		
		case 2:{
			drawRoman(23, 9, 'X',7);
			drawRoman(26, 9, 'I',7);
			
			drawRoman(18, 1, 'X',7);
			drawRoman(15, 1, 'I',7);
			drawRoman(13, 1, 'I',7);

			drawRoman(10, 9, 'I',7);
			drawRoman(8, 9, 'I',7);
			drawRoman(6, 9, 'I',7);

			drawRoman(18, O+L-3, 'V',7);
			drawRoman(15, O+L-3, 'I',7);
			break;
		}
	}

}
