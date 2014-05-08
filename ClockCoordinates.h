#ifndef _ClockCoordinates_H
#define _ClockCoordinates_H

#include <inttypes.h>
#include <avr/pgmspace.h>

#define CIRCLEX0 15
#define CIRCLEY0 12
#define CIRCLER 12

#define CIRCLEY02 15
#define CIRCLER2 14

uint8_t marquee[8] = {0,0,0,0,0,0,0,0};

uint8_t clockMinuteHandMatrix[60][2] PROGMEM = {{CIRCLEX0,CIRCLEY0-CIRCLER+2},//12
								 	     
										 {CIRCLEX0-1,CIRCLEY0-CIRCLER+2},//01 
										 {CIRCLEX0-2,CIRCLEY0-CIRCLER+3},//02
										 {CIRCLEX0-3,CIRCLEY0-CIRCLER+4},//03
										 {CIRCLEX0-4,CIRCLEY0-CIRCLER+5},//04
										 {CIRCLEX0-4,CIRCLEY0-7},//1
								 	   	 
										 {CIRCLEX0-5,CIRCLEY0-7},//06
										 {CIRCLEX0-5,CIRCLEY0-6},//07
								 	   	 {CIRCLEX0-6,CIRCLEY0-5},//08
								 	   	 {CIRCLEX0-6,CIRCLEY0-4},//09
								 	   	 
										 {CIRCLEX0-7,CIRCLEY0-4}, //2
								 	     
										 {CIRCLEX0-8,CIRCLEY0-4}, //011
										 {CIRCLEX0-7,CIRCLEY0-3}, //012
										 {CIRCLEX0-7,CIRCLEY0-2}, //013
										 {CIRCLEX0-7,CIRCLEY0-1}, //014
										 
										 {CIRCLEX0-CIRCLER+2,CIRCLEY0}, //3
								 	     
										 {CIRCLEX0-CIRCLER+2,CIRCLEY0+1}, //16
										 {CIRCLEX0-CIRCLER+3,CIRCLEY0+2}, //17
										 {CIRCLEX0-CIRCLER+4,CIRCLEY0+3}, //18
										 {CIRCLEX0-CIRCLER+5,CIRCLEY0+4}, //19
										 
										 {CIRCLEX0-7,CIRCLEY0+4}, //4
								 	     
										 {CIRCLEX0-6,CIRCLEY0+4}, //021
										 {CIRCLEX0-6,CIRCLEY0+5}, //022
										 {CIRCLEX0-5,CIRCLEY0+6}, //023
										 {CIRCLEX0-5,CIRCLEY0+7}, //024
										   
										 {CIRCLEX0-4,CIRCLEY0+7}, //5
								 	     
										 {CIRCLEX0-3,CIRCLEY0+6}, //26
								 	     {CIRCLEX0-3,CIRCLEY0+7}, //27
								 	     {CIRCLEX0-2,CIRCLEY0+7}, //28
								 	     {CIRCLEX0-1,CIRCLEY0+7}, //29
								 	     
										 {CIRCLEX0,CIRCLEY0+CIRCLER-2}, //6
								 	     
										 {CIRCLEX0+1,CIRCLEY0+CIRCLER-2}, //31
								 	     {CIRCLEX0+2,CIRCLEY0+CIRCLER-2}, //32
								 	     {CIRCLEX0+3,CIRCLEY0+CIRCLER-2}, //33
								 	     {CIRCLEX0+4,CIRCLEY0+CIRCLER-2}, //34
								 	     
										 {CIRCLEX0+4,CIRCLEY0+7}, //7
								 	     
										 {CIRCLEX0+5,CIRCLEY0+7}, //36
								 	     {CIRCLEX0+5,CIRCLEY0+6}, //37
								 	     {CIRCLEX0+6,CIRCLEY0+5}, //38
								 	     {CIRCLEX0+7,CIRCLEY0+5}, //39
								 	     
										 {CIRCLEX0+7,CIRCLEY0+4}, //8
								 	     
										 {CIRCLEX0+6,CIRCLEY0+3}, //41
								 	     {CIRCLEX0+7,CIRCLEY0+3}, //42
								 	     {CIRCLEX0+7,CIRCLEY0+2}, //43
								 	     {CIRCLEX0+7,CIRCLEY0+1}, //44
								 	     
										 {CIRCLEX0+CIRCLER-2,CIRCLEY0}, //9
								 	     
										 {CIRCLEX0+CIRCLER-2,CIRCLEY0-1}, //46
								 	     {CIRCLEX0+CIRCLER-1,CIRCLEY0-1}, //47
								 	     {CIRCLEX0+CIRCLER-2,CIRCLEY0-2}, //48
								 	     {CIRCLEX0+CIRCLER-2,CIRCLEY0-3}, //49
								 	     
										 {CIRCLEX0+7,CIRCLEY0-4}, //10
								 	     
										 {CIRCLEX0+7,CIRCLEY0-5}, //51
								 	     {CIRCLEX0+6,CIRCLEY0-5}, //52
								 	     {CIRCLEX0+6,CIRCLEY0-6}, //53
								 	     {CIRCLEX0+5,CIRCLEY0-6}, //54
								 	     
										 {CIRCLEX0+4,CIRCLEY0-7}, //11
										 
										 {CIRCLEX0+4,CIRCLEY0-CIRCLER+1}, //56
										 {CIRCLEX0+3,CIRCLEY0-CIRCLER+2}, //57
										 {CIRCLEX0+2,CIRCLEY0-CIRCLER+3}, //58
								 	   	 {CIRCLEX0+1,CIRCLEY0-CIRCLER+2}};//59


