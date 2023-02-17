/*
 * Project Name: Wash_MC_Sys_Dev.c
 *
 * .c filename: Control_stg_1.c
 * 
 * Description: The code below simulates a washing machine using LEDs
 * represent the phase of the washing machine and the stepper motor to
 * simulate the washing machine through the phases.
 *
 * Created: 2/8/2023 7:58:10 AM
 * Author : Savan Patel
 */ 

#define F_CPU 16000000UL
#include <avr/io.h> // avr file that goes with Microchip studio
#include <util/delay.h> // file that allows the use of the delay function
#include "Debugger.h" // debug file
#include "Stepper_motor.h"	// stepper motor file

#define Hot 0x01
#define Warm 0x02
#define Cold 0x04
#define DoorOpen 0x08
#define StartPB 0x10

void io_init (void);	// function prototype for IO

int main(void)
{
    initDebug();	// initialize the debugger
    io_init();		// initialize the IO
	Stepper_init();	// intialize stepper motor
	
    while (1) 
    {
		while((PINC&StartPB)==0)	// waiting for StartPB
		{}
		while((PINC&DoorOpen)==0)	// waiting for DoorOpen
		{}
		while((PINC&0x07)==0)		// waiting for temp selection
		{}
		switch(PINC&0x07)			// temp selection
		{
			case Hot:
				PORTL = 0x01;
				_delay_ms(4000);	// delay 4sec
				break;
			case Warm:
				PORTL = 0x03;
				_delay_ms(4000);	// delay 4sec
				break;
			case Cold:
				PORTL = 0x02;
				_delay_ms(4000);	// delay 4sec
				break;
		}
		PORTL = 0x00;				// LEDs off
		_delay_ms(500);
		PORTL = 0x04;				// Agitate LED on
		Stepper_MovementCW2sec();	// Agitate Motor CW 2sec with Agitate LED on
		Stepper_MovementCCW2sec();	// Agitate Motor CCW 2sec with Agitate LED on
		Stepper_MovementCW2sec();	// Agitate Motor CW 2sec with Agitate LED on
		Stepper_MovementCCW2sec();	// Agitate Motor CCW 2sec with Agitate LED on
		PORTL = 0x08;				// Drain LED on
		_delay_ms(4000);			// delay 4sec
		PORTL = 0x00;				// LEDs off
		switch(PINC&0x07)			// checks temp again
		{
			case Hot:
				PORTL = 0x01;
				_delay_ms(4000);	// delay 4sec
				break;
			case Warm:
				PORTL = 0x03;
				_delay_ms(4000);	// delay 4sec
				break;
			case Cold:
				PORTL = 0x02;
				_delay_ms(4000);	// delay 4sec
				break;
		}
		PORTL = 0x00;				// LEDs off
		_delay_ms(500);				
		PORTL = 0x04;				// Agitate LED on
		Stepper_MovementCW2sec();	// Agitate Motor CW 2sec with Agitate LED on
		Stepper_MovementCCW2sec();	// Agitate Motor CCW 2sec with Agitate LED on
		Stepper_MovementCW2sec();	// Agitate Motor CW 2sec with Agitate LED on
		Stepper_MovementCCW2sec();	// Agitate Motor CCW 2sec with Agitate LED on
		Stepper_MovementCW2sec();	// Agitate Motor CW 2sec with Agitate LED on
		Stepper_MovementCCW2sec();	// Agitate Motor CCW 2sec with Agitate LED on
		PORTL = 0x08;				// Drain LED on
		_delay_ms(1000);			// delay 1sec
		PORTL = 0x18;				// Drain and Spin LED on
		Stepper_MovementCWHighSpeed9sec();	// High speed spin CW for 9sec with Drain LED on
		PORTL = 0x20;				// Wash Done LED on
		while((PINC&DoorOpen)!=0)	// wait for DoorOpen to go low
		{
		}
		PORTL=0x00;					// LEDs off
    }
}

void io_init (void)
{
	DDRC=0x00;		// Initialize PORTC as an input
	PORTC=0xFF;		// Pull-up headers
	
	DDRA=0xFF;		// Initialize PORTA as an output
	PORTA=0x00;		// PORTA is off
	
	DDRL=0xFF;		// Initialize PORTL as an output
	PORTL=0x00;		// PORTL is off
}
