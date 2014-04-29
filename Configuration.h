#ifndef _Configuracion_H
#define _Configuracion_H

#include <inttypes.h>
#define TEXT_ADDRESS 0x0F15

void add_sig(void);
int check_sig(void);
void add_password(void);
int check_password(void);
void password_in(void);
void UART0_putsf(const char *data);
void clrscr(void);
uint8_t node_dir_in(void);
void gotoxy(uint8_t x, uint8_t y);
void default_settings(void);
void config_clock(void);
void TextSave(uint16_t dir);
void TextMenu();
#endif  
