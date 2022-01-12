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

#include <avr/io.h>
#include <avr/sfr_defs.h>
#include <avr/interrupt.h>

#define F_CPU 16000000UL
//-----Ports (IN/OUT)---------
#define PinDataAvailable PD2
#define dirDataAvailable DDRD
#define dirOutputEncoder DDRB
//----------------------------

#define setBit(sfr,bit) (_SFR_BYTE(sfr) |= _BV(bit))
#define clearBit(sfr,bit) (_SFR_BYTE(sfr) &=~ _BV(bit))

void initINT0(void);
void configKeypadEncoder(void);
ISR(INT0_vect);

int main(void)
{
	
	configKeypadEncoder();
	asm volatile ("ldi XH,0x01");
	asm volatile ("ldi XL,0x00");
	initINT0();
	sei();
    while (1) 
    {
		__asm__ volatile("nop");
    }
}

void initINT0(void)
{
	clearBit(dirDataAvailable,PinDataAvailable);
	EICRA = _BV(ISC01)|_BV(ISC00); //Rising Edge
	setBit(EIMSK,INT0); //Enable INT0	
}

void configKeypadEncoder(void)
{
	DDRB = 0x00;
	clearBit(dirDataAvailable,PinDataAvailable);
}
ISR(INT0_vect)
{
	uint8_t dato = PINB & 0x0F ;
	if (dato == 0x0D)
	{
		asm volatile ("ldi R16,'0'");
		asm volatile ("st X+,R16");
	}
	if (dato == 0x00)
	{
		asm volatile ("ldi R16,'1'");
		asm volatile ("st X+,R16");
	}
	if (dato == 0x01)
	{
		asm volatile ("ldi R16,'2'");
		asm volatile ("st X+,R16");
	}
	if (dato == 0x02)
	{
		asm volatile ("ldi R16,'3'");
		asm volatile ("st X+,R16");
	}
	if (dato == 0x03)
	{
		asm volatile ("ldi R16,'A'");
		asm volatile ("st X+,R16");
	}
	if (dato == 0x04)
	{
		asm volatile ("ldi R16,'4'");
		asm volatile ("st X+,R16");
	}
	if (dato == 0x05)
	{
		asm volatile ("ldi R16,'5'");
		asm volatile ("st X+,R16");
	}
	if (dato == 0x06)
	{
		asm volatile ("ldi R16,'6'");
		asm volatile ("st X+,R16");
	}
	if (dato == 0x07)
	{
		asm volatile ("ldi R16,'B'");
		asm volatile ("st X+,R16");
	}
	if (dato == 0x08)
	{
		asm volatile ("ldi R16,'7'");
		asm volatile ("st X+,R16");
	}
	if (dato == 0x09)
	{
		asm volatile ("ldi R16,'8'");
		asm volatile ("st X+,R16");
	}
	if (dato == 0x0A)
	{
		asm volatile ("ldi R16,'9'");
		asm volatile ("st X+,R16");
	}
	if (dato == 0x0B)
	{
		asm volatile ("ldi R16,'C'");
		asm volatile ("st X+,R16");
	}
	if (dato == 0x0C)
	{
		asm volatile ("ldi R16,'*'");
		asm volatile ("st X+,R16");
	}
	if (dato == 0x0E)
	{
		asm volatile ("ldi R16,'#'");
		asm volatile ("st X+,R16");
	}
	if (dato == 0x0F)
	{
		asm volatile ("ldi R16,'D'");
		asm volatile ("st X+,R16");
	}
}
