/*
 * BUTTON.c
 *
 * Created: 9/5/2022 10:27:23 PM
 *  Author: Lenovo
 */ 
#include "Button.h"
void Button_Init(uint8_t portnum,uint8_t pinnum)
{
	DIO_Init(portnum,pinnum,input);
	
}
void Get_Button(uint8_t portnum,uint8_t pinnum,uint8_t *value)
{
	DIO_Getpin(portnum,pinnum,value);
}