uint8_t clockMinuteHandMatrix2[60][2] PROGMEM = {{CIRCLEX0,CIRCLEY02-CIRCLER2+2},//12
								 	     
										 {CIRCLEX0-1,CIRCLEY02-CIRCLER2+2},//01 
										 {CIRCLEX0-2,CIRCLEY02-CIRCLER2+3},//02
										 {CIRCLEX0-3,CIRCLEY02-CIRCLER2+4},//03
										 {CIRCLEX0-4,CIRCLEY02-CIRCLER2+5},//04
										 {CIRCLEX0-4,CIRCLEY02-7},//1
								 	   	 
										 {CIRCLEX0-5,CIRCLEY02-7},//06
										 {CIRCLEX0-5,CIRCLEY02-6},//07
								 	   	 {CIRCLEX0-6,CIRCLEY02-5},//08
								 	   	 {CIRCLEX0-6,CIRCLEY02-4},//09
								 	   	 
										 {CIRCLEX0-7,CIRCLEY02-4}, //2
								 	     
										 {CIRCLEX0-8,CIRCLEY02-4}, //011
										 {CIRCLEX0-7,CIRCLEY02-3}, //012
										 {CIRCLEX0-7,CIRCLEY02-2}, //013
										 {CIRCLEX0-7,CIRCLEY02-1}, //014
										 
										 {CIRCLEX0-CIRCLER2+2,CIRCLEY02}, //3
								 	     
										 {CIRCLEX0-CIRCLER2+2,CIRCLEY02+1}, //16
										 {CIRCLEX0-CIRCLER2+3,CIRCLEY02+2}, //17
										 {CIRCLEX0-CIRCLER2+4,CIRCLEY02+3}, //18
										 {CIRCLEX0-CIRCLER2+5,CIRCLEY02+4}, //19
										 
										 {CIRCLEX0-7,CIRCLEY02+4}, //4
								 	     
										 {CIRCLEX0-6,CIRCLEY02+4}, //021
										 {CIRCLEX0-6,CIRCLEY02+5}, //022
										 {CIRCLEX0-5,CIRCLEY02+6}, //023
										 {CIRCLEX0-5,CIRCLEY02+7}, //024
										   
										 {CIRCLEX0-4,CIRCLEY02+7}, //5
								 	     
										 {CIRCLEX0-3,CIRCLEY02+6}, //26
								 	     {CIRCLEX0-3,CIRCLEY02+7}, //27
								 	     {CIRCLEX0-2,CIRCLEY02+7}, //28
								 	     {CIRCLEX0-1,CIRCLEY02+7}, //29
								 	     
										 {CIRCLEX0,CIRCLEY02+CIRCLER2-2}, //6
								 	     
										 {CIRCLEX0+1,CIRCLEY02+CIRCLER2-2}, //31
								 	     {CIRCLEX0+2,CIRCLEY02+CIRCLER2-2}, //32
								 	     {CIRCLEX0+3,CIRCLEY02+CIRCLER2-2}, //33
								 	     {CIRCLEX0+4,CIRCLEY02+CIRCLER2-2}, //34
								 	     
										 {CIRCLEX0+4,CIRCLEY02+7}, //7
								 	     
										 {CIRCLEX0+5,CIRCLEY02+7}, //36
								 	     {CIRCLEX0+5,CIRCLEY02+6}, //37
								 	     {CIRCLEX0+6,CIRCLEY02+5}, //38
								 	     {CIRCLEX0+7,CIRCLEY02+5}, //39
								 	     
										 {CIRCLEX0+7,CIRCLEY02+4}, //8
								 	     
										 {CIRCLEX0+6,CIRCLEY02+3}, //41
								 	     {CIRCLEX0+7,CIRCLEY02+3}, //42
								 	     {CIRCLEX0+7,CIRCLEY02+2}, //43
								 	     {CIRCLEX0+7,CIRCLEY02+1}, //44
								 	     
										 {CIRCLEX0+CIRCLER2-2,CIRCLEY02}, //9
								 	     
										 {CIRCLEX0+CIRCLER2-2,CIRCLEY02-1}, //46
								 	     {CIRCLEX0+CIRCLER2-1,CIRCLEY02-1}, //47
								 	     {CIRCLEX0+CIRCLER2-2,CIRCLEY02-2}, //48
								 	     {CIRCLEX0+CIRCLER2-2,CIRCLEY02-3}, //49
								 	     
										 {CIRCLEX0+7,CIRCLEY02-4}, //10
								 	     
										 {CIRCLEX0+7,CIRCLEY02-5}, //51
								 	     {CIRCLEX0+6,CIRCLEY02-5}, //52
								 	     {CIRCLEX0+6,CIRCLEY02-6}, //53
								 	     {CIRCLEX0+5,CIRCLEY02-6}, //54
								 	     
										 {CIRCLEX0+4,CIRCLEY02-7}, //11
										 
										 {CIRCLEX0+4,CIRCLEY02-CIRCLER2+1}, //56
										 {CIRCLEX0+3,CIRCLEY02-CIRCLER2+2}, //57
										 {CIRCLEX0+2,CIRCLEY02-CIRCLER2+3}, //58
								 	   	 {CIRCLEX0+1,CIRCLEY02-CIRCLER2+2}};//59

