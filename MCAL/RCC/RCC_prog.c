/*
 * RCC_prog.c
 *
 *  Created on: Aug 12, 2023
 *      Author: john
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "RCC_int.h"
#include "RCC_cfg.h"
#include "RCC_priv.h"



void MRCC_vInit(void){
#if  RCC_HSE_ENABLE==ENABLE
	SET_BIT(RCC->CR,HSE_ON);
	CLEAR_BIT(RCC->CR,HSE_BYP);
	CLEAR_BIT(RCC->CR,CSS_ON);
	RCC->CFGR &= ~ 0b11 ;
	RCC->CFGR |=   0b01	;

#elif RCC_HSI_ENABLE==ENABLE
	SET_BIT(RCC->CR,HSI_ON);
	RCC->CFGR &= ~ 0b11 ;

#else
	SET_BIT(RCC->CR,PLL_ON);
	RCC->CFGR &= ~ 0b11 ;
	RCC->CFGR |=   0b10	;
#endif
	RCC->CFGR &= ~ ((0b1111)<<HPRE_BITS);
	RCC->CFGR |=   ((AHBPRESCALAR)<<HPRE_BITS);

};
void MRCC_vEnable(u8 A_u8BusName , u8 A_u8PeripheralName){
	switch(A_u8BusName){
	case RCC_AHB1:
		SET_BIT(RCC-> AHB1ENR,A_u8PeripheralName) ;
	break;
	case RCC_AHB2:
		SET_BIT(RCC-> AHB2ENR,A_u8PeripheralName) ;
	break;
	case RCC_APB1:
		SET_BIT(RCC-> APB1ENR,A_u8PeripheralName) ;
	break;
	case RCC_APB2:
		SET_BIT(RCC-> APB2ENR,A_u8PeripheralName) ;
	break;
	}
};
void MRCC_vDisable(u8 A_u8BusName , u8 A_u8PeripheralName){
	switch(A_u8BusName){
	case RCC_AHB1:
		CLEAR_BIT(RCC-> AHB1ENR,A_u8PeripheralName) ;
	break;
	case RCC_AHB2:
		CLEAR_BIT(RCC-> AHB2ENR,A_u8PeripheralName) ;
	break;
	case RCC_APB1:
		CLEAR_BIT(RCC-> APB1ENR,A_u8PeripheralName) ;
	break;
	case RCC_APB2:
		CLEAR_BIT(RCC-> APB2ENR,A_u8PeripheralName) ;
	break;
	}
};
