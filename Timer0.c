#include <avr/interrupt.h>
#include <inttypes.h>

static volatile uint8_t  mSecCnt, mSec100Cnt;
static volatile uint8_t SecFlag; 

void Timer0_Ini ( void ){ 
	TCNT0 = 0x06;
	TCCR0A=0x00;  /* inicializa timer0 en modo CTC  */ 
	/* Inicializar Timer: fuente de oscilación interna  */
	TCCR0B=0x02;  /* con Prescalador 8          */ 
	TIMSK0=0x03;  /* habilita interrupcion del Timer0   */ 
	//OCR0A=0xF9;
	sei();    /* habilita interrupciones (global)   */
} 
	uint8_t Timer0_SecFlag ( void ){
	uint8_t tmp=SecFlag;
	if( tmp ) SecFlag=0; 
	return tmp;
	}

	ISR (TIMER0_OVF_vect ){//TIMER0_COMPA_vect){    /* TIMER0_OVF_vect         */
	TCNT0 += 0x06;
	mSecCnt++;      /* Incrementa contador de milisegundos  */
	if(mSecCnt==100){ 
	mSecCnt=0; 
	mSec100Cnt++;    /* Contador para 100 miliSegundos    */ 
	if(mSec100Cnt==10){ 
	mSec100Cnt=0; 
	SecFlag=1;    /* Bandera de Segundos        */
	} 
	} 
} 

