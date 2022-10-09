/*
 * BUTTON.h
 *
 * Created: 9/5/2022 10:27:05 PM
 *  Author: MOHAMED
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO_DRIVER/DIO.h"


/************************************************************************/
/*  BUTTON INITALIZE TO INPUT BY DIO_DRIVER                             */
/*            TAKE PORTNUM  , PIN NUM  AND                              */
/************************************************************************/
void Button_Init(uint8_t portnum,uint8_t pinnum);
/************************************************************************/
/*    BUTTON GET PRESSD         BY DIO_DRIVER                           */
/*            TAKE PORTNUM  , PIN NUM  AND    GET VALUE   IN POINTER    */
/************************************************************************/
void Get_Button(uint8_t portnum,uint8_t pinnum,uint8_t *value);





#endif /* BUTTON_H_ */