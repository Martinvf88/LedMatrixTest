#include <avr/pgmspace.h>
#include <inttypes.h>
#include "EEPROM.h"
#include "Clock.h"
#include "Configuration.h"


extern char UART0_kbhit (void);
extern char UART0_getch (void);
extern char UART0_getche (void);
extern void UART0_putchar(char dato);
extern void UART0_puts(const char *str);
extern void putByteHex(char dato);
extern void putWordHex (char *str);

uint8_t exit_menu,cuentas,space,temp_node_name[6];


void PortConfig(){

	DDRB = 0x0E;      /* configura de salida los bits 1 al 3 el PORTB  DDRB= 00001110      */ 
	PORTB = 0x0A;     /* presentar valor inicial en puerto  PORTB= 00000010      */

	DDRC = 0x0F;      /* configura de salida los bits 0 al 3 el PORTC DDRC= 00001111      */ 
	PORTC = 0x00;     /* presentar valor inicial en puerto PORTC= 00000000      */
	
	DDRD = 0xFC;      /* configura de salida los bits 2 al 7 el PORTD DDRD= 11111100      */
	PORTD = 0x00;     /* presentar valor inicial en puerto PORTD= 00000000 */

}

void clrscr() //Basado en la info obtenida en ATMEL
{
	UART0_putchar(0x1B); // ESCAPE
	UART0_putchar(0x5B); // [
	UART0_putchar(0x32); // 2
	UART0_putchar(0x4A); // J

}

void gotoxy(uint8_t x, uint8_t y)//Basado en la info obtenida en ATMEL
{
	uint8_t coord, aux1,aux2;
	coord = y;
	aux1 = coord/10;
	aux2 = coord %10;
	
	// ESC[n;mf  donde n=renglon m=columna
	UART0_putchar(0x1B);
	UART0_putchar('[');
	UART0_putchar(aux1+0x30);  // renglon
	UART0_putchar(aux2+0x30);  // renglon
	UART0_putchar(';');
	coord = x;
	aux1 = coord/10;
	aux2 = coord %10;
	UART0_putchar(aux1+0x30);  // columna
	UART0_putchar(aux2+0x30);  // columna
	UART0_putchar('f');
}

void UART0_putsf(const char *data) // Modificado-Adaptado apartir de la info. que esta en la pág de arduino
{
   while (pgm_read_byte(data) != 0x00)
     UART0_putchar(pgm_read_byte(data++));
} 

void TextSave(uint16_t dir)
{
	 uint8_t temp_key_node;
	 cuentas = 0;

	while(cuentas < 8)
	{
		temp_key_node = UART0_getche();
		if(temp_key_node == 0x08 && cuentas > 0)
		{
			gotoxy((0x03 + cuentas -1),0x03);
			UART0_putchar(' ');
			gotoxy((0x03 + cuentas -1),0x03);
			cuentas--;
		}
		if(temp_key_node != 0x08 && temp_key_node != 0x20)
		{
			temp_node_name[cuentas]=temp_key_node;
			EEPROM_Write(dir,temp_node_name[cuentas]);
			cuentas++;
			dir++;
		}
		
		if(temp_key_node == 0x20){
			temp_node_name[cuentas]=0;
			EEPROM_Write(dir,temp_node_name[cuentas]);
			cuentas++;
			dir++;	
		}
		
		if(temp_key_node == 0x0D){
			space = 8-cuentas;
			for (; space<8;space++){
				temp_node_name[space]=0;
				EEPROM_Write(dir,temp_node_name[space]);
			}
			cuentas = 8;
		}
	}
	UART0_getch();
}


void config_clock()
{
	char tecla1_hr, tecla1_min, tecla2_hr, tecla2_min,hora,min;

	tecla1_hr =UART0_getche();
	if(tecla1_hr > 0x31)
	{
		tecla1_hr = 0x30; //automatico el 0
	}
	tecla2_hr = UART0_getche();
	
	if(tecla1_hr >= 0x31 && tecla2_hr > 0x31 )
	{
		tecla2_hr = 0x30; //automatico el 0//error
		tecla1_hr = 0x30; //automatico el 0
	}
	UART0_putchar(':');
 	tecla1_min = UART0_getche();
	
	if(tecla1_min > 0x35)
	{
		tecla1_min = 0x30; //automatico el 0
	}
	
	tecla2_min =UART0_getche();
	
	hora = 10*(tecla1_hr -0x30) + (tecla2_hr - 0x30);
	min = 10*(tecla1_min -0x30) + (tecla2_min - 0x30);

	Clock_Ini(hora,min,0);
	Clock_Update();

	
}
