/*
 * DIO.c
 *
 * Created: 9/5/2022 10:08:01 PM
 *  Author: MOHAMED
 */ 
#include "DIO.h"




/************************************************************************/
/* INIT PINS TO MAKE OUTPUT OR INPUT            NO RETURN               */
/*            TAKE PORTNUM  AND PIN NUM AND DIRECTION                  */
/************************************************************************/
void DIO_Init(uint8_t portnum,uint8_t pinnum,uint8_t pindirection)
{
	switch(portnum)
	{
		case PORT_A:
		if(pindirection==output)
		{
			SET_BIT(DDRA,pinnum);
		}
		else if (pindirection==input)
		{
			
			CLR_BIT(DDRA,pinnum);

		}
		else{}
		break;
		case PORT_B:
		if(pindirection==output)
		{
			SET_BIT(DDRB,pinnum);

		}
		else if (pindirection==input)
		{
			CLR_BIT(DDRB,pinnum);

		}
		else{}
		break;
		case PORT_C:
		if(pindirection==output)
		{
			SET_BIT(DDRC,pinnum);
		}
		else if (pindirection==input)
		{
			CLR_BIT(DDRC,pinnum);
		}
		else{}
		break;
		case PORT_D:
		if(pindirection==output)
		{
			SET_BIT(DDRD,pinnum);

		}
		else if (pindirection==input)
		{
			CLR_BIT(DDRD,pinnum);

		}
		else{}
		break;
	}
	
}



/************************************************************************/
/* SET PINS TO MAKE HIGH OR LOW            NO RETURN                   */
/*            TAKE PORTNUM  , PIN NUM AND VALUE                       */
/************************************************************************/

void DIO_SetPin(uint8_t portnum,uint8_t pinnum,uint8_t value)
{
	switch(portnum)
	{
		case PORT_A:
		if(value==high)
		{
			SET_BIT(PORTA,pinnum);

		}
		else if (value==low)
		{
			CLR_BIT(PORTA,pinnum);

		}
		else{}
		break;
		case PORT_B:
		if(value==high)
		{
			SET_BIT(PORTB,pinnum);

		}
		else if (value==low)
		{
			CLR_BIT(PORTB,pinnum);

		}
		else{}
		break;
		case PORT_C:
		if(value==output)
		{
			SET_BIT(PORTC,pinnum);

		}
		else if (value==input)
		{
			CLR_BIT(PORTC,pinnum);

		}
		else{}
		break;
		
		case PORT_D:
		if(value==output)
		{
			SET_BIT(PORTD,pinnum);

		}
		else if (value==input)
		{
			CLR_BIT(PORTD,pinnum);

		}
		else{}
		break;
	}
	
}

/************************************************************************/
/* TOGLE PINS TO MAKE HIGH OR LOW            NO RETURN                   */
/*            TAKE PORTNUM  AND PIN NUM                               */
/************************************************************************/
void DIO_togPin(uint8_t portnum,uint8_t pinnum)
{
	switch(portnum)
	{
		case PORT_A:
		TOG_BIT(PORTA,pinnum);
		break;
		case PORT_B:
		TOG_BIT(PORTB,pinnum);
		break;
		case PORT_C:
		TOG_BIT(PORTC,pinnum);
		break;
		case PORT_D:
		TOG_BIT(PORTD,pinnum);
		break;
		
	}
	
	
	
	
	
}
/************************************************************************/
/* READ PINS                               NO RETURN                    */
/*            TAKE PORTNUM  , PIN NUM  AND    GET VALUE   IN POINTER    */
/************************************************************************/
void DIO_Getpin(uint8_t portnum,uint8_t pinnum,uint8_t *value)
{
	switch(portnum)
	{
		case PORT_A:
		*value=  GET_BIT(PINA,pinnum); //VALUE   IN POINTER 
		break;
		case PORT_B:
		*value= GET_BIT(PINB,pinnum);  //VALUE   IN POINTER 
		break;
		case PORT_C:
		*value= GET_BIT(PINC,pinnum);  //VALUE   IN POINTER 
		break;
		case PORT_D:
		*value= GET_BIT(PIND,pinnum);  //VALUE   IN POINTER 
		break;
		
	}
}