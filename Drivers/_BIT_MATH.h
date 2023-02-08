/*
 * _BIT_MATH.h
 *
 *  Created on: Apr 19, 2022
 *      Author: Barhoom
 */ 


#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

#define SET_BIT(REG_VAL,BITNO) (REG_VAL) |=  (1 << (BITNO))
#define CLR_BIT(REG_VAL,BITNO) (REG_VAL) &= ~(1 << (BITNO))
#define TOG_BIT(REG_VAL,BITNO) (REG_VAL) ^=  (1 << (BITNO))
#define GET_BIT(REG_VAL,BITNO) (((REG_VAL) >> (BITNO)) & 0x01)

#endif /* _BIT_MATH_H_ */