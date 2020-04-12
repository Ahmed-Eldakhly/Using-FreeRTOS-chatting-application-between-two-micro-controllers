/*****************************************************************************
 * Module 	  : Data Types definition
 *
 * File name  : std_types.h
 *
 * Created on : Apr 9, 2019
 *
 * Author     : Ahmed Eldakhly & Hesham Hafez
 ******************************************************************************/

#ifndef MACRO_H_
#define MACRO_H_

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

/* Set a certain bit in any register */
#define SET_BIT(REG,BIT) 		(REG|=(1<<BIT))

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT) 		(REG&=~(1<<BIT))

/* Check if a specific bit is set in any register and return true if yes */
#define GET_BIT(REG,BIT) 		((REG>>BIT)&1)

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BIT) 	(REG^=(1<<BIT))

/* Rotate right the register value with specific number of rotates */
#define ROTATE_RIGHT(REG,NUM) ( REG=(REG>>NUM) | REG=(REG<<(8-NUM)) )

/* Rotate left the register value with specific number of rotates */
#define ROTATE_LEFT(REG,NUM) ( REG=(REG<<NUM) | REG=(REG>>(8-NUM)) )



#endif /* MACRO_H_ */
