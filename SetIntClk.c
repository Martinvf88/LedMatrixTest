#include <avr/io.h>
#include <inttypes.h>

void SetIntClk_2MHz(){

    CLKPR = 0x80; /* Preparar cambio en CLKPR */
    CLKPR = 0x02; /* escribir divisor para obtener 2MHz */
    asm("nop\n"
    "nop\n"
    "nop\n"
    "nop\n"
    "nop\n"); /* Otra vez */
    CLKPR = 0x80; /* Preparar cambio en CLKPR */
    CLKPR = 0x02; /* escribir divisor para obtener 2MHz */
    asm("nop\n"
    "nop\n");

}
