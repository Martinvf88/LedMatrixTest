#ifndef _Configuracion_H
#define _Configuracion_H

#include <inttypes.h>
#define TEXT_ADDRESS 0x0F15

void config_clock(void);
void UART0_putsf(const char *data);
void clrscr(void);
void gotoxy(uint8_t x, uint8_t y);
void default_settings(void);
void TextSave(uint16_t dir);
void TextMenu();
void PortConfig(void);
#endif  
