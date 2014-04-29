#ifndef _TIMER0_H
#define _TIMER0_H
#include <inttypes.h>

/* Funcion para inicializar el Timer0 para generar   */
/* la temporización de 1 Sec.         */
void Timer0_Ini ( void ); 
/* Funcion para verificar bandera del segundo     */
uint8_t Timer0_SecFlag ( void );
#endif  /* _TIMER0_H */
