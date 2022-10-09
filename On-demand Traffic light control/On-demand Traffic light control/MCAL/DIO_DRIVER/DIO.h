/*
 * DIO.h
 *
 * Created: 9/5/2022 10:08:18 PM
 *  Author: MOHAMED
 */ 


#ifndef DIO_H_
#define DIO_H_


#include "../../Utilities/STD_TYPES.h"
#include "../../Utilities/Register.h"
#include "../../Utilities/BIT_MATH.h"


/*PORT IN*/
#define PORT_A      'A'
#define PORT_B      'B'
#define PORT_C      'C'
#define PORT_D      'D'
/*PINS IN*/
#define pin0         0
#define pin1         1
#define pin2         2
#define pin3         3
#define pin4         4
#define pin5         5
#define pin6         6
#define pin7         7




/************************************************************************/
/* PIN AND PORT STATUE                                                  */
/************************************************************************/
#define output       1
#define input        0

#define high         1
#define low          0

/************************************************************************/
/* INIT PINS TO MAKE OUTPUT OR INPUT            NO RETURN               */
/*            TAKE PORTNUM  AND PIN NUM AND DIRECTION                  */
/************************************************************************/

void DIO_Init(uint8_t portnum,uint8_t pinnum,uint8_t pindirection);

/************************************************************************/
/* SET PINS TO MAKE HIGH OR LOW            NO RETURN                   */
/*            TAKE PORTNUM  , PIN NUM AND VALUE                       */
/************************************************************************/

void DIO_SetPin(uint8_t portnum,uint8_t pinnum,uint8_t value);


/************************************************************************/
/* TOGLE PINS TO MAKE HIGH OR LOW            NO RETURN                   */
/*            TAKE PORTNUM  AND PIN NUM                               */
/************************************************************************/

void DIO_togPin(uint8_t portnum,uint8_t pinnum);
/************************************************************************/
/* READ PINS                               NO RETURN                    */
/*            TAKE PORTNUM  , PIN NUM  AND    GET VALUE   IN POINTER    */
/************************************************************************/
void DIO_Getpin(uint8_t portnum,uint8_t pinnum,uint8_t *value);







#endif /* DIO_H_ */