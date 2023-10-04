/*
 * GPIO_int.h
 *
 *  Created on: Aug 10, 2023
 *      Author: john
 */

#ifndef MCAL_GPIO_INT_H_
#define MCAL_GPIO_INT_H_

#include "../../LIB/STD_TYPES.h"

// PORT DEFINE
//////////////////////////////////////////
#define GPIO_PORTA 1
#define GPIO_PORTB 2
#define GPIO_PORTC 3

//PIN DEFINE
//////////////////////////////////////////
#define GPIO_PIN0    0
#define GPIO_PIN1    1
#define GPIO_PIN2    2
#define GPIO_PIN3    3
#define GPIO_PIN4    4
#define GPIO_PIN5    5
#define GPIO_PIN6    6
#define GPIO_PIN7    7
#define GPIO_PIN8    8
#define GPIO_PIN9    9
#define GPIO_PIN10   10
#define GPIO_PIN11   11
#define GPIO_PIN12   12
#define GPIO_PIN13   13
#define GPIO_PIN14   14
#define GPIO_PIN15   15

/*MODES*/
#define GPIO_MODE_INPUT    0b00
#define GPIO_MODE_OUTPUT   0b01
#define GPIO_MODE_ALTFUN   0b10
#define GPIO_MODE_ANALOG   0b11

/*OUT type*/
#define GPIO_OUTTYPE_OPENDRAIN      1
#define GPIO_OUTPUTTYPE_PUSHPULL    0

/*OUT SPEED*/
#define GPIO_OUTSPEED_LOW    0b00
#define GPIO_OUTSPEED_MEDIUM 0b01

/*INPUT TYPE*/
#define GPIO_INPUTTYPE_NPUPD   0b00
#define GPIO_INPUTTYPE_PU      0b01
#define GPIO_INPUTTYPE_PD      0b10

#define GPIO_HIGH    1
#define GPIO_LOW     0

enum ALTERNATE_FUNCTION {
		GPIO_AF0,
		GPIO_AF1,
		GPIO_AF2,
		GPIO_AF3,
		GPIO_AF4,
		GPIO_AF5,
		GPIO_AF6,
		GPIO_AF7,
		GPIO_AF8,
		GPIO_AF9,
		GPIO_AF10,
		GPIO_AF11,
		GPIO_AF12,
		GPIO_AF13,
		GPIO_AF14,
		GPIO_AF15,
};


typedef struct{
	u8 mode;
	u8 outputType;
	u8 outputSpeed;
	u8 port;
	u8 pin;
	u8 inputtype;
	u8 altFunc;
}GPIO_cfg_t;

void MGPIO_vInit(GPIO_cfg_t *A_ptr);

void MGPIO_vSetPinMode(u8 A_u8PortId,
			u8 A_u8PinId,
			u8 A_u8mode);

void MGPIO_vSetPinOutputType(u8 A_u8PortId,
			u8 A_u8PinId,
			u8 A_u8OutputType);

void MGPIO_vSetPinOutputSpeed(u8 A_u8PortId,
			u8 A_u8PinId,
			u8 A_u8speed);

void MGPIO_vSetPinInputType(u8 A_u8PortId,
			u8 A_u8PinId,
			u8 A_u8pulltype);

u8   MGPIO_u8GetPinVal(u8 A_u8PortId,
			u8 A_u8PinId);

void MGPIO_vSetPinVal(u8 A_u8PortId,
			u8 A_u8PinId,
			u8 A_u8pinval);

void MGPIO_vSetPinValfast(u8 A_u8PortId,
			u8 A_u8PinId,
			u8 A_u8pinval);

void  MGPIO_vSetAlternateFunction(u8 A_u8PortId,
			u8 A_u8PinId,
			u8 A_u8AltFun);

#endif /* MCAL_GPIO_INT_H_ */
