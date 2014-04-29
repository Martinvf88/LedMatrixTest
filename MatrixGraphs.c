#include <avr/io.h>
#include <inttypes.h>
#include "MatrixColor.h"
#include "MatrixGraphs.h"
#include "Alphabet.h"
#include "EEPROM.h"
#include <string.h>
#include <stdlib.h>

static volatile uint8_t i =0;
static volatile uint8_t j =0;



void paintPixel(uint8_t x, uint8_t y, uint8_t color){


	uint8_t loop;
	setColorPixel(color);
	if (y <= 16){
				
		PORTD &= ~(1<<5); //R1
		PORTD &= ~(1<<6); //G1
		PORTD &= ~(1<<7); //B1
	}

	else{
	
		PORTD &= ~(1<<2); //R0
		PORTD &= ~(1<<3); //G0
		PORTD &= ~(1<<4); //B0
		
	}	


	PORTB &= ~(1<<3); //SCLK on
	PORTC = y;
	PORTB |= (1<<3); //SCLK OFF

	PORTD &= ~(1<<2); //R0
	PORTD &= ~(1<<3); //G0
	PORTD &= ~(1<<4); //B0
	PORTD &= ~(1<<5); //R1
	PORTD &= ~(1<<6); //G1
	PORTD &= ~(1<<7); //B1


	for(loop = 0; loop<x; loop++)
	{
		PORTB &= ~(1<<3); //SCLK OFF	
		PORTB |= (1<<3); //SCLK OFF
	}
}

void drawLetter(uint8_t x0, uint8_t y0, uint16_t letter, uint8_t lettercase,uint8_t color){

	if(lettercase ==0){
		letter = (letter-65)*(5);
	}
	if(lettercase ==1){
		letter = (letter-70)*(5) -5;
	}
	if(lettercase ==2){
		letter = 260+(letter*5);
	}
	uint8_t i,j=0;
	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			PORTB &= ~(1<<2);
			paintPixel(x0-j,y0+i,(pgm_read_byte(&letters[letter+i][j]))+color);
			PORTB |= (1<<2);
		}
	}
}


void drawSquare(uint8_t x0, uint8_t y0, uint8_t color, uint8_t length){

	PORTB &= ~(1<<2);
	drawHorizontalLine(x0, y0, color, length);
	PORTB |= (1<<2);
	PORTB &= ~(1<<2);
	drawHorizontalLine(x0, y0+length-1, color, length);
	PORTB |= (1<<2);
	PORTB &= ~(1<<2);
	drawVerticalLine(x0, y0, color, length);
	PORTB |= (1<<2);
	PORTB &= ~(1<<2);
	drawVerticalLine(x0+length-1, y0, color, length);
	PORTB |= (1<<2);
}

void drawDiagonal2(uint8_t x0, uint8_t y0, uint8_t color, uint8_t lenght){

	//setColorPixel(color);
	if (y0 <= 15){
				
		PORTD &= ~(1<<5); //R1
		PORTD &= ~(1<<6); //G1
		PORTD &= ~(1<<7); //B1
	}

	else {
	
		PORTD &= ~(1<<2); //R0
		PORTD &= ~(1<<3); //G0
		PORTD &= ~(1<<4); //B0
		
		}
	for(i=0; i<lenght; i++){
		//PORTB &= ~(1<<3); //SCLK on
		
		PORTB |= (1<<2);
		paintPixel(x0+i,y0+(i*2),color);
		PORTB &= ~(1<<2);
		//PORTB |= (1<<3); //SCLK on
		
	}

}

void drawDiagonal3(uint8_t x0, uint8_t y0, uint8_t color, uint8_t lenght){

	//setColorPixel(color);
	if (y0 <= 15){
				
		PORTD &= ~(1<<5); //R1
		PORTD &= ~(1<<6); //G1
		PORTD &= ~(1<<7); //B1
	}

	else {
	
		PORTD &= ~(1<<2); //R0
		PORTD &= ~(1<<3); //G0
		PORTD &= ~(1<<4); //B0
		
		}
	for(i=0; i<lenght; i++){
		//PORTB &= ~(1<<3); //SCLK on
		
		PORTB |= (1<<2);
		paintPixel(x0+(i*2),y0+i,color);
		PORTB &= ~(1<<2);
		//PORTB |= (1<<3); //SCLK on
		
	}

}


void drawDiagonal(uint8_t x0, uint8_t y0, uint8_t color, uint8_t lenght){

	//setColorPixel(color);
	if (y0 <= 15){
				
		PORTD &= ~(1<<5); //R1
		PORTD &= ~(1<<6); //G1
		PORTD &= ~(1<<7); //B1
	}

	else {
	
		PORTD &= ~(1<<2); //R0
		PORTD &= ~(1<<3); //G0
		PORTD &= ~(1<<4); //B0
		
		}
	for(i=0; i<lenght; i++){
		//PORTB &= ~(1<<3); //SCLK on
		
		PORTB |= (1<<2);
		paintPixel(x0+i,y0+i,color);
		PORTB &= ~(1<<2);
		//PORTB |= (1<<3); //SCLK on
		
	}

}

void drawCounterDiagonal(uint8_t x0, uint8_t y0, uint8_t color, uint8_t x1){

	//setColorPixel(color);
	if (y0 <= 15){
				
		PORTD &= ~(1<<5); //R1
		PORTD &= ~(1<<6); //G1
		PORTD &= ~(1<<7); //B1
	}

	else {
	
		PORTD &= ~(1<<2); //R0
		PORTD &= ~(1<<3); //G0
		PORTD &= ~(1<<4); //B0
		
		}
	for(i=0; i<x1; i++){
		//PORTB &= ~(1<<3); //SCLK on
		PORTB |= (1<<2);
		paintPixel(x0-i,y0+i,color);
		PORTB &= ~(1<<2);
		
		//PORTB |= (1<<3); //SCLK on
	
	}

}

