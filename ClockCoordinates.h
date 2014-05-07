#ifndef _ClockCoordinates_H
#define _ClockCoordinates_H

#include <inttypes.h>

#define CIRCLEX0 15
#define CIRCLEY0 12
#define CIRCLER 12

uint8_t marquee[8] = {0,0,0,0,0,0,0,0};

uint8_t clockMinuteHandMatrix[60][2] = {{CIRCLEX0,CIRCLEY0-CIRCLER+2},//12
								 	     
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
								 	     
										 {CIRCLEX0-6,CIRCLEY0+4}, //011
										 {CIRCLEX0-6,CIRCLEY0+4}, //012
										 {CIRCLEX0-5,CIRCLEY0+5}, //013
										 {CIRCLEX0-5,CIRCLEY0+6}, //014
										   
										 {CIRCLEX0-4,CIRCLEY0+7}, //5
								 	     
										 {CIRCLEX0-4,CIRCLEY0+7}, //5
								 	     {CIRCLEX0-4,CIRCLEY0+7}, //5
								 	     {CIRCLEX0-4,CIRCLEY0+7}, //5
								 	     {CIRCLEX0-4,CIRCLEY0+7}, //5
								 	     
										 {CIRCLEX0,CIRCLEY0+CIRCLER-2}, //6
								 	     
										 {CIRCLEX0,CIRCLEY0+CIRCLER-2}, //6
								 	     {CIRCLEX0,CIRCLEY0+CIRCLER-2}, //6
								 	     {CIRCLEX0,CIRCLEY0+CIRCLER-2}, //6
								 	     {CIRCLEX0,CIRCLEY0+CIRCLER-2}, //6
								 	     
										 {CIRCLEX0+4,CIRCLEY0+7}, //7
								 	     
										 {CIRCLEX0+4,CIRCLEY0+7}, //7
								 	     {CIRCLEX0+4,CIRCLEY0+7}, //7
								 	     {CIRCLEX0+4,CIRCLEY0+7}, //7
								 	     {CIRCLEX0+4,CIRCLEY0+7}, //7
								 	     
										 {CIRCLEX0+7,CIRCLEY0+4}, //8
								 	     
										 {CIRCLEX0+7,CIRCLEY0+4}, //8
								 	     {CIRCLEX0+7,CIRCLEY0+4}, //8
								 	     {CIRCLEX0+7,CIRCLEY0+4}, //8
								 	     {CIRCLEX0+7,CIRCLEY0+4}, //8
								 	     
										 {CIRCLEX0+CIRCLER-2,CIRCLEY0}, //9
								 	     
										 {CIRCLEX0+CIRCLER-2,CIRCLEY0}, //9
								 	     {CIRCLEX0+CIRCLER-2,CIRCLEY0}, //9
								 	     {CIRCLEX0+CIRCLER-2,CIRCLEY0}, //9
								 	     {CIRCLEX0+CIRCLER-2,CIRCLEY0}, //9
								 	     
										 {CIRCLEX0+7,CIRCLEY0-4}, //10
								 	     
										 {CIRCLEX0+7,CIRCLEY0-4}, //10
								 	     {CIRCLEX0+7,CIRCLEY0-4}, //10
								 	     {CIRCLEX0+7,CIRCLEY0-4}, //10
								 	     {CIRCLEX0+7,CIRCLEY0-4}, //10
								 	     
										 {CIRCLEX0+4,CIRCLEY0-7}, //11
										 
										 {CIRCLEX0+4,CIRCLEY0-CIRCLER+1}, //56
										 {CIRCLEX0+3,CIRCLEY0-CIRCLER+2}, //57
										 {CIRCLEX0+2,CIRCLEY0-CIRCLER+3}, //58
								 	   	 {CIRCLEX0+1,CIRCLEY0-CIRCLER+2}};//59

uint8_t clockHourHandMatrix[12][2]  = {{CIRCLEX0,CIRCLEY0-CIRCLER+5},//12
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
#endif
