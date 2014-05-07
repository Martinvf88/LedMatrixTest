#include <avr/io.h>
#include <inttypes.h>
#include <math.h>
#include "MatrixColor.h"
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
extern char UART0_getch (void);
extern void UART0_putchar(char dato);
extern void UART0_puts(const char *str);
extern void putByteHex(char dato);
extern void putWordHex (char *str);

void SecondPassed(uint8_t x, uint8_t y);
int button_pressed(void);
int button_pressed2(void);
int button_pressed3(void);


static volatile uint8_t  count, advance, j, retardo,teclazo =0;
static volatile uint16_t address =0;


uint8_t C = CIRCLEX0;
uint8_t O = CIRCLEY0;
uint8_t L = CIRCLER;
uint8_t minutes5,seconds,secs,done,mode_flag,modes;			 	   
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
					teclazo = 1;
				}
		}
	}
	
	clrscr();

	if (teclazo == 1){
		menu();
	}

	else{
		Clock_Ini(0,0,0);
	}

	current = CurrentTime();
	Timer1_Ini();
	address = TEXT_ADDRESS;
	mode_flag =3;
	while(count <8){
		marquee[count] = EEPROM_Read(address);
		count++;
		address++;	
	}
	
	
	while(1){
	
		if(modes==0){
			if(button_pressed()){
				
				mode_flag++;
				switch(mode_flag){
					case 1:{//if(mode_flag==1){
						//mode_flag=0;
						CleanMatrix();
						O = 15;
						L = 14;
						break;
					}
				//else{
					case 2:{
						CleanMatrix();
						O = CIRCLEY0;
						L = CIRCLER;
						break;
					}
					case 3:{//if(mode_flag==1){
						//mode_flag=0;
						CleanMatrix();
						O = 15;
						L = 14;
						seconds = 0;
						secs = 0;
						minutes5 = 0;
						break;
					}
					default:{
						CleanMatrix();
						mode_flag =0;
						break;
					}

				}
			}
		}
		
		if(modes ==1){
			if(button_pressed()){
				if(current.hora >=11){
					Clock_Ini(0,current.minu,current.segu);
				}
			
				else{
					Clock_Ini(current.hora+1,current.minu,current.segu);
				}
			}	

			if(button_pressed2()){
				if(current.minu >=59){
					Clock_Ini(0,current.minu,current.segu);
				}
			
				else{	
					Clock_Ini(current.hora,current.minu+1,current.segu);
				}
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

		if(mode_flag ==1){
			drawCircle(C, 15, 1, 14);
		}
		
		if(mode_flag ==2){
			drawCircle(C, O, 1, L);
			for(count=0;count<8;count++){		
				drawLetter(32+advance-4*count, 25, marquee[count], 6);
			}
		
		}	
		if(mode_flag !=3){
			MinuteHand(C,O,clockMinuteHandMatrix[current.minu][0],clockMinuteHandMatrix[current.minu][1], 2);
			HourHand(C,O,clockHourHandMatrix[current.hora][0],clockHourHandMatrix[current.hora][1], 4);
		}		

		if(Timer2_Flag()){
			SecondPassed(C, O);
		
			Clock_Update();
			gotoxy(6,10);
			Clock_Display();
			current = CurrentTime();
			advance++;

			if(mode_flag == 3){
				seconds++;
				secs++;
				if(secs == 60){
					minutes5++;	
					secs = 0;
				}
		
				if(minutes5 == 0 && seconds <=30){
					for(count=0;count<8;count++){		
						drawLetter(31+seconds-4*count, 10, marquee[count], 6);
					}
				
				}
				
				if(seconds ==30){
					done =1;
					CleanMatrix();
				}
				
				if(minutes5 < 5 && seconds >=30 && done == 1){
					drawCircle(C, O, 1, L);
					MinuteHand(C,O,clockMinuteHandMatrix[current.minu][0],clockMinuteHandMatrix[current.minu][1], 2);
					HourHand(C,O,clockHourHandMatrix[current.hora][0],clockHourHandMatrix[current.hora][1], 4);
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

