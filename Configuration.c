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

#include <avr/pgmspace.h>


uint8_t exit_menu,cuentas,temp_node_name[6];
const char Title[] PROGMEM = " Introduzca el Dir. Nodo (byte) y presione enter";
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

	while(cuentas < 6)
	{
		temp_key_node = UART0_getche();
		if(temp_key_node == 0x08 && cuentas > 0)
		{
			gotoxy((0x03 + cuentas -1),0x03);
			UART0_putchar(' ');
			gotoxy((0x03 + cuentas -1),0x03);
			cuentas--;
		}
		if(temp_key_node != 0x08)
		{
			temp_node_name[cuentas]=temp_key_node;
			EEPROM_Write(dir,temp_node_name[cuentas]);
			cuentas++;
			dir++;
		}
	}
	UART0_getch();
}
void TextMenu(){
	exit_menu = 0;
	while(exit_menu ==0){
		UART0_putsf(Title);
	}
}
