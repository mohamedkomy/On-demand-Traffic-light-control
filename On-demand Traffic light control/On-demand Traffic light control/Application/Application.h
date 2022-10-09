/*
 * Application.h
 *
 * Created: 9/5/2022 10:31:41 PM
 *  Author: Lenovo
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_


#include "../ECUAL/LED_DRIVER/LED.h"
#include "../ECUAL/BUTTON_DRIVER/BUTTON.h"
#include "../MCAL/TIMER_DRIVER/TIMER.h"
#include "../Utilities/Interruptes.h"

//CAR PIN
#define  green_car  pin0 
#define yellow_car  pin1 
#define  red_car    pin2 
// PEDESTRAIN PIN 
#define  green_pedestrian  pin0
#define yellow_pedestrian  pin1
#define  red_pedestrian    pin2
/************************************************************************/
/* INTALIZE ALL LED ,BUUTON AND INTERUPT                                     */
/************************************************************************/
void APP_init(void);




/*Change from normal mode to pedestrian mode when the pedestrian button is pressed.
			If pressed when the cars' Red LED is on, the pedestrian's Green LED and the cars' Red LEDs will be on for five seconds, this means that pedestrians can cross the street while the pedestrian's Green LED is on.
			If pressed when the cars' Green LED is on or the cars' Yellow LED is blinking, the pedestrian Red LED will be on then both Yellow LEDs start to blink for five seconds, then the cars' Red LED and pedestrian Green LEDs are on for five seconds, this means that pedestrian must wait until the Green LED is on.
			At the end of the two states, the cars' Red LED will be off and both Yellow LEDs start blinking for 5 seconds and the pedestrian's Green LED is still on.
			After the five seconds the pedestrian Green LED will be off and both the pedestrian Red LED and the cars' Green LED will be on.
			Traffic lights signals are going to the normal mode again.*/

void APP_start(void);


#endif /* APPLICATION_H_ */