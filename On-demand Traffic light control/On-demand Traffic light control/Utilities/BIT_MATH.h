/*
 * BIT_MATH.h
 *
 * Created: 9/5/2022 10:11:57 PM
 *  Author: 
 */ 



#ifndef _BIT_MATH_H
#define _BIT_MATH_H

#define SET_BIT(VAR,BITNO) (VAR) |=  (1 << (BITNO))
#define CLR_BIT(VAR,BITNO) (VAR) &= ~(1 << (BITNO))
#define TOG_BIT(VAR,BITNO) (VAR) ^=  (1 << (BITNO))
#define GET_BIT(VAR,BITNO) (((VAR)&(1 << BITNO)) >> BITNO)



#endif