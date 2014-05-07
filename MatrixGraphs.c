#include <avr/io.h>
#include <inttypes.h>
#include "MatrixColor.h"
#include "MatrixGraphs.h"
#include "Alphabet.h"
#include "EEPROM.h"
#include <string.h>
#include <stdlib.h>

uint8_t *ptr;

uint8_t matrixBuffer[32][32] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};


static volatile uint8_t i,m =0;
static volatile uint8_t j,n =0;

static volatile uint8_t lastX,lastXH =0;
static volatile uint8_t lastY, lastYH =0;

void CleanMatrix(){

	//memset(matrixBuffer,0,sizeof(matrixBuffer));
	for(m=0;m<32;m++){
		for(n=0;n<32;n++){
		matrixBuffer[n][m]=0;
		}
	}
}
void CleanMessage(){
	for(m=0;m<32;m++){
		for(n=25;n<32;n++){
		matrixBuffer[n][m]=0;
		}
	}
}

void paintPixel(uint8_t x, uint8_t y, uint8_t color){

	ptr = &matrixBuffer[0][0];
	ptr[x+(32 * y)] =color;
}

void drawLetter(uint8_t x0, uint8_t y0, uint16_t letter,uint8_t color){

	uint16_t lettercase;
	if (letter == 0){
		lettercase =320;
		}
	if(letter >=65 && letter <=90){
		lettercase = (letter-65)*(5);
	}
	if(letter >=97 && letter <=122){
		lettercase = (letter-70)*(5) -5;
	}
	if(letter >=30 && letter <=39){
		lettercase = 212+(letter*5);
	}
	if(letter >=47 && letter <=57){
		lettercase = 260+((letter-47)*5);
	}

	uint8_t i,j=0;
	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			PORTB &= ~(1<<2);
			paintPixel(x0-j,y0+i,(pgm_read_byte(&letters[lettercase+i][j]))+color);
			PORTB |= (1<<2);
		}
	}
}


void swap(int *a, int *b){
	int c;
	c=*b;
	*b=*a;
	*a=c;
}

void Line(int x0,int y0, int x1, int y1, uint8_t color){

	int paso, deltax, deltay, error, ystep, y, x;
	if(abs(y1-y0)>abs(x1-x0))
		paso=1;
		else
		paso=0;
	if (paso == 1) {
		swap(&x0,&y0);
		swap(&x1,&y1);
	}
	if (x0>x1) {
		swap(&x0,&x1);
		swap(&y0,&y1);
	}
	deltax = x1 - x0;
	deltay = abs(y1-y0);
	error = deltax/2;
	y=y0;
	if (y0<y1)
		ystep=1;
		else
		ystep=-1;
	for (x=x0; x<=x1; x++){
		if (paso==1)
			paintPixel(y,x,color);
			else
			paintPixel(x,y,color);
		error = error - deltay;
		if (error < 0) {
			y=y+ystep;
			error=error+deltax;
		}
	}
}
void Display(){
	
	PORTC = i;
	PORTB |= (1<<2);
	PORTB |= (1<<1); //OE on	
		for(j=0;j<32;j++){
			setColorPixel(matrixBuffer[i][31-j]);
			if (i <= 15){
				
				PORTD &= ~(1<<5); //R1
				PORTD &= ~(1<<6); //G1
				PORTD &= ~(1<<7); //B1
			}

			else{
	
				PORTD &= ~(1<<2); //R0
				PORTD &= ~(1<<3); //G0
				PORTD &= ~(1<<4); //B0
		
			}	

		
			PORTB |= (1<<3); //SCLK on
			PORTB &= ~(1<<3); //SCLK on		
		
		}
	i++;
	if(i==32){
		i=0;
	}	
	PORTB &= ~(1<<2);
	PORTB &= ~(1<<1); //OE on	
	
}

void MinuteHand(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1,uint8_t color){

	if(lastXH!=0 && lastYH !=0){	
		Line(x0,y0,lastXH,lastYH,0);
	}	

	Line(x0,y0,x1,y1,color);
	
	lastXH = x1;
	lastYH = y1;
}


void HourHand(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1,uint8_t color){

	if(lastX!=0 && lastY !=0){	
		Line(x0,y0,lastX,lastY,0);
	}	

	Line(x0,y0,x1,y1,color);
	
	lastX = x1;
	lastY = y1;
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
		PORTB &= ~(1<<2);
			
	}
}

