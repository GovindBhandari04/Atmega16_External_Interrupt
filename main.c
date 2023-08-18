/*
 * External Interrupt.c
 *
 * Created: 8/18/2023 6:14:44 PM
 * Author : Govind
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void)
{
	sei(); //Enable the global interrupt bit
	GICR  |= (1<<INT0) | (1<<INT1);  //Enable the INT0 and INT1 bit in GICR register    
	MCUCR |= (1<<ISC00)|(1<<ISC01)|(1<<ISC10)|(1<<ISC11); //Enable the interrupt sense control register in MCUCR register
	DDRD  |= (1<<DDD0); //set led as output
	
    while (1) 
    {
    }
}

ISR(INT0_vect)
{
	PORTD |= (1<<PD0);
}

ISR(INT1_vect)
{
	PORTD &= ~(1<<PD0);
}
