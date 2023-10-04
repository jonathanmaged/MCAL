/*
 * EXTI_prg.c
 *
 *  Created on: Aug 14, 2023
 *      Author: john
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "EXTI_prv.h"
#include "EXTI_int.h"

void(*CALLBACK[16])(void)={0};
void MEXTI_vEnableLine(u8 A_u8Line,u8 A_u8PortId,u8 A_u8Trigger){
	MEXTI_vInteruptcfg(A_u8Line, A_u8PortId);
	if(A_u8Line<16){
		MEXTI_vSetTrigger(A_u8Line, A_u8Trigger);
		SET_BIT(EXTI->IMR ,A_u8Line);
	}
};
void MEXTI_vDisableLine(u8 A_u8Line){
	if(A_u8Line<16){
		CLEAR_BIT(EXTI->IMR,A_u8Line);
		CLEAR_BIT(EXTI->FTSR,A_u8Line);
		CLEAR_BIT(EXTI->RTSR,A_u8Line);
	}

};

void MEXTI_vSetTrigger(u8 A_u8Line,u8 A_u8Trigger){
	switch(A_u8Trigger){
	case Rising_Falling:
		SET_BIT(EXTI->RTSR ,A_u8Line);
		SET_BIT(EXTI->FTSR ,A_u8Line);
	break;
	case Rising_Edge:
		SET_BIT(EXTI->RTSR ,A_u8Line);
		CLEAR_BIT(EXTI->FTSR ,A_u8Line);

	break;
	case Falling_Edge:
		SET_BIT(EXTI->FTSR ,A_u8Line);
		CLEAR_BIT(EXTI->RTSR ,A_u8Line);
	break;
	}
};

void MEXTI_vSoftwareTrigger(u8 A_u8Line){
	SET_BIT(EXTI->SWIER,A_u8Line);
};
void MEXTI_vClearFlag(u8 A_u8Line){
	SET_BIT(EXTI->PR,A_u8Line);
};
void MEXTI_vInteruptcfg(u8 A_u8Line,u8 A_u8PortId){
	if(A_u8Line<=3){
		SYSCFG->EXTICR1 &= ~ ((0b1111)  << (A_u8Line%4)*4);
		SYSCFG->EXTICR1 |=   (A_u8PortId<< (A_u8Line%4)*4);
	}else if(A_u8Line<=7){
		SYSCFG->EXTICR2 &= ~ ((0b1111)  << (A_u8Line%4)*4);
		SYSCFG->EXTICR2 |=   (A_u8PortId<< (A_u8Line%4)*4);
	}else if(A_u8Line<=11){
		SYSCFG->EXTICR3 &= ~ ((0b1111)  << (A_u8Line%4)*4);
		SYSCFG->EXTICR3 |=   (A_u8PortId<< (A_u8Line%4)*4);
	}else if(A_u8Line<=15){
		SYSCFG->EXTICR4 &= ~ ((0b1111)  << (A_u8Line%4)*4);
		SYSCFG->EXTICR4 |=   (A_u8PortId<< (A_u8Line%4)*4);
	}

};
void MEXTI_vSetCallBack(u8 A_u8Line,void(*ptr)(void)){
	switch(A_u8Line){
	case EXTI_LINE0:
		CALLBACK[EXTI_LINE0]=ptr ;
	break;
	}
	switch(A_u8Line){
	case EXTI_LINE1:
		CALLBACK[EXTI_LINE1]=ptr ;
	break;
	}
};
void EXTI0_IRQHandler(void){
	MEXTI_vClearFlag(EXTI_LINE0);
	if(CALLBACK[EXTI_LINE0]!=0)
		CALLBACK[EXTI_LINE0]();

};
void EXTI1_IRQHandler(void){
	MEXTI_vClearFlag(EXTI_LINE1);
	if(CALLBACK[EXTI_LINE1]!=0)
		CALLBACK[EXTI_LINE1]();

};