uint8_t quadrantCoordinates[12][2] PROGMEM = {{CIRCLEX0,CIRCLEY0-CIRCLER},//12
								 	     {CIRCLEX0-7,CIRCLEY0-9},//1 
								 	   	 {CIRCLEX0-10,CIRCLEY0-5}, //2
								 	     {CIRCLEX0-CIRCLER+1,CIRCLEY0}, //3
								 	     {CIRCLEX0-10,CIRCLEY0+5}, //4
								 	     {CIRCLEX0-7,CIRCLEY0+9}, //5
								 	     {CIRCLEX0,CIRCLEY0+CIRCLER-1}, //6
								 	     {CIRCLEX0+7,CIRCLEY0+9}, //7
								 	     {CIRCLEX0+10,CIRCLEY0+5}, //8
								 	     {CIRCLEX0+CIRCLER-1,CIRCLEY0}, //9
								 	     {CIRCLEX0+10,CIRCLEY0-5}, //10
								 	     {CIRCLEX0+7,CIRCLEY0-9}}; //11

uint8_t quadrantCoordinates2[12][2] PROGMEM = {{CIRCLEX0,CIRCLEY02-CIRCLER2},//12
								 	     {CIRCLEX0-8,CIRCLEY02-10},//1 
								 	   	 {CIRCLEX0-11,CIRCLEY02-6}, //2
								 	     {CIRCLEX0-CIRCLER2+2,CIRCLEY02}, //3
								 	     {CIRCLEX0-11,CIRCLEY02+6}, //4
								 	     {CIRCLEX0-8,CIRCLEY02+10}, //5
								 	     {CIRCLEX0,CIRCLEY02+CIRCLER2}, //6
								 	     {CIRCLEX0+7,CIRCLEY02+10}, //7
								 	     {CIRCLEX0+12,CIRCLEY02+6}, //8
								 	     {CIRCLEX0+CIRCLER2-1,CIRCLEY02}, //9
								 	     {CIRCLEX0+12,CIRCLEY02-6}, //10
								 	     {CIRCLEX0+9,CIRCLEY02-10}}; //11

uint8_t clockHourHandMatrix[12][2] PROGMEM = {{CIRCLEX0,CIRCLEY0-CIRCLER+5},//12
								 	     {CIRCLEX0-4,CIRCLEY0-7},//1 
								 	   	 {CIRCLEX0-7,CIRCLEY0-4}, //2
								 	     {CIRCLEX0-CIRCLER+5,CIRCLEY0}, //3
								 	     {CIRCLEX0-7,CIRCLEY0+4}, //4
								 	     {CIRCLEX0-4,CIRCLEY0+7}, //5
								 	     {CIRCLEX0,CIRCLEY0+CIRCLER-5}, //6
								 	     {CIRCLEX0+4,CIRCLEY0+7}, //7
								 	     {CIRCLEX0+7,CIRCLEY0+4}, //8
								 	     {CIRCLEX0+CIRCLER-5,CIRCLEY0}, //9
								 	     {CIRCLEX0+7,CIRCLEY0-4}, //10
								 	     {CIRCLEX0+4,CIRCLEY0-7}}; //11

uint8_t clockHourHandMatrix2[12][2] PROGMEM = {{CIRCLEX0,CIRCLEY02-CIRCLER2+5},//12
								 	     {CIRCLEX0-4,CIRCLEY02-7},//1 
								 	   	 {CIRCLEX0-7,CIRCLEY02-4}, //2
								 	     {CIRCLEX0-CIRCLER2+5,CIRCLEY02}, //3
								 	     {CIRCLEX0-7,CIRCLEY02+4}, //4
								 	     {CIRCLEX0-4,CIRCLEY02+7}, //5
								 	     {CIRCLEX0,CIRCLEY02+CIRCLER2-5}, //6
								 	     {CIRCLEX0+4,CIRCLEY02+7}, //7
								 	     {CIRCLEX0+7,CIRCLEY02+4}, //8
								 	     {CIRCLEX0+CIRCLER2-5,CIRCLEY02}, //9
								 	     {CIRCLEX0+7,CIRCLEY02-4}, //10
								 	     {CIRCLEX0+4,CIRCLEY02-7}}; //11

#endif