void drawCounterDiagonal2(uint8_t x0, uint8_t y0, uint8_t color, uint8_t x1){

	//setColorPixel(color);
	if (y0 <= 15){
				
		PORTD &= ~(1<<5); //R1
		PORTD &= ~(1<<6); //G1
		PORTD &= ~(1<<7); //B1
	}

	else {
	
		PORTD &= ~(1<<2); //R0
		PORTD &= ~(1<<3); //G0
		PORTD &= ~(1<<4); //B0
		
		}
	for(i=0; i<x1 -1; i++){
		//PORTB &= ~(1<<3); //SCLK on
		PORTB |= (1<<2);
		paintPixel(x0-i,y0+(i*2),color);
		PORTB &= ~(1<<2);
		
		//PORTB |= (1<<3); //SCLK on
	
	}

}

void drawCounterDiagonal3(uint8_t x0, uint8_t y0, uint8_t color, uint8_t x1){

	//setColorPixel(color);
	if (y0 <= 15){
				
		PORTD &= ~(1<<5); //R1
		PORTD &= ~(1<<6); //G1
		PORTD &= ~(1<<7); //B1
	}

	else {
	
		PORTD &= ~(1<<2); //R0
		PORTD &= ~(1<<3); //G0
		PORTD &= ~(1<<4); //B0
		
		}
	for(i=0; i<x1; i++){
		//PORTB &= ~(1<<3); //SCLK on
		PORTB |= (1<<2);
		paintPixel(x0-(i*2),y0+i,color);
		PORTB &= ~(1<<2);
		
		//PORTB |= (1<<3); //SCLK on
	
	}

}
void drawHorizontalLine(uint8_t x0, uint8_t y0, uint8_t color, uint8_t x1){

	//setColorPixel(color);
	if (y0 <= 15){
				
		PORTD &= ~(1<<5); //R1
		PORTD &= ~(1<<6); //G1
		PORTD &= ~(1<<7); //B1
	}

	else {
	
		PORTD &= ~(1<<2); //R0
		PORTD &= ~(1<<3); //G0
		PORTD &= ~(1<<4); //B0
		
		}
	for(i=0; i<x1; i++){
		//PORTB &= ~(1<<3); //SCLK on
		PORTB &= ~(1<<2);
		paintPixel(x0+i,y0,color);
		PORTB |= (1<<2);
		//PORTB |= (1<<3); //SCLK on
	
	}

}

void drawVerticalLine(uint8_t x0, uint8_t y0, uint8_t color, uint8_t x1){

	//setColorPixel(color);
	if (y0 <= 15){
				
		PORTD &= ~(1<<5); //R1
		PORTD &= ~(1<<6); //G1
		PORTD &= ~(1<<7); //B1
	}

	else {
	
		PORTD &= ~(1<<2); //R0
		PORTD &= ~(1<<3); //G0
		PORTD &= ~(1<<4); //B0
		
		}
	for(i=0; i<x1; i++){
		//PORTB &= ~(1<<3); //SCLK on
		PORTB &= ~(1<<2);
		paintPixel(x0,y0+i,color);
		PORTB |= (1<<2);
		//PORTB |= (1<<3); //SCLK on
	
	}

}

void drawCircle(int16_t x0, int16_t y0, int16_t color, uint16_t r) {

	int16_t f = 1 - r;
	int16_t ddF_x = 1;
	int16_t ddF_y = -2 * r;
	int16_t x = 0;
	int16_t y = r;
		
  
	PORTB &= ~(1<<2);
	paintPixel(x0  , y0+r, color);
	PORTB |= (1<<2);
  
	PORTB &= ~(1<<2);
	paintPixel(x0  , y0-r, color);
	PORTB |= (1<<2);

	PORTB &= ~(1<<2);
	paintPixel(x0+r, y0  , color);
	PORTB |= (1<<2);

	PORTB &= ~(1<<2);
	paintPixel(x0-r, y0  , color);
	PORTB |= (1<<2);
	
	while (x<y) {
		if (f >= 0) {
			y--;
			ddF_y += 2;
			f += ddF_y;
		}

		x++;
		ddF_x += 2;
		f += ddF_x;
  
		PORTB &= ~(1<<2);
		paintPixel(x0 + x, y0 + y, color);
		PORTB |= (1<<2);

		PORTB &= ~(1<<2);
		paintPixel(x0 - x, y0 + y, color);
		PORTB |= (1<<2);

		PORTB &= ~(1<<2);
		paintPixel(x0 + x, y0 - y, color);
		PORTB |= (1<<2);

		PORTB &= ~(1<<2);
		paintPixel(x0 - x, y0 - y, color);
		PORTB |= (1<<2);

		PORTB &= ~(1<<2);
		paintPixel(x0 + y, y0 + x, color);
		PORTB |= (1<<2);

		PORTB &= ~(1<<2);
		paintPixel(x0 - y, y0 + x, color);
		PORTB |= (1<<2);

		PORTB &= ~(1<<2);
		paintPixel(x0 + y, y0 - x, color);
		PORTB |= (1<<2);

		PORTB &= ~(1<<2);
		paintPixel(x0 - y, y0 - x, color);
		PORTB |= (1<<2);
			
	}
}
