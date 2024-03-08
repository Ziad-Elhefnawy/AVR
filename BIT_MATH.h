/*
 * BIT_MATH.h
 *
 * Created: 3/5/2024 12:13:10 AM
 *  Author: Ziad Ashraf
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT_NUM)	(REG|=(1<<BIT_NUM))
#define CLEAR_BIT(REG,BIT_NUM)	(REG&=(~(1<<BIT_NUM)))
#define TOGGLE_BIT(REG,BIT_NUM)	(REG^=(1<<BIT_NUM))
#define GET_BIT(REG,BIT_NUM)	((REG>>BIT_NUM)&(0X01))

#define CONC_BIT(B7,B6,B5,B4,B3,B2,B1,B0) CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0)
#define CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0) 0##b##B7##B6##B5##B4##B3##B2##B1##B0


#endif /* BIT_MATH_H_ */