
#include "LED.h"

/************************************************************************/
/*  LED INIALISE TO OUTPUT BY DIO_DRIVER                                */
/************************************************************************/
void Led_Init(uint8_t Portnum,uint8_t pinunm)
{
	DIO_Init(Portnum,pinunm,output);
	
}
/************************************************************************/
/*  LED SET TO HIGH BY DIO_DRIVER                                */
/************************************************************************/
void LED_ON(uint8_t Portnum,uint8_t pinunm)
{
	DIO_SetPin(Portnum,pinunm,high);
}




/************************************************************************/
/*  LED SET TO LOW BY DIO_DRIVER                                */
/************************************************************************/
void LED_OFF(uint8_t Portnum,uint8_t pinunm)
{
		DIO_SetPin(Portnum,pinunm,low);
}
/************************************************************************/
/*  LED TOGGLE BY DIO_DRIVER                                */
/************************************************************************/
void LED_TOGLE(uint8_t Portnum,uint8_t pinunm)
{
	DIO_togPin(Portnum,pinunm);
}


