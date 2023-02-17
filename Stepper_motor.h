/*
 * Stepper_motor.h
 *
 * Created: 2/1/23 7:30
 * Author: Savan Patel
 *
 *
 * Project name: Three_Modes_Stepper
 * Description: 
 * Control stepper motor thru three different modes:
 * - Wave step mode
 * - Full step mode
 * - Half step mode 
 *
 * Three arrays with data corresponding to the bit pattern is necessary
 * to move the stepper motor. The code has a for loop in either 4 or 8
 * iterations depending on the drive mode for the stepper.
 *
 * Use system delay function _delay_ms(3) Delays 3ms in between each step
 * (Below 1ms won't work)
 *
 * 		Hardware: (output) Active High
 * 		IN1 ---- PORTA.0
 * 		IN2 ---- PORTA.1
 * 		IN3 ---- PORTA.2
 * 		IN4 ---- PORTA.3
 *
 * 		Input: how were they connected?
 * 		SW0 ---- PORTC.0		WAVE
 * 		SW1 ---- PORTC.1		FULL STEP
 * 		SW2 ---- PORTC.2		HALF STEP
 * 		SW3 ---- PORTC.3		(Later for last procedure)
 *
 * 		THe code is written as a multi module program
 *
 
 ********************************************************/


#ifndef STEPPER_MOTOR_H_
#define STEPPER_MOTOR_H_

#define F_CPU 16000000UL

//include files
#include <avr/io.h>	// avr.io file that corresponds with Mircochip Studios
#include <util/delay.h>	// delay file allow the _delay_ms() function


// Define function prototypes
void Stepper_Drive(char mode, uint8_t revolutions);

void Stepper_init(void);

void Stepper_Position(char mode, uint16_t degrees);

void Stepper_MovementCCW2sec(void);		//CCW

void Stepper_MovementCW2sec(void);	//CW

void Stepper_MovementCWHighSpeed9sec(void);	//CW

// Define

#define Wave_Step	0x01
#define Full_Step	0x02
#define Half_Step	0x04
#define Position	0x08


//global variables
extern uint8_t Wave[4];
extern uint8_t Full[4];
extern uint8_t Half[8];
extern uint8_t Waveback[4];



#endif /* STEPPER_MOTOR_H_ */