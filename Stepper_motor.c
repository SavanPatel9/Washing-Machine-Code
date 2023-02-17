/*
 * Stepper_motor.c
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

 #include "Stepper_motor.h" // stepper motor file with functions

 uint8_t Wave[4] = {0x01, 0x02, 0x04, 0x08};
 uint8_t Full[4] = {0x03, 0x06, 0x0C, 0x09};
 uint8_t Half[8] = {0x09, 0x01, 0x03, 0x02, 0x06, 0x04, 0x0C, 0x08};
 uint8_t Waveback[4] = {8, 4, 2, 1};
	 
 void Stepper_Drive(char mode, uint8_t revolutions)
 {
	 
	 uint16_t steps;
	 
	 switch (mode)
	 {
		 case 'W':
		 
		 steps = (revolutions * 2048) / 4; 
		 
		 for(uint16_t i = 0; i< steps; i++)
		 {
			 for(uint16_t j = 0; j< 4; j++)
			 {
				 PORTA = Wave[j];
				 _delay_ms(3);
			 }
		 }
		 break;
		 
		 case 'F':
		 
		 steps = (revolutions * 2048) / 4;
		 
		 for(uint16_t i = 0; i< steps; i++)
		 {
			 for(uint16_t j = 0; j< 4; j++)
			 {
				 PORTA = Full[j];
				 _delay_ms(3);
			 }
		 }
		 break;
		 
		 case 'H':
		 
		 steps = (revolutions * 4096) / 8;
		 
		 for(uint16_t i = 0; i< steps; i++)
		 {
			 for(uint16_t j = 0; j< 8; j++)
			 {
				 PORTA = Half[j];
				 _delay_ms(3);
			 }
		 }
		 break;
	 }
	 
 }
 
 void Stepper_MovementCCW2sec(void)
 {
		for(uint16_t i = 0; i<83; i++)
		{
			for(uint16_t j = 0; j< 4; j++)
			{
				PORTA = Wave[j];
				_delay_ms(6);
			}	
		}
 }
 
 void Stepper_MovementCW2sec(void)
 {
	 for(uint16_t i = 0; i<83; i++)
	 {
		 for(uint16_t j = 0; j< 4; j++)
		 {
			 PORTA = Waveback[j];
			 _delay_ms(6);
		 }
	 }
 }

 
 void Stepper_MovementCWHighSpeed9sec(void)
 {
	 for(uint16_t i = 0; i<750; i++)
	 {
		 for(uint16_t j = 0; j< 4; j++)
		 {
			 PORTA = Waveback[j];
			 _delay_ms(3);
		 }
	 }
 }
 
 void Stepper_init(void)
 {
	 DDRA=0xFF; // Sets up PORTA as output
	 PORTA=0x00; // PORTA is off
 }