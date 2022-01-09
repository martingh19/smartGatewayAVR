/*
 * SmartGateway.c
 *
 * Created: 9/1/2022 10:54:56
 * Author : Martín Gutiérrez
 * Description:
 * The following program will try to automate the functions of 
 * a door (opening and closing) 
 *
 *  tag | description
 * (v.0) matrix keypad MM74C922N
 * (v.1) electric lock  
 */ 
#define F_CPU 16000000UL
//-----Ports (IN/OUT)---------
#define PinDataAvailable PD2
//----------------------------

#define setBit(sfr,bit) (_SFR_BYTE(sfr) |= _BV(bit))
#define clearBit(sfr,bit) (_SFR_BYTE(sfr) &=~ _BV(bit))

#include <avr/io.h>
#include <avr/sfr_defs.h>
#include <avr/interrupt.h>

void initINT0(void);

int main(void)
{
	initINT0();
	sei();
    while (1) 
    {
		__asm__ ("nop");
    }
}

void initINT0(void)
{
	EICRA = _BV(ISC01)|_BV(ISC00); //Rising Edge
	setBit(EIMSK,INT0); //Enable INT0	
}

ISR(INT0_vect)
{

}
