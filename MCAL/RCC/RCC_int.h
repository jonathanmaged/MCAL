/*
 * RCC_int.h
 *
 *  Created on: Aug 12, 2023
 *      Author: john
 */

#ifndef MCAL_RCC_RCC_INT_H_
#define MCAL_RCC_RCC_INT_H_

#include "../../LIB/STD_TYPES.h"

#define RCC_AHB1 1
#define RCC_AHB2 2
#define RCC_APB1 3
#define RCC_APB2 4

enum{
	RCC_GPIOAEN,
	RCC_GPIOBEN,
	RCC_GPIOCEN,
	RCC_GPIODEN,
	RCC_GPIOEEN,
};
#define RCC_GPIOHEN 7
#define RCC_USART2EN 17
#define RCC_USART1EN 4
#define RCC_SYSCFGEN 14

//INIT FUCTION ENABLE THE TYPE OF CLK SOURCE USED
void MRCC_vInit(void);
//ENABLE FUNCTION ENABLE THE PERIPHERAL YOU WANT TO USE
void MRCC_vEnable(u8 A_u8BusName , u8 A_u8PeripheralName);
//DISABLE FUNCTION DISABLE THE PERIPHERAL YOU WANT TO USE
void MRCC_vDisable(u8 A_u8BusName , u8 A_u8PeripheralName);


#endif /* MCAL_RCC_RCC_INT_H_ */
