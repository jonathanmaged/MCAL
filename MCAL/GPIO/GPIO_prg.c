/*
 * GPIO_prg.c
 *
 *  Created on: Aug 9, 2023
 *      Author: admin
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "GPIO_prv.h"
#include "GPIO_int.h"

void MGPIO_vInit(GPIO_cfg_t *A_ptr){
	MGPIO_vSetPinMode(A_ptr->port, A_ptr->pin, A_ptr->mode);
	MGPIO_vSetPinOutputType(A_ptr->port, A_ptr->pin, A_ptr->outputType);
	MGPIO_vSetPinOutputSpeed(A_ptr->port, A_ptr->pin, A_ptr->outputSpeed);
	MGPIO_vSetPinInputType(A_ptr->port, A_ptr->pin, A_ptr->inputtype);
	 MGPIO_vSetAlternateFunction(A_ptr->port, A_ptr->pin, A_ptr->altFunc);

}
void MGPIO_vSetPinMode(u8 A_u8PortId,
		u8 A_u8PinId,
		u8 A_u8Mode )
{
	switch(A_u8PortId){
		case GPIO_PORTA:
			GPIOA->MODER &= ~ ((0b11) <<A_u8PinId*2);
			GPIOA->MODER |=   ((A_u8Mode) << A_u8PinId*2);
			break;
		case GPIO_PORTB:
			GPIOB->MODER &= ~ ((0b11)<<A_u8PinId*2);
			GPIOB->MODER |=   ((A_u8Mode) << A_u8PinId*2);
			break;
		case GPIO_PORTC:
			GPIOC->MODER &= ~ ((0b11)<<A_u8PinId*2);
			GPIOC->MODER |=   ((A_u8Mode) << A_u8PinId*2);
			break;
	}
}
void MGPIO_vSetPinOutputType(u8 A_u8PortId,
			u8 A_u8PinId,
			u8 A_u8OutputType)
{
	if(A_u8OutputType == 1){
		switch(A_u8PortId){
			case GPIO_PORTA:
				GPIOA->OTYPER |= (1<<A_u8PinId);
				break;
			case GPIO_PORTB:
				GPIOB->OTYPER |= (1<<A_u8PinId);
				break;
			case GPIO_PORTC:
				GPIOC->OTYPER |= (1<<A_u8PinId);
				break;
		}
	}else{
		switch(A_u8PortId){
			case GPIO_PORTA:
				GPIOA->OTYPER &= ~(1<<A_u8PinId);
				break;
			case GPIO_PORTB:
				GPIOB->OTYPER &= ~(1<<A_u8PinId);
				break;
			case GPIO_PORTC:
				GPIOC->OTYPER &= ~(1<<A_u8PinId);
				break;
		}
	}
}

void MGPIO_vSetPinOutputSpeed(u8 A_u8PortId,
			u8 A_u8PinId,
			u8 A_u8speed)
{
	switch(A_u8PortId){
		case GPIO_PORTA:
			GPIOA->OSPEEDR &= ~ ((0b11)<<A_u8PinId*2);
			GPIOA->OSPEEDR |=   ((A_u8speed) << A_u8PinId*2);
		break;
		case GPIO_PORTB:
			GPIOB->OSPEEDR &= ~ ((0b11)<<A_u8PinId*2);
			GPIOB->OSPEEDR |=   ((A_u8speed) << A_u8PinId*2);
		break;
		case GPIO_PORTC:
			GPIOC->OSPEEDR &= ~ ((0b11)<<A_u8PinId*2);
			GPIOC->OSPEEDR |=   ((A_u8speed) << A_u8PinId*2);
		break;
	}
}

void MGPIO_vSetPinInputType(u8 A_u8PortId,
			u8 A_u8PinId,
			u8 A_u8pulltype)
{
	switch(A_u8PortId){
		case GPIO_PORTA:
			GPIOA->PUPDR &= ~ ((0b11)<<A_u8PinId*2);
			GPIOA->PUPDR |=   ((A_u8pulltype) << A_u8PinId*2);
		break;
		case GPIO_PORTB:
			GPIOB->PUPDR &= ~ ((0b11)<<A_u8PinId*2);
			GPIOB->PUPDR |=   ((A_u8pulltype) << A_u8PinId*2);
		break;
		case GPIO_PORTC:
			GPIOC->PUPDR &= ~ ((0b11)<<A_u8PinId*2);
			GPIOC->PUPDR |=   ((A_u8pulltype) << A_u8PinId*2);
		break;
	}
}

u8 MGPIO_u8GetPinVal(u8 A_u8PortId,
			u8 A_u8PinId)
{
	u8 return_val=2 ;
	switch(A_u8PortId){
		case GPIO_PORTA:
			return_val=GET_BIT(GPIOA->IDR,A_u8PinId);
			break;
		case GPIO_PORTB:
			return_val=GET_BIT(GPIOA->IDR,A_u8PinId);
			break;
		case GPIO_PORTC:
			return_val=GET_BIT(GPIOA->IDR,A_u8PinId);
			break;
	}
	return return_val ;
}

void MGPIO_vSetPinVal(u8 A_u8PortId,
			u8 A_u8PinId,
			u8 A_u8pinval)
{
	if(A_u8pinval == 1){
			switch(A_u8PortId){
				case GPIO_PORTA:
					SET_BIT(GPIOA->ODR,A_u8PinId);
					break;
				case GPIO_PORTB:
					SET_BIT(GPIOB->ODR,A_u8PinId);
					break;
				case GPIO_PORTC:
					SET_BIT(GPIOC->ODR,A_u8PinId);
					break;
			}
	}else{
			switch(A_u8PortId){
				case GPIO_PORTA:
					CLEAR_BIT(GPIOC->ODR,A_u8PinId);
					break;
				case GPIO_PORTB:
					CLEAR_BIT(GPIOC->ODR,A_u8PinId);
					break;
				case GPIO_PORTC:
					CLEAR_BIT(GPIOC->ODR,A_u8PinId);
					break;
			}
	}
}
void MGPIO_vSetPinValfast(u8 A_u8PortId,
			u8 A_u8PinId,
			u8 A_u8pinval)
{
	if( A_u8pinval == 1){
		switch(A_u8PortId){
			case GPIO_PORTA:
				SET_BIT(GPIOA->BSRR,A_u8PinId);
				break;
			case GPIO_PORTB:
				SET_BIT(GPIOB->BSRR,A_u8PinId);
				break;
			case GPIO_PORTC:
				SET_BIT(GPIOC->BSRR,A_u8PinId);
				break;
		}
	}else{
		switch(A_u8PortId){
			case GPIO_PORTA:
				SET_BIT(GPIOA->BSRR,A_u8PinId+16);
				break;
			case GPIO_PORTB:
				SET_BIT(GPIOB->BSRR,A_u8PinId+16);
				break;
			case GPIO_PORTC:
				SET_BIT(GPIOC->BSRR,A_u8PinId+16);
				break;
		}
	}

}

void MGPIO_vSetAlternateFunction(u8 A_u8PortId,
			u8 A_u8PinId,
			u8 A_u8AltFun){
	if(A_u8PinId<8){
		switch(A_u8PortId){
		case GPIO_PORTA:
			GPIOA->AFRL &= ~ ((0b1111)<<A_u8PinId*4);
			GPIOA->AFRL |=   ((A_u8AltFun) << A_u8PinId*4);
			break;
		case GPIO_PORTB:
			GPIOB->AFRL &= ~ ((0b1111)<<A_u8PinId*4);
			GPIOB->AFRL |=   ((A_u8AltFun) << A_u8PinId*4);
			break;
		case GPIO_PORTC:
			GPIOC->AFRL &= ~ ((0b1111)<<A_u8PinId*4);
			GPIOC->AFRL |=   ((A_u8AltFun) << A_u8PinId*4);
			break;
		}
	}else if(A_u8PinId<16){
		switch(A_u8PortId){
		case GPIO_PORTA:
			GPIOA->AFRH &= ~ ((0b1111)<<(A_u8PinId%8)*4);
			GPIOA->AFRH |=   ((A_u8AltFun) << (A_u8PinId%8)*4);
			break;
		case GPIO_PORTB:
			GPIOB->AFRH &= ~ ((0b1111)<<(A_u8PinId%8)*4);
			GPIOB->AFRH |=   ((A_u8AltFun) << (A_u8PinId%8)*4);
			break;
		case GPIO_PORTC:
			GPIOC->AFRH &= ~ ((0b1111)<<(A_u8PinId%8)*4);
			GPIOC->AFRH |=   ((A_u8AltFun) << (A_u8PinId%8)*4);
			break;
		}
	}
}




