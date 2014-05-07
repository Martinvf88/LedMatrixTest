#include <avr/io.h>
#include <inttypes.h>
#include <avr/pgmspace.h>
#include "Configuration.h"
#include "Clock.h"
#include "Timer2.h"
#include "EEPROM.h"

uint8_t exit_menu;

extern char UART0_getch (void);
extern char UART0_getche (void);
extern char UART0_kbhit (void);
extern char UART0_putchar(char cara);
extern void putByteHex(char dato);
extern void UART0_puts (uint16_t str);


const char MenuOp[] PROGMEM = " a) Marquesina\n\r b) Ajuste de Reloj\n\r c) Salir";
const char SubMenuOp1[] PROGMEM = " Introduzca el texto (cadena de 8 bytes) y presione enter";	
const char SubMenuOp2[] PROGMEM = " Presione la tecla enter para configurar el reloj o escape para regresar al menu principal";
const char SubMenuOp2a[] PROGMEM = " Configure en base al formato de 24 hrs, en caso de un valor invalido este sera 0";

void menu()
{	
	exit_menu = 0;
	uint8_t menu,regreso,opcion=0,continue_menu=0;
	

		while(exit_menu ==0)
		{
			regreso =0;
			clrscr();
			gotoxy(0x01,0x01);
			UART0_putsf(MenuOp);
			menu = UART0_getch();
			switch (menu)
			{
				case 'a': /*Mensaje de marquesina */
				{
					clrscr();
					UART0_putsf(SubMenuOp1);
					gotoxy(6,10);
					TextSave(TEXT_ADDRESS);

				    exit_menu =0;
					break;
				}
				
				case 'b': /*Ajuste de Reloj*/
				{ 
					clrscr();
					gotoxy(0x01,0x01);
					UART0_putsf(SubMenuOp2);
					opcion = 0;
					while(opcion == 0)
					{
						if( Timer2_Flag ())
					  	{
					  		gotoxy(0x06,0x06);
							Clock_Update();
					  		Clock_Display();
					  	}
					  	
					  	if(UART0_kbhit() == 0x0D)
						{
							clrscr();
							gotoxy(0x01,0x01);
							UART0_putsf(SubMenuOp2a);
							gotoxy(0x06,0x06);
							config_clock();
							clrscr();
							gotoxy(0x01,0x01);
							UART0_putsf(SubMenuOp2);
							opcion = 0;
						}

						if(UART0_kbhit() == 0x1B)
						{
							opcion = 1;
						}
					} /*   ajuste(hr:min) (mostrar reloj actual) */
				  
					exit_menu =0;
					break;
				}

				case 'c':
				{	
					exit_menu =1;
					clrscr();
					break;/*Salir */
				}

				default:
				{
					exit_menu =0;
					break;
				}
			}

	}
	if(continue_menu == 1)
	{
		clrscr();
	}
}
