#ifndef _ALPHABET_H
#define _ALPHABET_H
#include <inttypes.h>
#include <avr/pgmspace.h>

#include "EEPROM.h"
 uint8_t letters[325][5] PROGMEM = {//A
						  {8,8,0,8,8},
					      {8,0,8,0,8},
						  {8,0,0,0,8},
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  //B 5
						  {8,0,0,0,8},
						  {8,0,8,0,8},
						  {8,0,0,8,8},
						  {8,0,8,0,8},
						  {8,0,0,0,8},
						  //C 10
						  {8,8,0,0,8},
						  {8,0,8,8,8},
						  {8,0,8,8,8},
						  {8,0,8,8,8},
						  {8,8,0,0,8},
						  //D 15
						  {8,0,0,8,8},
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  {8,0,0,8,8},
						  //E 20
						  {8,0,0,0,8},
						  {8,0,8,8,8},
						  {8,0,0,0,8},
						  {8,0,8,8,8},
						  {8,0,0,0,8},
						  //F 25
						  {8,0,0,0,8},
						  {8,0,8,8,8},
						  {8,0,0,0,8},
						  {8,0,8,8,8},
						  {8,0,8,8,8},
						  //G 30
						  {8,8,0,0,8},
						  {8,0,8,8,8},
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  {8,8,0,0,8},
						  //H 35
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  {8,0,0,0,8},
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  //I 40
						  {8,0,0,0,8},
						  {8,8,0,8,8},
						  {8,8,0,8,8},
						  {8,8,0,8,8},
						  {8,0,0,0,8},
						  //J 45
						  {8,8,8,0,8},
						  {8,8,8,0,8},
						  {8,8,8,0,8},
						  {8,0,8,0,8},
						  {8,0,0,0,8},
				  		  //K 50
						  {8,0,8,0,8},
						  {8,0,0,8,8},
						  {8,0,0,8,8},
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  //L 55
						  {8,0,8,8,8},
						  {8,0,8,8,8},
						  {8,0,8,8,8},
						  {8,0,8,8,8},
						  {8,0,0,0,8},
						  //M 60
						  {8,0,8,0,8},
						  {8,0,0,0,8},
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  //N 65
						  {8,0,0,0,8},
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  //O 70
						  {8,0,0,0,8},
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  {8,0,0,0,8},
						  //P 75
						  {8,0,0,0,8},
						  {8,0,8,0,8},
						  {8,0,0,0,8},
						  {8,0,8,8,8},
						  {8,0,8,8,8},
						  //Q 80
						  {8,0,0,0,8},
						  {8,0,8,0,8},
						  {8,0,0,0,8},
						  {8,0,0,0,8},
						  {8,8,0,8,8},
						  //R 85
						  {8,0,0,0,8},
						  {8,0,8,0,8},
						  {8,0,0,8,8},
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  //S 90
						  {8,8,0,0,8},
						  {8,0,8,8,8},
						  {8,8,0,8,8},
						  {8,8,8,0,8},
						  {8,0,0,8,8},
						  //T 95
						  {8,0,0,0,8},
						  {8,8,0,8,8},
						  {8,8,0,8,8},
						  {8,8,0,8,8},
						  {8,8,0,8,8},
						  //U 100
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  {8,0,0,0,8},
						  //V 105
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  {8,8,0,8,8},
						  //W 110
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  {8,0,0,0,8},
						  {8,0,8,0,8},
						  //X 115
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  {8,8,0,8,8},
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  //Y 120
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  {8,8,0,8,8},
						  {8,8,0,8,8},
						  {8,8,0,8,8},
						  //Z 125
						  {8,0,0,0,8},
						  {8,8,8,0,8},
						  {8,8,0,8,8},
						  {8,0,8,8,8},
						  {8,0,0,0,8},
						  //a 130
						  {8,8,0,8,8},
					      {8,0,8,0,8},
						  {8,8,0,0,8},
						  {8,0,8,0,8},
						  {8,8,0,0,8},
						  //b 135
						  {8,0,8,8,8},
						  {8,0,8,8,8},
						  {8,0,0,0,8},
						  {8,0,8,0,8},
						  {8,0,0,0,8},
						  //c 140
						  {8,8,8,8,8},
						  {8,8,0,0,8},
						  {8,0,8,8,8},
						  {8,0,8,8,8},
						  {8,8,0,0,8},
						  //d 145
						  {8,8,8,0,8},
						  {8,8,8,0,8},
						  {8,0,0,0,8},
						  {8,0,8,0,8},
						  {8,0,0,8,8},
						  //e 150
						  {8,8,8,8,8},
						  {8,0,0,0,8},
						  {8,0,0,0,8},
						  {8,0,8,8,8},
						  {8,0,0,0,8},
						  //f
						  {8,8,0,0,8},
						  {8,0,8,8,8},
						  {8,0,0,8,8},
						  {8,0,8,8,8},
						  {8,0,8,8,8},
						  //g
						  {8,0,0,0,8},
						  {8,0,8,0,8},
						  {8,0,0,0,8},
						  {8,0,8,0,8},
						  {8,0,0,0,8},
						  //h
						  {8,0,8,8,8},
						  {8,0,8,8,8},
						  {8,0,0,0,8},
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  //i
						  {8,8,0,8,8},
						  {8,8,8,8,8},
						  {8,8,0,8,8},
						  {8,8,0,8,8},
						  {8,8,0,8,8},
						  //j
						  {8,8,8,8,8},
						  {8,8,0,8,8},
						  {8,8,0,8,8},
						  {8,8,0,8,8},
						  {8,0,0,8,8},
				  		  //k
						  {8,8,8,8,8},
						  {8,0,8,0,8},
						  {8,0,0,8,8},
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  //l
						  {8,8,0,8,8},
						  {8,8,0,8,8},
						  {8,8,0,8,8},
						  {8,8,0,8,8},
						  {8,8,0,8,8},
						  //m
						  {8,8,8,8,8},
						  {8,0,8,0,8},
						  {8,0,0,0,8},
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  //n
						  {8,8,8,8,8},
						  {8,8,8,8,8},
						  {8,0,0,0,8},
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  //o
						  {8,8,8,8,8},
						  {8,8,8,8,8},
						  {8,0,0,0,8},
						  {8,0,8,0,8},
						  {8,0,0,0,8},
						  //p
						  {8,8,8,8,8},
						  {8,0,0,8,8},
						  {8,0,8,0,8},
						  {8,0,0,8,8},
						  {8,0,8,8,8},
						  //q
						  {8,8,8,8,8},
						  {8,0,0,0,8},
						  {8,0,8,0,8},
						  {8,0,0,0,8},
						  {8,8,8,0,8},
						  //r
						  {8,8,8,8,8},
						  {8,8,8,8,8},
						  {8,0,0,0,8},
						  {8,0,8,8,8},
						  {8,0,8,8,8},
						  //s
						  {8,8,8,8,8},
						  {8,0,0,0,8},
						  {8,0,8,8,8},
						  {8,8,0,0,8},
						  {8,0,0,0,8},
						  //t
						  {8,8,0,8,8},
						  {8,0,0,0,8},
						  {8,8,0,8,8},
						  {8,8,0,8,8},
						  {8,8,0,0,8},
						  //u
						  {8,8,8,8,8},
						  {8,8,8,8,8},
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  {8,0,0,0,8},
						  //v
						  {8,8,8,8,8},
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  {8,8,0,8,8},
						  //w
						  {8,8,8,8,8},
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  {8,0,0,0,8},
						  {8,0,8,0,8},
						  //x
						  {8,8,8,8,8},
						  {8,8,8,8,8},
						  {8,0,8,0,8},
						  {8,8,0,8,8},
						  {8,0,8,0,8},
						  //y
						  {8,8,8,8,8},
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  {8,8,0,8,8},
						  {8,8,0,8,8},
						  //z
						  {8,8,8,8,8},
						  {8,0,0,0,8},
						  {8,8,0,8,8},
						  {8,0,8,8,8},
						  {8,0,0,0,8},
						  // /
						  {8,8,8,0,8},
						  {8,8,8,8,8},
						  {8,8,0,8,8},
						  {8,8,8,8,8},
						  {8,0,8,8,8},
						  //0
						  {8,8,0,8,8},
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  {8,8,0,8,8},
						  //1
						  {8,8,0,8,8},
						  {8,0,0,8,8},
						  {8,8,0,8,8},
						  {8,8,0,8,8},
						  {8,0,0,0,8},
						  //2
						  {8,0,0,0,8},
						  {8,8,8,0,8},
						  {8,0,0,0,8},
						  {8,0,8,8,8},
						  {8,0,0,0,8},
						  //3
						  {8,0,0,0,8},
						  {8,8,8,0,8},
						  {8,0,0,0,8},
						  {8,8,8,0,8},
						  {8,0,0,0,8},
						  //4
						  {8,0,8,0,8},
						  {8,0,8,0,8},
						  {8,0,0,0,8},
						  {8,8,8,0,8},
						  {8,8,8,0,8},
						  //5
						  {8,0,0,0,8},
						  {8,0,8,8,8},
						  {8,0,0,0,8},
						  {8,8,8,0,8},
						  {8,0,0,0,8},
						  //6
						  {8,0,0,0,8},
						  {8,0,8,8,8},
						  {8,0,0,0,8},
						  {8,0,8,0,8},
						  {8,0,0,0,8},
						  //7
						  {8,0,0,0,8},
						  {8,8,8,0,8},
						  {8,8,8,0,8},
						  {8,8,8,0,8},
						  {8,8,8,0,8},
						  //8
						  {8,0,0,0,8},
						  {8,0,8,0,8},
						  {8,8,0,8,8},
						  {8,0,8,0,8},
						  {8,0,0,0,8},
						  //9
						  {8,0,0,0,8},
						  {8,0,8,0,8},
						  {8,0,0,0,8},
						  {8,8,8,0,8},
						  {8,8,8,0,8},
						  //:
						  {8,8,8,8,8},
						  {8,0,0,0,8},
						  {8,8,8,8,8},
						  {8,0,0,0,8},
						  {8,8,8,8,8},
						  // blank
						  {8,8,8,8,8},
						  {8,8,8,8,8},
						  {8,8,8,8,8},
						  {8,8,8,8,8},
						  {8,8,8,8,8}};
#endif  /* _TIMER1_H */


