#define _SFR_ASM_COMPAT 1
#define __SFR_OFFSET 0
#include <avr/io.h>
.global UART0_Init
.global UART0_getch
.global UART0_kbhit
.global UART0_putchar
.global UART0_puts
.global UART0_getche
.global putByteHex
.global putWordHex
.global boton

;*************************************************************************
; UART0_Init
; Descripcion: Inicializa UART0 a 38400,8,N,1 si r24=0, y a 19200,8,N,1 
;  para cualquier otro valor.
; Nota: Considere que LiSANDRA opera a 8MHz
;*************************************************************************


UART0_Init:

push r16
push r17
push r18
push r19
push r20
push r21 ; guardamos los registros en la pila

ldi r21,0 ; nos ayudamos de R21 para comparar R24 con 0

ldi r20, 0x06 ;bits que pasaran al registro de control UCSR0C
ldi r19, 0x18 ;bits que pasaran al registro de control UCSR0B
ldi r18, 0x20 ;bits que pasaran al registro de control UCSR0A (19200) el bit de U2X0 es 0

sts UCSR0B, r19
sts UCSR0C, r20

mov R16,R24
ldi R17,0
sts UBRR0H,R17
sts UBRR0L,R16
sts UCSR0A, r18

pop r21
pop r20
pop r19
pop r18
pop r17
pop r16 ;sacamos de la pila los valores originales


ret

;*************************************************************************
; UART0_putchar
; Descripcion: Función para  transmite por el puerto serie  0 un byte 
; dado por un parámetro. 
;*************************************************************************

UART0_putchar:

	push r21
	push r22
	push r24

UART0_putchar_r:

	lds r21,UCSR0A ;pasamos el registro UCSR0A
	sbrs r21,UDRE0 ; salta si el bit 5 (UDRE0) esta en 1, es decir no hay nada de datos en UDR0
	rjmp UART0_putchar_r

	sts UDR0,r24 ; sacamos el dato
	ldi r22,1
	bst r22,0
	bld r21,UDRE0
	sts UCSR0A,r21

	pop r24
	pop r22
	pop r21

ret

;*************************************************************************
; UART0_getch
; Descripcion: Función que retorna un byte recibido por el puerto serie 0. 
;*************************************************************************

UART0_getch:
	;push r24
	push r21
UART0_getch_l:
	lds r21,UCSR0A
	sbrs r21, RXC0
	rjmp UART0_getch_l
; Get and return received data from buffer
	lds r24, UDR0
//	rcall UART0_putchar
	pop r21
;pop r24
ret

;*************************************************************************************
; UART0_getche
; Descripcion: Función que retorna un byte recibido por el puerto serie 0 y lo muestra. 
;**************************************************************************************

UART0_getche:
	;push r24
	push r21
UART0_getche_l:
	lds r21,UCSR0A
	sbrs r21, RXC0
	rjmp UART0_getche_l
; Get and return received data from buffer
	lds r24, UDR0
	rcall UART0_putchar
	pop r21
;pop r24
ret

;*************************************************************************
; UART0_kbhit
; Descripcion: Función que retorna un byte recibido por el puerto serie 0. 
;*************************************************************************

UART0_kbhit:

	lds r24, UDR0

ret


;*************************************************************************
; UART0_puts
; Descripcion:   Función que transmite una cadena por el puerto serie 0 y
; se basa en la funcion UART0_putchar
;*************************************************************************


UART0_puts:

push r20
push r24

ldi r20,0

try2:
	ld  r24,Y+ ;cargamos a r24 el dato al que apunta la direccion ram guardada en Y
	sts UDR0,r24 ;sacamos el dato
	cpse r24,r20  ; comparamos con 0 (el cual establecimos como fin de cadena)
	rjmp try2

	pop r24
	pop r20

ret

;*************************************************************************
; putByteHex
; Descripcion:   Función que imprime el valor hexadecimal de el byte que recibe
; Nota: Modifica R24
;*************************************************************************

putByteHex:
	
	push r24
	push r25
	push r18
	push r17
	push r16     ;Se guardan en la pila los valores registros a usar.

	ldi r16,0x30 ;Este 0x30 se usará en caso de ser un numero
	ldi r17,0x37 ;Este 0x37 se usará en caso de ser un letra
	mov r25,r24  ;Hacemos una copia de R24 en R25

	cbr r24,0x0F  ;Limpiamos el nibble de los bits menos significativos (bajo)
	swap r24      ;Pasamos el nibble alto a la parte baja
	mov r18,r24   ;Copiamos el valor a R18
	subi r18,0xFA ;Restamos de r18 250 (o lo que es equivalente sumar 6), esto para comparar
	sbrs r18,4    ;el bit menos significativo del nibble alto (bit 4) si es 0 es numero, si es 1 letra
	add r24,r16   ;se suma 0x30 (numero)
	sbrc r18,4    ;Salto de linea si es 0 (para que no sume de nuevo)
	add r24,r17   ;Se suma 0x37 (letra) 
	rcall UART0_putchar ;Imprime caracter
	
	cbr r25,0xF0  ;Limpiamos el nibble de los bits mas significativos (alto)
	mov r24,r25   ;Copiamos el valor a r24
	mov r18,r24   ;Copiamos el valor a r18
	subi r18,0xFA ;Restamos de r18 250 (o lo que es equivalente sumar 6), esto para comparar
	sbrs r18,4    ;el bit menos significativo del nibble alto (bit 4) si es 0 es numero, si es 1 letra
	add r24,r16   ;se suma 0x30 (numero)
	sbrc r18,4    ;Salto de linea si es 0 (para que no sume de nuevo)
	add r24,r17   ;Se suma 0x37 (letra) 
	rcall UART0_putchar ;Imprime caracter

	pop r16
	pop r17
	pop r18
	pop r25
	pop r24 ;Se sacan de la pila los valores originales de los registros usados

	ret

;*************************************************************************
; putWordHex
; Descripcion:   Función que imprime el valor hexadecimal de la palabra que recibe
; Nota: Modifica R24 y R25
;*************************************************************************

putWordHex:
	push r24
	push r25
	push r20 ;Se guardan en la pila los valores de los registros a usar

	mov r20,r24 ;Copiamos el valor de r24(parte baja de la palabra) a r20
	mov r24,r25 ;Copiamos el valor de r25(parte alta de la palabra) a r24
	rcall putByteHex ;Llamamos la rutina de putByteHex
	mov r24,r20      ;Copiamos el valor de r20(parte baja de la palabra) a r24
	rcall putByteHex ;Llamamos la rutina de putByteHex	

	pop r20
	pop r25
	pop r24;Se sacan de la pila los valores originales de los registros usados
ret

;*************************************************************************

boton:
	

	sbis PINC,2
	ldi r24,0x01
	ldi r24,0x00
ret


num_let:

	push r16
	push r17

	ldi r16,0x30
	ldi r17,0x37

	cpi r24,0x0A
	brlo numeros
	add r24,r17
	rjmp fin

numeros:

	add r24,r16
fin:
	pop r17
	pop r16
ret

