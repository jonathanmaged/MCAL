/*
 * NVIC_prg.c
 *
 *  Created on: Aug 13, 2023
 *      Author: john
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "NVIC_prv.h"
#include "NVIC_int.h"



void MNVIC_VEnableInteruptPeripheral(u8 A_u8IntId){
	if(A_u8IntId<85){
		NVIC->ISER[A_u8IntId/32]= 1<<( A_u8IntId%32);
	}
};

void MNVIC_VDisableInteruptPeripheral(u8 A_u8IntId){
	NVIC->ICER[A_u8IntId/32]= 1<<( A_u8IntId%32);
};

/*Test SW Interupt*/
void MNVIC_VSetPending(u8 A_u8IntId){
	NVIC->ISPR[A_u8IntId/32]= 1<<( A_u8IntId%32);
};


void MNVIC_VClearPending(u8 A_u8IntId){
	NVIC->ICPR[A_u8IntId/32]= 1<<( A_u8IntId%32);
};

//to check
u8 MNVIC_VGetActive(u8 A_u8IntId){
	return GET_BIT(NVIC->IABR[A_u8IntId/32], A_u8IntId%32);
};


void MNVIC_VSetPriorityCfg(u8 A_u8Group){

	u32 L_u32GroupConf =password |(A_u8Group<<8);
	SCB->AIRCR =L_u32GroupConf;
};
void MNVIC_VSetPriority(s8 A_s8IntId,u8 A_u8GroupPriority,u8 A_u8SubPriority){
	u32 L_u32Group = (SCB->AIRCR & 0X00007000)>>8 ;

	u8 L_u8priority = (A_u8SubPriority | (A_u8GroupPriority<<(L_u32Group-3)));

	if(A_s8IntId>=0)
	{
		NVIC->IPR[A_s8IntId] = L_u8priority<<4 ;
	}else{
		if (A_s8IntId     == NVIC_MEMORY_FAULT     ||
				A_s8IntId == NVIC_BUS_FAULT     ||
				A_s8IntId == NVIC_USAGE_FAULT
		)
		{
			A_s8IntId+=6;
			SCB->SHPR1 &= ~ (0b1111<<((A_s8IntId)*8+4));
			SCB->SHPR1 |=   (L_u8priority<<((A_s8IntId)*8+4));
		}else if(A_s8IntId == NVIC_SV_CALL)
		{
			A_s8IntId+=6;
			SCB->SHPR2 &= ~ (0b1111<<((A_s8IntId)*8+4));
			SCB->SHPR2 |=   (L_u8priority<<((A_s8IntId)*8+4));
		}else if(A_s8IntId == NVIC_PEND_SV || A_s8IntId == NVIC_SYSTICK)
		{
			A_s8IntId+=4;
			SCB->SHPR3 &= ~ (0b1111<<((A_s8IntId)*8+4));
			SCB->SHPR3 |=   (L_u8priority<<((A_s8IntId)*8+4));
		}
	}
};

