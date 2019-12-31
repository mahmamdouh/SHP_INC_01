/*
 * Bit_Math.h
 *
 *  Created on: Apr 24, 2019
 *      Author: salsa
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define CONCAT_HELPER(a,b,c,d,e,f,g,h) (0b##a##b##c##d##e##f##g##h)
#define CONCAT(a,b,c,d,e,f,g,h) (CONCAT_HELPER(a,b,c,d,e,f,g,h))
#define SET_BIT(REGISTER,PIN) (REGISTER) =(REGISTER | 1<<PIN)
#define CLEAR_BIT(REGISTER,PIN) (REGISTER) =((REGISTER) & ~((1) << (PIN)))
#define TOGGLE_BIT(REGISTER,PIN) (REGISTER) =(REGISTER^(1<<PIN))
#define CHECK_BIT(REGISTER,PIN) ((REGISTER>>PIN)&1)
#define set_bit(reg,position) (reg|=(1<<position))
#define red_bit(reg,position) ((reg>>position)&1)
#define clear_bit(reg,position) (reg&=~(1<<position))
#define toggle_bit(reg,position) (reg^(1<<position))
#endif /* BIT_MATH_H_ */
