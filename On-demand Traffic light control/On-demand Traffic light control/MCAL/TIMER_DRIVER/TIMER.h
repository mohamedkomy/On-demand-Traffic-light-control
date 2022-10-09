/*
 * TIMER4.h
 *
 * Created: 9/5/2022 10:17:43 PM
 *  Author: Lenovo
 */ 


#ifndef TIMER4_H_
#define TIMER4_H_


#include "../../Utilities/STD_TYPES.h"
#include "../../Utilities/Interruptes.h"
#include "../../Utilities/BIT_MATH.h"
#include "../DIO_DRIVER/DIO.h"
#include "../../Utilities/Register.h"
#include <math.h>




//initialize Timer0
void TIMER_init(void);          
//delay of specific amount default uses 256 prescalar
void TIMER_delay(uint16_t millisec); 




#endif /* TIMER4_H_ */