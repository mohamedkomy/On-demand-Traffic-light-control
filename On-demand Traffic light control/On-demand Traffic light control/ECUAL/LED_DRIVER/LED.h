/*
 * LED.h
 *
 * Created: 9/2/2022 11:40:41 PM
 *  Author: Lenovo
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO_DRIVER/DIO.h"

/************************************************************************/
/*  LED INIALISE TO OUTPUT BY DIO_DRIVER                                */
/************************************************************************/
void Led_Init(uint8_t Portnum,uint8_t pinunm);





/************************************************************************/
/*  LED SET ON TO HIGH BY DIO_DRIVER                                */
/************************************************************************/
void LED_ON(uint8_t Portnum,uint8_t pinunm);


/************************************************************************/
/*  LED SET OFF TO LOW BY DIO_DRIVER                                */
/************************************************************************/
void LED_OFF(uint8_t Portnum,uint8_t pinunm);


/************************************************************************/
/*  LED TOGLE BY DIO_DRIVER                                */
/************************************************************************/

void LED_TOGLE(uint8_t Portnum,uint8_t pinunm);



#endif 